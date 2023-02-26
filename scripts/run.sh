#!/bin/sh

THEME="edgerunners"

feh --bg-fill ~/.config/dotfiles/dwm/themes/$THEME.jpg
xrdb ~/.config/dotfiles/dwm/themes/$THEME.Xresources

picom --config ~/.config/dotfiles/dwm/picom.conf &

~/.config/dotfiles/dwm/scripts/status.sh &
exec dwm

