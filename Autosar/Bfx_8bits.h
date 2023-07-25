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
static inline boolean Bfx_TstBitMask_u8u8_u8(uint8 Data,uint8 Mask);
static inline boolean Bfx_TstBitLnMask_u8u8_u8(uint8 Data,uint8 Mask);
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
    for (uint8 i = (BitStartPin + (BitLn)); i <= 7u; i++)//revisar esta parte
    {
        /* code */
        Data &= ~(0x1 << i);
    }
    Data = (Data >> (BitStartPin));

    /*
    7654 3210
    1100 0000 = 192
    11bb bs00 = 220
    1111 1100
    0000 0111 = resultado por el test
    0000 1111 = Respuesta 


    1011 1010
    0001 0111 >> 3
    0000 0011

    0100 1100
    0001 0011 >> 2
    0000 0011 
    */
   return Data;
}

static inline void Bfx_SetBitMask_u8u8(uint8* Data, uint8 Mask)
{
    *Data = *Data | Mask;
}

static inline void Bfx_ClrBitMask_u8u8(uint8* Data, uint8 Mask)
{
    *Data = *Data &~ Mask;
}

static inline boolean Bfx_TstBitMask_u8u8_u8(uint8 Data,uint8 Mask)
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

static inline boolean Bfx_TstBitLnMask_u8u8_u8(uint8 Data,uint8 Mask)
{
    /*
    COdigo pendiente
    */
}

static inline void Bfx_ToggleBits_u8(uint8* Data)
{
    /*
    Complemento a 1
    */
   for(uint8 i = 0; i <= 8; i++)
   {
        *Data ^= (0x1 << i);
   }
}

static inline void Bfx_ToggleBitMask_u8u8(uint8* Data, uint8 Mask)
{
    /*
    This function toggles the bits of data when the corresponding bit of the mask is 
    enabled and set to 1.
    */
}

static inline void Bfx_ShiftBitRt_u8u8(uint8* Data, uint8 ShiftCnt)
{
    /*
    This function shall shift data to the right by ShiftCnt. The most significant bit 
    (left-most bit) is replaced by a '0' bit and the least significant bit (right-most bit) 
    is dis-carded for every single bit shift cycle.
    */
}

static inline void Bfx_ShiftBitLt_u8u8(uint8* Data, uint8 ShiftCnt)
{
    /*
    This function shall shift data to the left by ShiftCnt. The least significant bit 
    (right-most bit) is replaced by a '0' bit and the most significant bit (left-most bit) is 
    dis-carded for every single bit shift cycle.
    */
}

static inline void Bfx_PutBit_u8u8u8(uint8* Data, uint8 BitPn, boolean Status)
{
    if(Status == true)
    {
        *Data |= (0x1 << BitPn);   
    }
    else
    {
        *Data &= ~(0x1 << BitPn);
    }
}

#endif