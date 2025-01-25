#pragma once
#include <cstdint>
#include <type_traits>

class Crc16
{
public:
    template <typename T>
    static uint16_t calc(T t);
    template <typename T>
    static uint16_t calc(T begin, T end);
    static uint16_t calc(uint8_t *data, std::size_t size);
    template <typename T>
    inline static uint16_t calcContainer(T t);
};


template <typename T>
uint16_t Crc16::calc(const T t)
{
    return calcContainer(t);
}

template <typename T>
uint16_t Crc16::calc(T begin, T end)
{
    constexpr uint16_t poly = 0x8005;
    uint16_t out = 0;
    int bits_read = 0, bit_flag;

    while(begin < end)
    {
        bit_flag = out >> 15;
        out <<= 1;
        out |= uint16_t(((*begin&0xff) >> bits_read) & 1);

        bits_read++;
        if(bits_read > 7)
        {
            bits_read = 0;
            begin++;
        }

        if(bit_flag)
            out ^= poly;

    }

    int i;
    for (i = 0; i < 16; ++i) {
        bit_flag = out >> 15;
        out <<= 1;
        if(bit_flag)
            out ^= poly;
    }

    uint16_t crc = 0;
    i = 0x8000;
    uint16_t j = 0x0001;
    for (; i != 0; i >>=1, j <<= 1) {
        if (i & out) crc |= j;
    }

    return crc;
}


template <typename T>
uint16_t Crc16::calcContainer(T t)
{
    return calc(t.begin(), t.end());
}








