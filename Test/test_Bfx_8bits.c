#include "unity.h"
#include "Bfx_8bits.h"

/*this function is required by Ceedling to run any code before the test cases*/
void setUp( void )
{
}

/*this function is required by Ceedling to run any code after the test cases*/
void tearDown( void )
{
}

/**
 * @brief   **Test set bit 2**
 *
 * The test validates if bit 2 is set over a varible with value 0x00, to pass the test data should have
 * a value of 0x04.
 */
void test__Bfx_SetBit_u8u8__bit2( void )
{
    uint8 Data = 0u;
    Bfx_SetBit_u8u8( &Data, 2u );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x04, "Bit 2 was not set as supposed to be" );
}

/**
 * @brief   **Test set bit 7**
 *
 * The test validates if bit 7 is set over a varible with value 0x00, to pass data tested should have
 * a value of 0x80.
 */
void test__Bfx_SetBit_u8u8__bit7( void )
{
    uint8 Data = 0u;
    Bfx_SetBit_u8u8( &Data, 7u );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x80, "Bit 7 was not set as supposed to be" );
}

/**
 * @brief   **Test clear bit 2**
 *
 * The test validates if bit 2 is clear over a varible with value 0x82, to pass data tested should have
 * a value of 0x52.
 */
void test_Bfx_ClrBit_u8u8_bit2(void)
{
    uint8 Data = 82u;
    Bfx_ClrBit_u8u8(&Data, 2u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x52, "Bit 2 was not clear as supposed to be" );
}

void test_Bfx_ClrBit_u8u8_bit5(void)
{
    uint8 Data = 128u;
    Bfx_ClrBit_u8u8(&Data, 5u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x80, "Bit 2 was not clear as supposed to be" );
}

void test_Bfx_GetBit_u8u8_u8_bit1(void)
{
    uint8 Data = 0u;
    bool test = Bfx_GetBit_u8u8_u8(Data, 1u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, false, "Bit 2 was not clear as supposed to be" );
}

void test_Bfx_GetBit_u8u8_u8_bit2(void)
{
    uint8 Data = 0u;
    bool test = Bfx_GetBit_u8u8_u8(Data, 1u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, false, "Bit 2 was not clear as supposed to be" );
}

void test_Bfx_Setbit_u8u8u8u8_bit3(void)
{
    uint8 Data = 128u;
    Bfx_SetBits_u8u8u8u8(&Data, 3u, 3u, 0x01);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xB8, "Bit 3 was not clear as supposed to be" );
}

void test_Bfx_Setbit_u8u8u8u8_bit4(void)
{
    uint8 Data = 128u;
    Bfx_SetBits_u8u8u8u8(&Data, 4u, 2u, 0x01);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xB0, "Bit 3 was not clear as supposed to be" );
}

void test_Bfx_GetBits_u8u8u8_u8(void)
{
    uint8 Data = 76u;
    uint8 test = Bfx_GetBits_u8u8u8_u8(Data, 2u, 2u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( test, 0x03, "Bit 3 was not clear as supposed to be" );
}