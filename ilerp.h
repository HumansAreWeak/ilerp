/**
 * This file was created by HumansAreWeak (https://github.com/HumansAreWeak)
 * Standalone and header only library.
 *
 * @author HumansAreWeak
 * @date 02.04.2023
 */
#ifndef MC_LERP_H_
#define MC_LERP_H_

#include <stdint.h>

/**
 * Base macro definition of a linear interpolation that is only using addition, subtraction and a bit shift operation.
 * It is pretty quick and should run nearly on any given platform natively without much overhead. Use this if you are
 * okay with losing 127 extra points in the interpolation, but saving a division operation.
 * @param src Number to start the interpolation from
 * @param dest The number to where interpolate to
 * @param delta Change in time as integer. Must range from 0 to half of types given MAX SIZE
 * @param type Used type for the interpolation
 */
#define _ilerps_base(src, dest, delta, type) (type)((src * (((1LL << ((sizeof(type) * 8) - 1))) - delta) + dest * delta) >> 7)

/**
 * Base macro definition of a linear interpolation that is only using addition, subtraction and a division operation.
 * It is pretty quick and should run mostly on any given platform natively. Use this if you need the extra precision
 * for your interpolation at cost of a division operator.
 * @param src Number to start the interpolation from
 * @param dest The number to where interpolate to
 * @param delta Change in time as integer. Must range from 0 to given type MAX SIZE
 * @param type Used type for the interpolation
 */
#define _ilerpd_base(src, dest, delta, type) (type)((src * (((type) (((1LL << ((sizeof(type) * 8) - 1)) * 2) - 1)) - delta) + dest * delta) / 255)

/**
 * Integer-based linear interpolation for signed integer. It does interpolation in a small scale for a really small cost.
 * @param src First value, type must be int8_t
 * @param dest Second value, type must be int8_t
 * @param delta Change in time, int8_t between 0 and 127
 */
#define _ilerps_i8(src, dest, delta) _ilerps_base(src, dest, delta, int8_t)

/**
 * Integer-based linear interpolation for signed integer. It does interpolation in a small scale for a really small cost.
 * @param src First value, type must be uint8_t
 * @param dest Second value, type must be uint8_t
 * @param delta Change in time, uint8_t between 0 and 127
 */
#define _ilerps_u8(src, dest, delta) _ilerps_base(src, dest, delta, uint8_t)


/**
 * Integer-based linear interpolation for signed integer. It does interpolation in a small scale for a really small cost.
 * @param src First value, type must be uint8_t
 * @param dest Second value, type must be uint8_t
 * @param delta Change in time, uint8_t between 0 and 255
 */
#define _ilerpd_u8(src, dest, delta) _ilerpd_base(src, dest, delta, uint8_t)

#endif
