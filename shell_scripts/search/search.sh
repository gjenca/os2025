#!/bin/bash

SEARCH_STRING=$(while [ $# != 0 ]
do
   echo $1
   shift
done | paste -s -d+ )

curl -s "https://arxiv.org/search/?query=$SEARCH_STRING&searchtype=all&abstracts=show&order=-announced_date_first&size=50" | grep 'arXiv:' | sed 's/.*arXiv:\([^<]*\)<.*/\1/'

