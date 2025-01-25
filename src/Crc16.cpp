#include "Crc16.hpp"



uint16_t Crc16::calc(uint8_t *data, std::size_t size)
{

    constexpr uint16_t poly = 0x8005;
    uint16_t out = 0;
    int bits_read = 0, bit_flag;

    for (unsigned i = 0; i < size;)
    {
        bit_flag = out >> 15;
        out <<= 1;
        out |= (data[i] >> bits_read) & 1;

        bits_read++;
        if(bits_read > 7)
        {
            bits_read = 0;
            i++;
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

