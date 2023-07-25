#ifndef BFX_32BITS_H__
#define BFX_32BITS_H__

#include "Platform_Types.h"

static inline void Bfx_SetBit_u32u8(uint32* Data, uint8 BitPn);
static inline void Bfx_ClrBit_u32u8(uint32* Data, uint8 BitPn);
static inline boolean Bfx_GetBit_u32u8_u8(uint32,uint8);
static inline void Bfx_SetBits_u32u8u8u8( uint32* Data, uint8 BitStartPn, uint8 BitLn, uint8 Status );
static inline uint32 Bfx_GetBits_u32u8u8_u8(uint32 Data,uint8 BitStartPin,uint8 BitLn);
static inline void Bfx_SetBitMask_u32u32(uint32* Data, uint32 Mask);
static inline void Bfx_ClrBitMask_u32u32(uint32* Data, uint32 Mask);
static inline boolean Bfx_TstBitMask_u32u32_u8(uint32,uint32);
static inline boolean Bfx_TstBitLnMask_u32u32_u8(uint32,uint32);
static inline void Bfx_ToggleBits_u32(uint32* Data);
static inline void Bfx_ToggleBitMask_u32u32(uint32* Data, uint32 Mask);
static inline void Bfx_ShiftBitRt_u32u8(uint32* Data, uint8 ShiftCnt);
static inline void Bfx_ShiftBitLt_u32u8(uint32* Data, uint8 ShiftCnt);
static inline void Bfx_PutBit_u32u8u8(uint32* Data, uint8 BitPn, boolean Status);

static inline void Bfx_SetBit_u32u8(uint32* Data, uint8 BitPn)
{
    *Data = *Data | (0x01 << BitPn);
}

static inline void Bfx_ClrBit_u32u8(uint32* Data, uint8 BitPn)
{
    *Data = (*Data & ~(0x01 << BitPn));
}

static inline boolean Bfx_GetBit_u32u8_u8(uint32 Data,uint8 BitPn)
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

static inline void Bfx_SetBits_u32u8u8u8( uint32* Data, uint8 BitStartPn, uint8 BitLn, uint8 Status )
{
    uint8 count;
    count = BitStartPn + BitLn;
    for(uint8 i = BitStartPn; i < count; i++)
    {
        *Data = *Data | (0x01 << i);
    }
}

static inline void Bfx_SetBitMask_u32u32(uint32* Data, uint32 Mask)
{
    *Data = *Data | Mask;
}

static inline void Bfx_ClrBitMask_u32u32(uint32* Data, uint32 Mask)
{
    *Data = *Data &~ Mask;
}

static inline boolean Bfx_TstBitMask_u32u32_u8(uint32 Data,uint32 Mask)
{
    bool Result;

    if((Data & Mask) == Mask)
    {
        Result = true;
    }
    else
    {
        Result = false;
    }

    return Result;
}

#endif