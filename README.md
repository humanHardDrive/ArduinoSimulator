# ArduinoSimulator
A register level simulation of the ATMega328 and other hardware

## Goals
* A register level simulation of the ATMega328 (Arduino Uno) processor. Register level being between bit level and API level, meaning it
doesn't just simulate Arduino code and isn't a total replication of the processor core. By simulating the registers, the Arduino libraries
can be run as normal and full AVR-C code can also be run. This allows for 3rd party libraries written in either Arduino or AVR-C to be
completely compatible and run without modification.
* A simulation of hardware components outside the Arduino allowing for complex schematics with buttons, LEDs, ICs and other such devices. Because all components are built from the same structure, new components for other hardware can easily be created and added without the need for recompilation.

## Parts
* Arduino Simulator: Exectues the Arduino/AVR-C code
* Hardware Simulator: Manages connections between all of the hardware, passing data to all components, managing states and errors
* GUI: A visual of the schematic
