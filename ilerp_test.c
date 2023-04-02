//
// Created by Walera on 02.04.2023.
//
#include <assert.h>
#include "ilerp.h"

void test_ilerps_base()
{
    assert(_ilerps_base(0, 255, 0, uint8_t) == 0);
    assert(_ilerps_base(0, 255, 64, uint8_t) == 127);
    assert(_ilerps_base(0, 255, 128, uint8_t) == 255);

    assert(_ilerps_base(0, 42, 0, uint8_t) == 0);
    assert(_ilerps_base(0, 42, 64, uint8_t) == 21);
    assert(_ilerps_base(0, 42, 128, uint8_t) == 42);

    for(uint32_t i = 0; i <= 128; i++)
    {
        assert(_ilerps_base(0, 20, i, uint8_t) <= 20);
        assert(_ilerps_base(10, 20, i, uint8_t) <= 20);
        assert(_ilerps_base(10, 20, i, uint8_t) >= 10);
    }
}

void test_ilerpd_base()
{
    assert(_ilerpd_base(0, 255, 0, uint8_t) == 0);
    assert(_ilerpd_base(0, 255, 128, uint8_t) == 128);
    assert(_ilerpd_base(0, 255, 255, uint8_t) == 255);

    assert(_ilerpd_base(0, 42, 0, uint8_t) == 0);
    assert(_ilerpd_base(0, 42, 128, uint8_t) == 21);
    assert(_ilerpd_base(0, 42, 255, uint8_t) == 42);
}

// Entry point
int main()
{
    test_ilerps_base();
    test_ilerpd_base();

    return 0;
}