#pragma once
#include <cstdint>
#include <type_traits>

// poly = 0x8005, initValue = 0xffff
class Crc16Ibm
{
public:
    template <typename T>
    static uint16_t calc(T t);
    template <typename T>
    static uint16_t calc(T begin, T end);
    static uint16_t calc(const uint8_t *data, std::size_t size);
    template <typename T>
    inline static uint16_t calcContainer(T t);

private:
	static uint8_t reflect8(uint8_t in);
	static uint16_t reflect16(uint16_t org);
};


template <typename T>
uint16_t Crc16Ibm::calc(const T t)
{
    return calcContainer(t);
}

template <typename T>
uint16_t Crc16Ibm::calc(T begin, T end)
{
	uint16_t poly = 0x8005;
	static const uint16_t table[2] = {0x0000, reflect16(poly)};
	uint16_t crc = 0xFFFF;
	char bit = 0;
	unsigned int _xor = 0;

	for(;begin < end; begin++)
	{
		crc ^= reflect8((uint8_t)*begin);

		for( bit = 0; bit < 8; bit++ )
		{
			_xor = crc & 0x01;
			crc >>= 1;
			crc ^= table[_xor];
		}
	}
	return reflect16(crc);
}


template <typename T>
uint16_t Crc16Ibm::calcContainer(T t)
{
    return calc(t.begin(), t.end());
}








