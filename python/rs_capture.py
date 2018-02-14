## License: Apache 2.0. See LICENSE file in root directory.
## Copyright(c) 2015-2017 Intel Corporation. All Rights Reserved.

###############################################
##      Open CV and Numpy integration        ##
###############################################

import os
import pyrealsense2 as rs
import numpy as np
import cv2
os.makedirs('B:/captures', exist_ok=True)
os.chdir('B:/captures/')
# Configure depth and color streams
pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)

# Start streaming
profile = pipeline.start(config)

depth_sensor = profile.get_device().first_depth_sensor()
depth_scale = depth_sensor.get_depth_scale()

depth_stream = profile.get_stream(rs.stream.depth)
color_stream = profile.get_stream(rs.stream.color)

depth_stream.as_video_stream_profile().get_intrinsics()
depth_to_color = depth_stream.get_extrinsics_to(color_stream)


align_to = rs.stream.color
align = rs.align(align_to)

pc = rs.pointcloud()
points = rs.points()

# Open disk
# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'MJPG')
color_out = cv2.VideoWriter('colour_output.avi',fourcc, 30, (640,480))

os.makedirs('depth', exist_ok=True)
os.makedirs('pc', exist_ok=True)

frame_idx = 0
try:
    while True:

        # Wait for a coherent pair of frames: depth and color
        frames = pipeline.wait_for_frames()
        aligned_frames = align.proccess(frames)

        depth_frame = aligned_frames.get_depth_frame()
        color_frame = aligned_frames.get_color_frame()
        if not depth_frame or not color_frame:
            continue

        pc.map_to(color_frame)
        points = pc.calculate(depth_frame)
        points.export_to_ply('pc/pc_%i.ply' % frame_idx, color_frame)
        points.get_data()


        # Convert images to numpy arrays
        depth_image = np.asanyarray(depth_frame.get_data())
        color_image = np.asanyarray(color_frame.get_data())

        color_out.write(color_image)
       #depth_image.astype('uint16').tofile('depth/depth_frame_%i.bin' % frame_idx)


        # Apply colormap on frames image (image must be converted to 8-bit per pixel first)
        depth_colormap = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.03), cv2.COLORMAP_JET)

        # Stack both images horizontally
        images = np.hstack((color_image, depth_colormap))

        # Show images
        cv2.namedWindow('RealSense', cv2.WINDOW_AUTOSIZE)
        cv2.imshow('RealSense', images)
        cv2.waitKey(1)
        frame_idx += 1

        if cv2.getWindowProperty('RealSense', 0) == -1:
            color_out.release()
            break
finally:

    # Stop streaming
    pipeline.stop()