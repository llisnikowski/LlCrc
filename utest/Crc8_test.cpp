#include "gtest/gtest.h"
#include "llCrc/Crc8.hpp"


// todo
// TEST(Crc8_test, calc8)
// {
//     // EXPECT_EQ(Crc8::calc((int8_t)0x3f), 0xbd); // !! (int8_t) !!
//     // uint32_t value = 0x3f17aa62;
//     // EXPECT_EQ(Crc8::calc(value), 0x7c);
// }

TEST(Crc8_test, arraySingleValue)
{
    std::vector<uint8_t> data = {0x3f};
    EXPECT_EQ(Crc8::calc(data), 0xbd);
}

TEST(Crc8_test, rawArray)
{
    uint8_t data[4] = {0x3f, 0x17, 0xaa, 0x62};
    EXPECT_EQ(Crc8::calc(data, 4), 0x7c);
}

TEST(Crc8_test, array)
{
    std::vector<uint8_t> data = {0x3f, 0x17, 0xaa, 0x62};
    EXPECT_EQ(Crc8::calc(data), 0x7c);
}

TEST(Crc8_test, iterators)
{
    std::vector<uint8_t> data = {0x3f, 0x17, 0xaa, 0x62};
    EXPECT_EQ(Crc8::calc(data.begin(), data.end()), 0x7c);
}




