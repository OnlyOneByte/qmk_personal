# onlyonebyte/alice_72

![onlyonebyte/alice_72](imgur.com image replace me!)

This is a test using up some leftover stuff I have lying around to make an alice style, handwired keyboard with lots of keys.
This keyboard is designed in ergogen, and is designed to be 3d printed and then handwired.

I had a leftover pro micro, as well as leftover 128x32 oled, so its just a learning experience for me to use ergogen and handwiring.

* Keyboard Maintainer: [Angelo Yang](https://github.com/Angelo Yang)
* Hardware Supported: ProMicro
* Hardware Availability: nowhere

Make example for this keyboard (after setting up your build environment):

    make onlyonebyte/alice_72:default

Flashing example for this keyboard:

    make onlyonebyte/alice_72:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
