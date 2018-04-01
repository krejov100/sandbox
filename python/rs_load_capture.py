
import numpy as np
import cv2
import os
import sys
from vispy import scene, app
import pyrealsense2 as rs
pc = rs.pointcloud()

os.chdir('captures/capture1')

cap = cv2.VideoCapture('colour_output.avi')

canvas = scene.SceneCanvas(keys='interactive', bgcolor='white')
canvas.show()
view = canvas.central_widget.add_view()
view.camera = scene.TurntableCamera()
view.camera.set_range((-1, 1), (-1, 1), (-1, 1))

markers = scene.visuals.Markers(parent=view.scene)
pos = np.random.normal(size=(100000, 3), scale=0.2)
markers.set_data(pos, face_color=(0, 0, 0, 1), size=5)

frame_idx  = 0


align_to = rs.stream.color
align = rs.align(align_to)

def update(ev):
    global frame_idx

    ret, frame = cap.read()
    depth_image = np.fromfile('depth/depth_frame_%i.bin' % frame_idx, dtype='uint16').reshape(480, 640)

    depth_colormap = cv2.applyColorMap(cv2.convertScaleAbs(depth_image, alpha=0.03), cv2.COLORMAP_JET)



    pos = np.random.normal(size=(100000, 3), scale=0.2)
    #markers.set_data(pos, face_color=(0, 0, 0, 1), size=5)

    cv2.imshow('frame', depth_colormap)
    frame_idx += 1


timer = app.Timer()
timer.connect(update)
timer.start(0)
# Add a 3D axis to keep us oriented
scene.visuals.XYZAxis(parent=view.scene)

if __name__ == '__main__' and sys.flags.interactive == 0:
    canvas.show()
    app.run()




