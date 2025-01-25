#include "gtest/gtest.h"
#include "llCrc/Crc16Ibm.hpp"


// todo
// TEST(Crc16Ibm_test, calc8)
// {
//     // EXPECT_EQ(Crc16::calc((uint16_t)0x3f), 0xbd); // !! (uint16_t) !!
//     // uint32_t value = 0x3f17aa62;
//     // EXPECT_EQ(Crc16::calc(value), 0x7c);
// }

TEST(Crc16Ibm_test, arraySingleValue)
{
    std::vector<uint8_t> data = {0x3f};
    EXPECT_EQ(Crc16Ibm::calc(data), 0xFD80);
}

TEST(Crc16Ibm_test, rawArray)
{
    uint8_t data[7] = {0x55, 0x09, 0x14, 0x04, 0x04, 0x0a, 0x00};
    EXPECT_EQ(Crc16Ibm::calc(data, 7), 0x5A6A);
}

TEST(Crc16Ibm_test, array)
{
    std::vector<uint8_t> data = {0x55, 0x09, 0x14, 0x04, 0x04, 0x0a, 0x00};
    EXPECT_EQ(Crc16Ibm::calc(data), 0x5A6A);
}

TEST(Crc16Ibm_test, iterators)
{
    std::vector<uint16_t> data = {0x55, 0x09, 0x14, 0x04, 0x04, 0x0a, 0x00};
    EXPECT_EQ(Crc16Ibm::calc(data.begin(), data.end()), 0x5A6A);
}




