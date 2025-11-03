#!/bin/bash

while read ARXIV_CODE
do
 TITLE=$(
 curl -s "https://www.arxiv.org/abs/$ARXIV_CODE" | 
       grep '<meta property="og:title"' |
       sed 's/.*content="//' | sed 's#" />##'
   )
 sleep 0.2
 echo '---'
 echo "arXiv: $ARXIV_CODE"
 echo "title: $TITLE"
done

