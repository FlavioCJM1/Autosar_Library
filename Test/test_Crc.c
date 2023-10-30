#include "unity.h"
#include "Crc.h"

/*this function is required by Ceedling to run any code before the test cases*/
void setUp( void )
{
}

/*this function is required by Ceedling to run any code after the test cases*/
void tearDown( void )
{
}

void test_Crc_8bits(void)
{
    uint8 data[] = {0x33, 0x22, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
    uint32 dataLength = sizeof(data) / sizeof(data[0]);
    uint8 startValue = 0xFF;  // Initial CRC value
    boolean isFirstCall = true;  // First call indicator
    uint8 crcResult = Crc_CalculateCRC8(data, dataLength, startValue, isFirstCall);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0xCB, crcResult, "Bit 2 was not set as supposed to be" );
}

void test_Crc_8bits2HF(void)
{
    uint8 data[] = {0xFF, 0xFF, 0xFF, 0xFF};
    uint32 dataLength = sizeof(data) / sizeof(data[0]);;
    uint8 startValue = 0xFF;  // Initial CRC value
    boolean isFirstCall = true;  // First call indicator
    uint8 crcResult = ~Crc_CalculateCRC8H2F(data, dataLength, startValue, isFirstCall);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0x6C, crcResult, "Bit 2 was not set as supposed to be" );
}

void test_Crc_16bit(void)
{
    uint8 data[] = {0x0F, 0xAA, 0x00, 0x55};
    uint32 dataLength = sizeof(data) / sizeof(data[0]);
    uint16 startValue = 0xFFFF;
    boolean isFirstCall = true;
    uint16 crcResult = Crc_CalculateCRC16(data, dataLength, startValue, isFirstCall);
    TEST_ASSERT_EQUAL_HEX16_MESSAGE(0x2023, crcResult, "Bit 2 was not set as supposed to be");
}

void test_Crc_32bit(void)
{
    //uint8 data[] = {0x00, 0x00, 0x00, 0x00}; //result 0x2144DF1C
    uint8 data[] = {0xF2, 0x01, 0x83}; //result 0x24AB9D77
    //uint32 dataLength = sizeof(data) / sizeof(data[0]);
    uint32 dataLength = sizeof(data);
    uint32 startValue = 0xFFFFFFFF;
    boolean isFirstCall = true;
    uint32 crcResult = Crc_CalculateCRC32(data, dataLength, startValue, isFirstCall);
    //crcResult = 0x00000003;
    TEST_ASSERT_EQUAL_HEX32_MESSAGE(0x24AB9D77, crcResult, "Bit 2 was not set as supposed to be");
}

/* void test_Crc_32bitP4(void)
{
    uint8 data[] = {0x00, 0x00, 0x00, 0x00}; //result 0x6FB32240
    //uint8 data[] = {0xF2, 0x01, 0x83}; //result 0x4F721A25
    //uint32 dataLength = sizeof(data) / sizeof(data[0]);
    uint32 dataLength = sizeof(data);
    uint32 startValue = 0xFFFFFFFF;
    boolean isFirstCall = true;
    uint32 crcResult = Crc_CalculateCRC32P4(data, dataLength, startValue, isFirstCall);
    TEST_ASSERT_EQUAL_HEX32_MESSAGE(0x6FB32240, crcResult, "Bit 2 was not set as supposed to be");
} */

void test_Crc_64bitP7(void)
{
    uint8 data[] = {0x00, 0x00, 0x00, 0x00}; //result 0xF4A586351E1B9F4B
    //uint8 data[] = {0xF2, 0x01, 0x83}; //result 0x4F721A25
    //uint32 dataLength = sizeof(data) / sizeof(data[0]);
    uint64 dataLength = sizeof(data);
    uint64 startValue = 0xFFFFFFFFFFFFFFFF;
    boolean isFirstCall = true;
    uint64 crcResult = Crc_CalculateCRC64P7(data, dataLength, startValue, isFirstCall);
    TEST_ASSERT_EQUAL_HEX64_MESSAGE(0xF4A586351E1B9F4B, crcResult, "Bit 2 was not set as supposed to be");
}

void test_Crc_16bitARC(void)
{
    //uint8 data[] = {0x92, 0x6B, 0x55};
    //uint8 data[] = {0x0F, 0xAA, 0x00, 0x55};
    //uint8 data[] = {0x00, 0x0F, 0x55, 0x11};
    //uint8 data[] = {0x33, 0x22, 0x55, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
    //uint8 data[] = {0x92, 0x6B, 0x55};
    uint8 data[] = {0xFF, 0xFF, 0xFF, 0xFF};
    uint32 dataLength = sizeof(data);  
    uint16 startValue = 0x0000;
    boolean isFirstCall = true;
    uint16 crcResult = Crc_CalculateCRC16ARC(data, dataLength, startValue, isFirstCall);
    //crcResult = 0x0002;
    TEST_ASSERT_EQUAL_HEX16_MESSAGE(0x6CCF, crcResult, "Bit 2 was not set as supposed to be");
} 

void test_Crc_16bit_ARC_PRUEBA(void)
{
    //uint8 data[] = {0x92, 0x6B, 0x55}; //0100 1111 1000 0000 1100 0001 valores separados reflejados 0xC1804F
    uint8 data[] = {0xFF, 0xFF, 0xFF, 0xFF};
    uint32 dataLength = sizeof(data);  //1100 0001 1000 0000 0100 1111 valores juntos reflejados 0xC1804F
    uint16 startValue = 0x0000;
    boolean isFirstCall = true;
    uint16 crcResult = Crc_SwCalculateCRC16ARC(data, dataLength, startValue, isFirstCall);
    TEST_ASSERT_EQUAL_HEX16_MESSAGE(0xE24E, crcResult, "Bit 2 was not set as supposed to be");
} 