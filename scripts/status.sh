#!/bin/sh

function get_volume {
	VALUE=$(pactl get-sink-volume @DEFAULT_SINK@ | awk '/^Volume/ { print substr($5, 1, length($5)-1) }')

	if [ "$(pactl get-sink-mute @DEFAULT_SINK@)" = "Mute: yes" ]; then
		ICON="婢"
	else
		if [ $VALUE -lt 30 ]; then
			ICON="奄"
		else
			if [ $VALUE -lt 60 ]; then
				ICON="奔"
			else
				ICON="墳"
			fi
		fi
	fi

	echo "$ICON $VALUE%"
}

function get_brightness {
	echo "盛 $(printf "%.0f\n" $(xbacklight))%"
}

function get_battery {
	CAPACITY=$(cat /sys/class/power_supply/BAT0/capacity)
	STATUS=$(cat /sys/class/power_supply/BAT0/status)

	if [ $STATUS = "Charging" ]; then
		ICON=""
	else
		if [ $CAPACITY == 100 ]; then
			ICON=""
		else if [ $CAPACITY -lt 10 ]; then
			ICON=""
		else
			ICON=$(printf "\u$(printf "%x" $((0xf578 + $CAPACITY / 10)))")
		fi fi
	fi

	echo "$ICON $CAPACITY%"
}

function get_mem {
  echo "﬙ $(free -h | awk '/^Mem:/ { print $3 "/" $2 }')"
}

function hard_set {
  echo "  $(get_brightness)   $(get_volume)   $(get_battery)   $(get_mem)   " > /tmp/dwmstatus
	soft_set
}

function soft_set {
	xsetroot -name "$(cat /tmp/dwmstatus)$(date +' %X    %a %B %d, %Y') "
}

while true; do
	hard_set
	[ "$1" != "true" ] || break
	sleep 1

	for i in {1..9}
	do
		soft_set
		sleep 1
	done
done

