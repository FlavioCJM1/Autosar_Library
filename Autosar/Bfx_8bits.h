#ifndef BFX_8BITS_H__
#define BFX_8BITS_H__

#include "Platform_Types.h"

static inline void Bfx_SetBit_u8u8(uint8* Data, uint8 BitPn);
static inline void Bfx_ClrBit_u8u8(uint8* Data, uint8 BitPn);
static inline boolean Bfx_GetBit_u8u8_u8(uint8 Data,uint8 BitPn);
static inline void Bfx_SetBits_u8u8u8u8( uint8* Data, uint8 BitStartPn, uint8 BitLn, uint8 Status );
static inline uint8 Bfx_GetBits_u8u8u8_u8(uint8 Data,uint8 BitStartPin,uint8 BitLn);
static inline void Bfx_SetBitMask_u8u8(uint8* Data, uint8 Mask);
static inline void Bfx_ClrBitMask_u8u8(uint8* Data, uint8 Mask);
static inline boolean Bfx_TstBitMask_u8u8_u8(uint8,uint8);
static inline boolean Bfx_TstBitLnMask_u8u8_u8(uint8,uint8);
static inline void Bfx_ToggleBits_u8(uint8* Data);
static inline void Bfx_ToggleBitMask_u8u8(uint8* Data, uint8 Mask);
static inline void Bfx_ShiftBitRt_u8u8(uint8* Data, uint8 ShiftCnt);
static inline void Bfx_ShiftBitLt_u8u8(uint8* Data, uint8 ShiftCnt);
static inline void Bfx_PutBit_u8u8u8(uint8* Data, uint8 BitPn, boolean Status);

static inline void Bfx_SetBit_u8u8(uint8* Data, uint8 BitPn)
{
    *Data = *Data | (0x01 << BitPn);
}

static inline void Bfx_ClrBit_u8u8(uint8* Data, uint8 BitPn)
{
    *Data = (*Data & ~(0x01 << BitPn));
}

static inline boolean Bfx_GetBit_u8u8_u8(uint8 Data,uint8 BitPn)
{
    bool Result;

    if(((Data & (0x01 << BitPn)) != 0))
    {
        Result = true;
    }
    else
    {
        Result = false;
    }

    return Result;
}

static inline void Bfx_SetBits_u8u8u8u8( uint8* Data, uint8 BitStartPn, uint8 BitLn, uint8 Status )
{
    uint8 count;
    count = BitStartPn + BitLn;
    for(uint8 i = BitStartPn; i < count; i++)
    {
        *Data = *Data | (0x01 << i);
    }
}

static inline uint8 Bfx_GetBits_u8u8u8_u8(uint8 Data,uint8 BitStartPin,uint8 BitLn)
{
    Data = (Data >> (BitStartPin));

    for(uint8 i = (BitLn); i <= 8u; i++)
    {
        //Data = (Data & (0x0 << i));
        Data &= ~(0x1 << i);
    }
    /*
    0000 0000
    0100 0000 >> 6 
    0000 0001

    1011 1010
    0001 0111 >> 3
    0000 0011

    0100 1100
    0001 0011 >> 2
    0000 0011 
    */
   return Data;
}

#endif