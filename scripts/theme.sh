#!/bin/sh

THEMES=($(echo $(ls ~/.config/dotfiles/dwm/themes/ -l | grep .jpg | awk '{ print $9 }') | sed 's/.jpg//g'))
THEME_INDEX=$(expr $(expr $(< /tmp/theme) + 1) % ${#THEMES[@]})
THEME=${THEMES[$THEME_INDEX]}

echo $THEME_INDEX > /tmp/theme
feh --bg-fill ~/.config/dotfiles/dwm/themes/$THEME.jpg
xrdb ~/.config/dotfiles/dwm/themes/$THEME.Xresources

