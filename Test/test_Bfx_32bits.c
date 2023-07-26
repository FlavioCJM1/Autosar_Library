#include "unity.h"
#include "Bfx_32bits.h"

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
void test__Bfx_SetBit_u32u8__bit2( void )
{
    uint32 Data = 0u;
    Bfx_SetBit_u32u8( &Data, 16u );
    TEST_ASSERT_EQUAL_HEX8_MESSAGE( Data, 0x04, "Bit 2 was not set as supposed to be" );
}