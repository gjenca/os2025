#!/bin/bash

echo "počet argumentov=$#"

echo "arg1=-$1-"
echo "arg2=-$2-"

echo "všetky argumenty=-$@-"

for ARG in "$@"
do
    echo "argument=-$ARG-"
done

echo "shift!"
shift

echo "počet argumentov=$#"

echo "arg1=-$1-"
echo "arg2=-$2-"

echo "všetky argumenty=-$@-"

for ARG in "$@"
do
    echo "argument=-$ARG-"
done

