#include "Crc16Modbus.hpp"


uint16_t Crc16Modbus::calc(const uint8_t *data, std::size_t size)
{
	static const uint16_t table[2] = {0x0000, 0xA001};
	uint16_t crc = 0xFFFF;
	char bit = 0;
	unsigned int _xor = 0;

	for(unsigned i = 0; i < size; i++ )
	{
		crc ^= data[i];

		for( bit = 0; bit < 8; bit++ )
		{
			_xor = crc & 0x01;
			crc >>= 1;
			crc ^= table[_xor];
		}
	}

	return crc;
}