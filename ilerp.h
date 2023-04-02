#ifndef MC_LERP_H_
#define MC_LERP_H_

#include <stdint.h>

/**
 * Base macro definition of a linear interpolation that is only using addition, subtraction and a bit shift operation.
 * It is pretty quick and should run nearly on any given platform natively without much overhead.
 * @param src Number to start the interpolation from
 * @param dest The number to where interpolate to
 * @param delta Change in time as integer. Must range from 0 to half of types given max size
 * @param type Used type for the interpolation
 */
#define _ilerps_base(src, dest, delta, type) (type)((src * (((1LL << ((sizeof(type) * 8) - 1))) - delta) + dest * delta) >> 7)
#define _ilerpd_base(src, dest, delta, type) (type)((src * (((type) (1LL << ((sizeof(type) * 8) - 1))) - delta) + dest * delta) / 255)

#define _ilerps_u8(src, dest, delta) _ilerps_base(src, dest, delta, uint8_t)

// (src * (128 - i) + dest * i) << 1

#endif