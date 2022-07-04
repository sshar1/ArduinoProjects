import cv2 as cv
import numpy as np

from cvzone.SerialModule import SerialObject

arduino = SerialObject()

while True:
    img = cv.imread("Imgs/Potentiometer.jpg")

    data = arduino.getData()

    try:

        val = data[0]
        print(val)
        cv.putText(img, val.zfill(4), (260, 280), cv.FONT_HERSHEY_PLAIN, 3, (255, 255, 255), 3)

        if (val != '0'):
            val = np.interp(int(val), [0, 1023], [-90, 270])

            cv.ellipse(img, (320, 265), (131, 131), 0, -90, val, (255, 180, 0), 25)

    except:
        pass

    cv.imshow("Image", img)
    cv.waitKey(1)

    if cv.waitKey(10)&0xFF== ord('q'):
        break

cv.destroyAllWindows()
