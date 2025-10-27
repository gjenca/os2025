#!/bin/bash
if test "$#" = 0
then
    M="2 50"
else
    M="$@"
fi
for N in $(seq $M)
do
    N_2=$(echo "sqrt($N)" | bc)
    JE_NIEJE="je"
    for D in $(seq 2 $N_2)
    do
        ZVYSOK=$(echo "$N%$D" | bc)
        if test "$ZVYSOK" == 0
        then
            JE_NIEJE="nie je"
            break
        fi
    done
    echo "$N $JE_NIEJE prvočíslo"
done

