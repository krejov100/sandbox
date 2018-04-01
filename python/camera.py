import numpy as np
class ImagePoint:
    x = 0
    y = 0


class FocalLength:
    fx = 0
    fy = 0


class PinHoleCamera:
    principlePoint = ImagePoint
    focalLength = FocalLength
    dimensions = ImagePoint


class ViPiCamera:
    camera = PinHoleCamera


class Pose:
    orientation = np.asarray([0, 0, 0, 1])
    position = np.zeros(3)
    scale = np.ones(3)


class MultiCameraArray:
    cameras = []
    globalPoses = []
