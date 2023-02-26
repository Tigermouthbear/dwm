#!/bin/sh

THEMES=("berserk" "cyborg" "edgerunners" "evangelion" "ouro-kronii-cyberpunk" "windowsjp")
THEME=${THEMES[$(($RANDOM % ${#THEMES[@]}))]}

feh --bg-fill ~/.config/dotfiles/dwm/themes/$THEME.jpg
xrdb ~/.config/dotfiles/dwm/themes/$THEME.Xresources

picom --config ~/.config/dotfiles/dwm/picom.conf &

~/.config/dotfiles/dwm/scripts/status.sh &
exec dwm

