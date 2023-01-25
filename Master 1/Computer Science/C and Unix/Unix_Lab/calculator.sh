# !/bin/bash

if [ "$1" == "" ] && [ "$2" == "" ]
then
    echo Please enter operand a:
    read a
    echo Please enter operand b:
    read b 
    r1=`echo $a + $b | bc `
    r2=`echo $a - $b | bc`
    r3=`echo $a \* $b | bc`
    r4=`echo $a / $b | bc`
    echo "sum $a + $b = $r1 "
    echo "diff $a - $b = $r2 "
    echo "mult $a * $b = $r3 "
    echo "div $a / $b = $r4 "
else
    r1=`echo $1 + $2 | bc `
    r2=`echo $1 - $2 | bc`
    r3=`echo $1 \* $2 | bc`
    r4=`echo $1 / $2 | bc`
    echo "sum $1 + $2 = $r1 "
    echo "diff $1 - $2 = $r2 "
    echo "mult $1 * $2 = $r3 "
    echo "div $1 / $2 = $r4 "
fi