#!/bin/sh -x

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

cd "/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src/qt_create"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/usr/local/lib/python2.7/dist-packages:/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src-build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src-build" \
    "/usr/bin/python" \
    "/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src/qt_create/setup.py" \
    build --build-base "/home/zhangjian/qt_environment/qt_programmer/pendant/qt_ros_zhangjian/src-build/qt_create" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/usr/local" --install-scripts="/usr/local/bin"
