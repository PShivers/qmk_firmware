# Keyball series

This directory includes source code of Keyball keyboard series:

| Name          | Description
|---------------|-------------------------------------------------------------
|[Keyball46](./keyball46)|A split keyboard with 46 vertically staggered keys and 34mm track ball.
|[Keyball61](./keyball61)|A split keyboard with 61 vertically staggered keys and 34mm track ball.
|[Keyball39](./keyball39)|A split keyboard with 39 vertically staggered keys and 34mm track ball.
|[ONE47](./one47)|A keyboard with 47 vertically keys and 34mm trackball. It will support BLE Micro Pro.
|[Keyball44](./keyball44)|A split keyboard with 44 vertically staggered keys and 34mm track ball.

* Keyboard Designer: [@Yowkees](https://twitter.com/Yowkees)  
* Hardware Supported: ProMicro like footprint
* Hardware Availability: See [Where to Buy](../../../README.md#where-to-buy)

See each directories for each keyboards in a table above.

## How to build
as i have a seapicro(promicro clone) I needed the compile to spit out a .uf2 instead of .hex
I ended up having to use the keymap and config from the idank repo
this is the command that worked for me after much trouble. 
make keyball/keyball44:pshivers:flash -j8
