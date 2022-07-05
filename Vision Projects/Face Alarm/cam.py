import cv2 as cv
from cvzone.FaceDetectionModule import FaceDetector
from cvzone.SerialModule import SerialObject

cap = cv.VideoCapture(0)

detector = FaceDetector()
arduino = SerialObject()

while cap.isOpened():
    ret, img = cap.read()

    if not ret:
        break

    img, bboxes = detector.findFaces(img)

    if bboxes:
        arduino.sendData([1])
    else:
        arduino.sendData([0])

    cv.imshow("Image", img)
    cv.waitKey(1)

arduino.sendData([0])
