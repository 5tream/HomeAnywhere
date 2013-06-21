# !/bin/sh

base=device_car

case $1 in
    start)
        /home/joycar/$base 192.168.1.22 6666 80 /dev/video2 mjpeg jpeg /dev/ttySAC2 &
        ;;

    stop)
        pid=`/bin/pidof $base`
        if [ -n "$pid" ]; then
            kill -9 $pid
        fi
        ;;
esac

exit 0

