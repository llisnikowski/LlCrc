#include "Crc16Ibm.hpp"


uint16_t Crc16Ibm::calc(const uint8_t *data, std::size_t size)
{
	uint16_t poly = 0x8005;
	static const uint16_t table[2] = {0x0000, reflect16(poly)};
	uint16_t crc = 0xFFFF;
	unsigned int i = 0;
	char bit = 0;
	unsigned int _xor = 0;

	for( i = 0; i < size; i++ )
	{
		crc ^= reflect8(data[i]);

		for( bit = 0; bit < 8; bit++ )
		{
			_xor = crc & 0x01;
			crc >>= 1;
			crc ^= table[_xor];
		}
	}
	return reflect16(crc);
}

uint8_t Crc16Ibm::reflect8(uint8_t in){
    uint8_t out{};
    for(int i = 0; i < 8; i++){
        out <<= 1;
        out |= in & 0x01;
        in >>= 1;
    }
    return out;
}

uint16_t Crc16Ibm::reflect16(uint16_t org){
	return (reflect8((uint8_t)(org & 0xff)) << 8) | reflect8(uint8_t(org>>8));
}
