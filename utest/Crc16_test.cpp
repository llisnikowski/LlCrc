#include "gtest/gtest.h"
#include "llCrc/Crc16.hpp"


// todo
// TEST(Crc16_test, calc8)
// {
//     // EXPECT_EQ(Crc16::calc((uint16_t)0x3f), 0xbd); // !! (uint16_t) !!
//     // uint32_t value = 0x3f17aa62;
//     // EXPECT_EQ(Crc16::calc(value), 0x7c);
// }

TEST(Crc16_test, arraySingleValue)
{
    std::vector<uint8_t> data = {0x3f};
    EXPECT_EQ(Crc16::calc(data), 0x1040);
}

TEST(Crc16_test, rawArray)
{
    uint8_t data[4] = {0x3f, 0x17, 0xaa, 0x62};
    EXPECT_EQ(Crc16::calc(data, 4), 0x5943);
}

TEST(Crc16_test, array)
{
    std::vector<uint8_t> data = {0x3f, 0x17, 0xaa, 0x62};
    EXPECT_EQ(Crc16::calc(data), 0x5943);
}

TEST(Crc16_test, iterators)
{
    std::vector<uint16_t> data = {0x3f, 0x17, 0xaa, 0x62};
    EXPECT_EQ(Crc16::calc(data.begin(), data.end()), 0x5943);
}




