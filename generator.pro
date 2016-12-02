#-------------------------------------------------
#
# Project created by QtCreator 2016-10-26T10:07:00
#    https://sites.google.com/site/raspberryflightgear/4-qt-and-raspberry
# http://stackoverflow.com/questions/1356328/console-input-with-qt-creator

https://www.dexterindustries.com/GoPiGo/programming/python-programming-for-the-raspberry-pi-gopigo/
https://github.com/DexterInd/GoPiGo
http://forbot.pl/blog/artykuly/programowanie/raspberry-pi-w-robotyce-amatorskiej-3-programowanie-id1274
http://codeandlife.com/2015/03/25/raspberry-pi-2-vs-1-gpio-benchmark/
http://raspberrypihobbyist.blogspot.com/2015/01/gpio-interrupts-using-wiringpi.html


http://tordwessman.blogspot.se/2013/12/adafruit-pca9685-c-servo-controller.html
https://www.raspberrypi.org/forums/viewtopic.php?t=29458&p=333855
https://github.com/TeraHz/PCA9685
#-------------------------------------------------

QT       += core gui network  widgets axcontainer webkitwidgets webkit


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Generator2_v1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    zasoby.qrc \
    zasoby.qrc

DISTFILES += \
    przeszkody1.txt
# install
target.path = $$[QT_INSTALL_EXAMPLES]/activeqt/webbrowser
INSTALLS += target
