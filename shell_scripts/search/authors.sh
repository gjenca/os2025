#!/bin/bash

while read ARXIV_CODE
do
 AUTHORS=$(
 curl -s "https://www.arxiv.org/abs/$ARXIV_CODE" | 
       grep '<div class="authors"'| 
       tr '<' '\n' | 
       grep '^a href=' | 
       sed 's/.*>//' )
  sleep 0.2
  echo $AUTHORS
done

