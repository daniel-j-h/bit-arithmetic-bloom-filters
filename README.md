# Bit Arithmetic Example: Bloom Filters

Bit arithmetic example for my 2013/2014 osdev tutorial. Students were given an introduction into Bloom filters and the code skeleton. Assignment was to think about bitwise operations.

Note: driver.c and values.c were not part of the skeleton. These are for using the Low-Level Bounded Model Checker (LLBMC) in order to automatically find collisions. The driver also contains a all\_ones function for LLBMC to find an input that renders the Bloom Filter useless, by setting all bits to ones.

## Getting started

    make

## Usage

    ./bloom

## License

Copyright (C) 2014 Daniel J. H.

Distributed under the MIT License.
