#!/bin/bash
for N in $(seq 9)
do
    echo "$N*$N="$(echo "$N*$N" | bc)
done

