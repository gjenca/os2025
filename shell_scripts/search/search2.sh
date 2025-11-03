#!/bin/bash

SEARCH_STRING=""
while [ $# != 0 ]
do
   SEARCH_STRING="$SEARCH_STRING+$1"
   shift
done
SEARCH_STRING=$(echo $SEARCH_STRING | sed 's/^+//')
echo $SEARCH_STRING
