#!/bin/sh

THEMES=($(echo $(ls ~/.config/dotfiles/dwm-flexipatch/themes -l | grep .jpg | awk '{ print $9 }') | sed 's/.jpg//g'))
THEME_INDEX=$(expr $RANDOM % ${#THEMES[@]})
THEME=${THEMES[$THEME_INDEX]}

# set theme
echo $THEME_INDEX > /tmp/theme
feh --bg-fill ~/.config/dotfiles/dwm-flexipatch/themes/$THEME.jpg
xrdb ~/.config/dotfiles/dwm-flexipatch/themes/$THEME.Xresources

# start de
picom --config ~/.config/dotfiles/dwm-flexipatch/picom.conf &
~/.config/dotfiles/dwm-flexipatch/scripts/status.sh &
exec dwm

