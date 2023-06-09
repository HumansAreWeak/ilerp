﻿# Integer based Non-Floating Point Interpolation Library

[![Test](https://github.com/HumansAreWeak/ilerp/actions/workflows/test-runner.yml/badge.svg)](https://github.com/HumansAreWeak/ilerp/actions/workflows/test-runner.yml)

**First of all: What does this library do?**

It does exactly what the title says, it can linearly interpolate between two 
given values using only relatively cheap operations and integers. This saves 
on using Floating-Point numbers in cases where it is not appropriate due to 
project limitations and such. 

**Why do we need that library?**

As a reference point (since I could not find anything similar here) for
writing an algorithm that incorporates linear interpolation. It is mostly
intended to be used with microcontrollers (e.g. ATTiny13) with severe hardware
(storage, performance) limitations.

## Usage

Just include the header file ```ilerp.h``` into any of your header/source files and use either the bit-shift version of the algorithm with the macros
* ```_ilerps_i8``` for signed 8-bit integer
* ```_ilerps_u8``` for unsigned 8-bit integer

for the division version use:
* ```_ilerpd_u8``` for unsigned 8-bit integer

All the macros take in a **source** (*from*), **destination** (*to*) and a delta.

## Calculations

Let $n_s$ be the source (aka *from*), $n_d$ the destination (aka *to*), $\delta$ the change in time **as unsigned integer** and $t$ the width of the used type.

Using only bitshift:

$$y=n_s\cdot\left(\frac{t}{2}+1-\delta\right)+\delta\cdot n_d >> 7$$

As you can imagine, for ASM you could theoretically make a shift left once and just look at the HIGH BYTE.

Using division:

$$y=\frac{n_s\cdot(t-\delta)+\delta\cdot n_d}{255}$$

With the bit shift you have the side effect of having only 128 different states available to you instead of 256, effectivly halving it. Nonetheless, you are saving on a division operation. 

## License

Feel free to use it however you desire, you don't have to mention my name anywhere. 

## Contributions

If you manage to catch any mistakes or even further improve the library, then feel free to send a PR.
