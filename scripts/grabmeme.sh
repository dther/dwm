#!/bin/sh
# (c) Rudy Dellomas III

# Does a common operation:
# Grabs a screenshot (interactively),
# saves it to $XDG_PICTURES_HOME/screenshots/,
# and pushes it to `xclip -selection clipboard -t image/png`.
XDG_PICTURES_HOME=$(xdg-user-dir PICTURES)
dir="$XDG_PICTURES_HOME/screenshots" 
[ -d "$dir" ] || mkdir "$dir"
now=$(date +%Y-%m-%d-%H:%M:%S)
name="$now" # can be edited? hmm
fullname="$dir/$name.png"

maim -su | tee "$fullname" | xclip -selection clipboard -t "image/png" &&\
	notify-send -u "low" "grabmeme.sh" "Screenshot clipped + saved to $fullname"

#name=$(printf "%s" "$now" | dmenu -p "image name? ")
#fullname="$dir/$name.png"
#
#if [ "$(xclip -selection clipboard -t TARGETS -o | tail -n1)" = "image/png" ] && \
#		xclip -selection clipboard -o > "$fullname" ; then
#	notify-send -u "low" "grabmeme.sh" "Image saved to $fullname"
#else
#	notify-send -u "critical" "grabmeme.sh:WARNING" "Failed to save $fullname."
#fi

