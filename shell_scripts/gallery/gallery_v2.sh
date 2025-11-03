#!/bin/bash

HEADER='Gallery'
PERCENT=20
while true
do
    # Máme -h a potom neprázdny argument $2
    if [ "$1" = '-h' -a -n "$2" ]
    then
        HEADER="$2"
        shift
        shift
    elif [ "$1" = '-p' -a -n "$2" ]
    then
        PERCENT="$2"
        shift
        shift
    else
        break
    fi
done
cat <<THE_END
<html>
<body>
<h1>$HEADER</h1>

<ul>
THE_END

# ak podadresár min neexistuje, vytvor ho
if [ ! -d mini ]
then
    mkdir mini
fi
for IMGFILE in "$@"
do
    MINIFILE=$(echo "$IMGFILE" | sed 's#\(.*\)jpg$#mini/\1png#')
    magick "$IMGFILE" -resize "$PERCENT%" "$MINIFILE"
    echo '<li>'
    echo '<a href="'"$IMGFILE"'">'
    echo '<img src="'"$MINIFILE"'">'
    echo '</a>'
    echo '</li>'
done
cat <<THE_END
</ul>
</body>
</html>
THE_END


