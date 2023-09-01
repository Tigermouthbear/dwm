#!/bin/sh

THEMES=($(echo $(ls ~/.config/dotfiles/dwm-flexipatch/themes -l | grep .jpg | awk '{ print $9 }') | sed 's/.jpg//g'))
THEME_INDEX=$(expr $(expr $(< ~/.cache/theme) + 1) % ${#THEMES[@]})
THEME=${THEMES[$THEME_INDEX]}

echo $THEME_INDEX > ~/.cache/theme
feh --bg-fill ~/.config/dotfiles/dwm-flexipatch/themes/$THEME.jpg
xrdb ~/.config/dotfiles/dwm-flexipatch/themes/$THEME.Xresources && kill -USR1 $(pidof st)

