#pragma once
#include <cstdint>
#include <type_traits>

// poly = 0x8005, initValue = 0xffff
class Crc16Modbus
{
public:
    template <typename T>
    static uint16_t calc(T t);
    template <typename T>
    static uint16_t calc(T begin, T end);
    static uint16_t calc(const uint8_t *data, std::size_t size);
    template <typename T>
    inline static uint16_t calcContainer(T t);
};


template <typename T>
uint16_t Crc16Modbus::calc(const T t)
{
    return calcContainer(t);
}

template <typename T>
uint16_t Crc16Modbus::calc(T begin, T end)
{
	static const uint16_t table[2] = {0x0000, 0xA001};
	uint16_t crc = 0xFFFF;
	char bit = 0;
	unsigned int _xor = 0;

	for(;begin < end; begin++)
	{
        uint8_t v = (uint8_t)*begin;
		crc ^= v;

		for( bit = 0; bit < 8; bit++ )
		{
			_xor = crc & 0x01;
			crc >>= 1;
			crc ^= table[_xor];
		}
	}

	return crc;
}


template <typename T>
uint16_t Crc16Modbus::calcContainer(T t)
{
    return calc(t.begin(), t.end());
}








