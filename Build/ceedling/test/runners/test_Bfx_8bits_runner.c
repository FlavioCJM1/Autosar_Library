/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test__Bfx_SetBit_u8u8__bit2(void );
extern void test__Bfx_SetBit_u8u8__bit7(void );
extern void test_Bfx_ClrBit_u8u8_bit2(void);
extern void test_Bfx_ClrBit_u8u8_bit5(void);
extern void test_Bfx_GetBit_u8u8_u8_bit1(void);
extern void test_Bfx_GetBit_u8u8_u8_bit2(void);
extern void test_Bfx_Setbit_u8u8u8u8_bit3(void);
extern void test_Bfx_Setbit_u8u8u8u8_bit4(void);
extern void test_Bfx_GetBits_u8u8u8_u8(void);
extern void test_Bfx_SetBitMask_u8u8_Mask128(void);
extern void test_Bfx_SetBitMask_u8u8_Mask32(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        CEXCEPTION_T e;
        Try {
            setUp();
            func();
        } Catch(e) {
            TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!");
        }
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_Bfx_8bits.c");
  run_test(test__Bfx_SetBit_u8u8__bit2, "test__Bfx_SetBit_u8u8__bit2", 20);
  run_test(test__Bfx_SetBit_u8u8__bit7, "test__Bfx_SetBit_u8u8__bit7", 33);
  run_test(test_Bfx_ClrBit_u8u8_bit2, "test_Bfx_ClrBit_u8u8_bit2", 46);
  run_test(test_Bfx_ClrBit_u8u8_bit5, "test_Bfx_ClrBit_u8u8_bit5", 59);
  run_test(test_Bfx_GetBit_u8u8_u8_bit1, "test_Bfx_GetBit_u8u8_u8_bit1", 71);
  run_test(test_Bfx_GetBit_u8u8_u8_bit2, "test_Bfx_GetBit_u8u8_u8_bit2", 83);
  run_test(test_Bfx_Setbit_u8u8u8u8_bit3, "test_Bfx_Setbit_u8u8u8u8_bit3", 96);
  run_test(test_Bfx_Setbit_u8u8u8u8_bit4, "test_Bfx_Setbit_u8u8u8u8_bit4", 109);
  run_test(test_Bfx_GetBits_u8u8u8_u8, "test_Bfx_GetBits_u8u8u8_u8", 116);
  run_test(test_Bfx_SetBitMask_u8u8_Mask128, "test_Bfx_SetBitMask_u8u8_Mask128", 123);
  run_test(test_Bfx_SetBitMask_u8u8_Mask32, "test_Bfx_SetBitMask_u8u8_Mask32", 130);

  return UnityEnd();
}
