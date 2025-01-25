#pragma once
#include <cstdint>
#include <type_traits>

class Crc8
{
public:
    template <typename T>
    static uint8_t calc(T t);
    template <typename T>
    static uint8_t calc(T begin, T end);
    static uint8_t calc(uint8_t *data, std::size_t size);
    template <typename T>
    inline static uint8_t calcContainer(T t);
};


template <typename T>
uint8_t Crc8::calc(const T t)
{
    return calcContainer(t);
}


template <typename T>
uint8_t Crc8::calc(T begin, T end)
{
    const uint8_t poly = 0x07;
    uint8_t crc = 0;

    for (auto it = begin; it < end; it++) {
        crc ^= *it;

        for (int i = 0; i < 8; i++) {
            if ((crc & 0x80) != 0)
                crc = (crc << 1) ^ poly;
            else
                crc <<= 1;
        }
    }
    return crc;
}


template <typename T>
uint8_t Crc8::calcContainer(T t)
{
    return calc(t.begin(), t.end());
}

uint8_t Crc8::calc(uint8_t *data, std::size_t size)
{
    const uint8_t generator = 0x07;
    uint8_t crc = 0;

    for (unsigned i = 0; i < size; i++) {
        crc ^= data[i];

        for (int i = 0; i < 8; i++) {
            if ((crc & 0x80) != 0)
                crc = (crc << 1) ^ generator;
            else
                crc <<= 1;
        }
    }
    return crc;
}







