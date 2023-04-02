/**
 * This file was created by HumansAreWeak (https://github.com/HumansAreWeak)
 *
 * It is part of the ilerp library. The crude "unit tests" of the library are written here.
 *
 * @author HumansAreWeak
 * @date 02.04.2023
 */
#include <assert.h>
#include "ilerp.h"

void test_ilerps_base()
{
    /** --- _ilerps_u8 Tests --- */
    assert(_ilerps_u8(0, 255, 0) == 0);
    assert(_ilerps_u8(0, 255, 64) == 127);
    assert(_ilerps_u8(0, 255, 128) == 255);

    assert(_ilerps_u8(0, 42, 0) == 0);
    assert(_ilerps_u8(0, 42, 64) == 21);
    assert(_ilerps_u8(0, 42, 128) == 42);

    for(uint32_t i = 0; i <= 128; i++)
    {
        assert(_ilerps_u8(10, 20, i) <= 20);
        assert(_ilerps_u8(10, 20, i) >= 10);
    }

    /** --- _ilerps_i8 Tests --- */
    assert(_ilerps_i8(0, 127, 0) == 0);
    assert(_ilerps_i8(0, 127, 64) == 63);
    assert(_ilerps_i8(0, 127, 128) == 127);

    assert(_ilerps_i8(0, 42, 0) == 0);
    assert(_ilerps_i8(0, 42, 64) == 21);
    assert(_ilerps_i8(0, 42, 128) == 42);

    for(uint32_t i = 0; i <= 128; i++)
    {
        assert(_ilerps_i8(-10, 20, i) <= 20);
        assert(_ilerps_i8(-10, 20, i) >= -10);
    }
}

void test_ilerpd_base()
{
    /** --- _ilerpd_u8 Tests --- */
    assert(_ilerpd_u8(0, 255, 0) == 0);
    assert(_ilerpd_u8(0, 255, 128) == 128);
    assert(_ilerpd_u8(0, 255, 255) == 255);

    assert(_ilerpd_u8(0, 42, 0) == 0);
    assert(_ilerpd_u8(0, 42, 128) == 21);
    assert(_ilerpd_u8(0, 42, 255) == 42);

    for(uint32_t i = 0; i <= 255; i++)
    {
        assert(_ilerpd_u8(10, 20, i) <= 20);
        assert(_ilerpd_u8(10, 20, i) >= 10);
    }
}

// Entry point
int main()
{
    test_ilerps_base();
    test_ilerpd_base();

    return 0;
}