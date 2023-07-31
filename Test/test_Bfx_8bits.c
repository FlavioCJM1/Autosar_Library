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
    Bfx_SetBit_u8u8( &Data, 2u );//funcion de usuario a probar
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0x04, Data, "Bit 2 was not set as supposed to be" );
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

/**
 * @brief   **Test clear bit 5**
 *
 * The test validates if bit 5 is clear over a varible with value 0x82, to pass data tested should have
 * a value of 0x80.
 */
void test_Bfx_ClrBit_u8u8_bit5(void)
{
    uint8 Data = 128u;
    Bfx_ClrBit_u8u8(&Data, 5u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x80, "Bit 5 was not clear as supposed to be" );
}

/**
 * @brief   **Test clear bit 1**
 *
 * The test validates the state of bit 1.
 */
void test_Bfx_GetBit_u8u8_u8_bit1(void)
{
    uint8 Data = 0u;
    bool test = Bfx_GetBit_u8u8_u8(Data, 1u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, false, "The value of the 1 bit was as expected" );
}

/**
 * @brief   **Test clear bit 2**
 *
 * The test validates the state of bit 2.
 */
void test_Bfx_GetBit_u8u8_u8_bit2(void)
{
    uint8 Data = 0u;
    bool test = Bfx_GetBit_u8u8_u8(Data, 1u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, false, "The value of the 2 bit was as expected" );
}

/**
 * @brief   **Test Set bits**
 *
 * The test validates the state of the bits since the startbit to the 
 * BitLn, in this case the bit 3 with a length of 3 bits.
 */
void test_Bfx_Setbit_u8u8u8u8_bit3(void)
{
    uint8 Data = 128u;
    Bfx_SetBits_u8u8u8u8(&Data, 3u, 3u, 0x01);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xB8, "Bit 3 with a length of 3 was not set correctly" );
}

/**
 * @brief   **Test Set bits**
 *
 * The test validates the state of the bits since the startbit to the 
 * BitLn, in this case the bit 4 with a length of 2 bits.
 */
void test_Bfx_Setbit_u8u8u8u8_bit4(void)
{
    uint8 Data = 128u;
    Bfx_SetBits_u8u8u8u8(&Data, 4u, 2u, 0x01);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0xB0, "Bit 4 with a length of 2 was not set correctly" );
}

void test_Bfx_GetBits_u8u8u8_u8(void)
{
    uint8 Data = 220u;
    uint8 test = Bfx_GetBits_u8u8u8_u8(Data, 2u, 4u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0x0F, test, "Bit 3 was not clear as supposed to be" );
}

/**
 * @brief   **Test Set bit Mask128**
 *
 * The test validates the state of the bits with the corresponding mask
 * and remaining bits retain their original values. Mask 128.
 */
void test_Bfx_SetBitMask_u8u8_Mask128(void)
{
    uint8 Data = 16u;
    Bfx_SetBitMask_u8u8(&Data, 128u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x90, "Bit 3 was not clear as supposed to be" );
}

/**
 * @brief   **Test Set bit Mask32**
 *
 * The test validates the state of the bits with the corresponding mask
 * and remaining bits retain their original values. Mask 32.
 */
void test_Bfx_SetBitMask_u8u8_Mask32(void)
{
    uint8 Data = 16u;
    Bfx_SetBitMask_u8u8(&Data, 32u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x30, "Bit 3 was not clear as supposed to be" );
}

/**
 * @brief   **Test Clear bit Mask128**
 *
 * The test validates the state of the cleared bits with the corresponding mask
 * and remaining bits retain their original values. Clear Mask 128.
 */
void test_Bfx_ClrBitMask_u8u8_ClMASK128(void)
{
    uint8 Data = 144u;
    Bfx_ClrBitMask_u8u8(&Data, 128u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x10, "Bit 7 should be cleaned" );
}

/**
 * @brief   **Test Clear bit Mask64**
 *
 * The test validates the state of the cleared bits with the corresponding mask
 * and remaining bits retain their original values. Clear Mask 64.
 */
void test_Bfx_ClrBitMask_u8u8_ClMASK64(void)
{
    uint8 Data = 80u;
    Bfx_ClrBitMask_u8u8(&Data, 128u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x50, "Bit 6 should be cleaned" );
}

void test_Bfx_TstBitMask_u8u8_u8_TstBitmsk_144(void)
{
    uint8 Data = 147u;
    uint8 test = Bfx_TstBitMask_u8u8_u8(Data, 144u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( true, test, "The & with the mask was not equals to mask" );
}

void test_Bfx_TstBitMask_u8u8_u8_TstBitmsk_15(void)
{
    uint8 Data = 240u;
    uint8 test = Bfx_TstBitMask_u8u8_u8(Data, 15u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( false, test, "The & with the mask was not equals to mask" );
}

void test_Bfx_TstBitLnMask_u8u8_u8_Mask64(void)//num
{
    uint8 Data = 128u;
    uint8 test = Bfx_TstBitLnMask_u8u8_u8(Data, 64u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( false, test, "The & with the mask was not equals to mask" );
}

void test_Bfx_TstBitLnMask_u8u8_u8_Mask87(void)//num
{
    uint8 Data = 168u;
    uint8 test = Bfx_TstBitLnMask_u8u8_u8(Data, 170u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( true, test, "The & with the mask was not equals to mask" );
}

void test_Bfx_ToggleBits_u8_Toogle170(void)
{
    uint8 Data = 170u;
    Bfx_ToggleBits_u8(&Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0x55, Data, "The & with the mask was not equals to mask" );
}

void test_Bfx_ToggleBits_u8_Toogle85(void)
{
    uint8 Data = 85u;
    Bfx_ToggleBits_u8(&Data);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0xAA, Data, "The & with the mask was not equals to mask" );
}

void test_Bfx_ToggleBitMask_u8u8_MASK140(void)
{
    uint8 Data = 211u;
    Bfx_ToggleBitMask_u8u8(&Data, 140u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0x5F, Data, "The & with the mask was not equals to mask" );
}

void test_Bfx_ToggleBitMask_u8u8_MASKFF(void)
{
    uint8 Data = 0u;
    Bfx_ToggleBitMask_u8u8(&Data, 255u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0xFF, Data, "The & with the mask was not equals to mask" );
}

void test_Bfx_ShiftBitRt_u8u8(void)
{
    uint8 Data = 220u;
    Bfx_ShiftBitRt_u8u8(&Data,4u);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0x04, Data, "The & with the mask was not equals to mask" );
}

void test_Bfx_PutBit_u8u8u8_231(void)
{
    uint8 Data = 231u;
    Bfx_PutBit_u8u8u8(&Data, 4u, true);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0xF7, Data, "The & with the mask was not equals to mask" );
}

void test_Bfx_PutBit_u8u8u8_156(void)
{
    uint8 Data = 156u;
    Bfx_PutBit_u8u8u8(&Data, 4u, false);
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( 0x8C, Data, "The & with the mask was not equals to mask" );
}