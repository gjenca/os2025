#!/bin/bash

cat <<THE_END
<html>
<body>
<h1>Gallery</h1>

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
    magick "$IMGFILE" -resize '20%' "$MINIFILE"
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


