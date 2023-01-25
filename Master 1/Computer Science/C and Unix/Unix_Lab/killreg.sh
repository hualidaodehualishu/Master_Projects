# !/bin/bash
if [ "$1" == "" ] && [ "$2" == "" ] 
then
    echo "Error , at least one argument is required !"
else 
    if [ "`echo $1 |grep ^-`" = "" ] && [ $# -eq 2 ]
    then
        echo "Error, the first argument must start with a hyphen"
    else
        if [ $# -eq 2 ]
        then
            for a in `ps | grep -E $2 |awk '{print $4}'`
            do 
                killall $1 $a 2>/dev/null
            done
        fi;
    fi;
fi;

if [ $# -eq 1 ] 
then
    for b in `ps | grep -E $1 |awk '{print $4}'`
        do 
            killall -TERM $b 2>/dev/null
        done
fi;