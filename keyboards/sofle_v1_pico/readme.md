# Sofle V1 PCB with Pico Keyboard

Sofle Pico is a 60% Raspberry Pi Pico powered split keyboard boasting a 4x6 layout with an aggressive columnar stagger. It has 5 "thumb" keys on either side, support for 2-4 rotary encoders, per-key RGB lighting, 128x64 OLEDs and a tenting puck mount.

- Keyboard Maintainer: [Angelo Yang](https://github.com/OnlyOneByte/qmk_soflev1_pico)
- Hardware Supported: Sofle V1 PCB, Raspberry Pi Pico

This is a hacky project using up leftover parts. I had some Sofle V1 PCBs laying around from several years ago when I first built the original Sofle, and I have Pi Picos from an unrelated project but no Pro Micros laying around. Therefore, the only thing to do was meticulously handwire each Pro Micro pin on the PCB to a Pi Pico, customize a QMK instance, and then modify an existing case to fit a Pi Pico like a giant tumor.


Credits:
- https://github.com/josefadamcik/SofleKeyboard (Sofle V1, original keyboard)
- https://github.com/JellyTitan/Sofle-Pico (Sofle Pico, for the QMK base)
- https://github.com/itsdmd/sofle-v1-modular-case (Sofle V1 3D Printed case, modified)


Remember you have to flash both halves of the keyboard for it to work!

Make example for this keyboard (after setting up your build environment):

    make sofle_pico:default

Flashing example for this keyboard:

    make sofle_pico:default:uf2-split-left
    make sofle_pico:default:uf2-split-right
    
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

- **Bootmagic reset** (works after you have flashed once): Hold down the top far corner key while plugging in the keyboard (`~` left half, `-` right half). This will also clear the EEPROM.
- **Physical reset button**: Hold the `BOOT` button on the Pico and press the `RST` button on the Pico, release the the `RST` button before the `BOOT` button.
- **Keycode in layout**: In the default layout, the `Bootloader` keycode is above home row pinky on the right side's adjust layer.

Once you enter the bootloader, the keyboard will show up as a USB device on your computer, you could drag and drop a `.uf2` firmware file to flash it.

[Keyboard-layout-editor.com](http://www.keyboard-layout-editor.com/#/gists/2fa0527caf2f6e527e4f46787a74a9d2)
