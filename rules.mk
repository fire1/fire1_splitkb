TAP_DANCE_ENABLE = yes # Allow tab dance

# Other dependency are defined in info.json
LTO_ENABLE = yes  # Makes hex file smaller

RGB_DISABLE_WHEN_USB_SUSPENDED=true
#NO_USB_STARTUP_CHECK=true

# Suspend RGB leds
SLEEP_LED_ENABLE=yes
#OPT_DEFS += -DNO_SUSPEND_POWER_DOWN

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = analog_joystick
POINTING_DEVICE_LEFT = no
POINTING_DEVICE_RIGHT = yes
