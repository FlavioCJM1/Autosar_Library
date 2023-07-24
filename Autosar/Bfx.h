#ifndef BFX_H__
#define BFX_H__

#include "Platform_Types.h"

/*
static inline void Bfx_SetBit_<TypeMn>u8( <Type> *Data, uint8 BitPn )
static inline void Bfx_ClrBit_<TypeMn>u8( <Type>* Data, uint8 BitPn )
static inline boolean Bfx_GetBit_<InTypeMn>u8_u8( <InType> Data, uint8 BitPn )
static inline void Bfx_SetBits_<TypeMn>u8u8u8( <Type>* Data, uint8 BitStartPn, uint8 BitLn, uint8 Status )
static inline <Type> Bfx_GetBits_<TypeMn>u8u8_<TypeMn>( <Type> Data, uint8 BitStartPn, uint8 BitLn )
static inline void Bfx_SetBitMask_<TypeMn><TypeMn>( <Type>* Data, <Type> Mask )
static inline void Bfx_ClrBitMask_<TypeMn><TypeMn>( <Type>* Data, <Type> Mask )
static inline boolean Bfx_TstBitMask_<InTypeMn><InTypeMn>_u8( <InType> Data, <InType> Mask )
static inline boolean Bfx_TstBitLnMask_<InTypeMn><InTypeMn>_u8( <InType> Data, <InType> Mask )
static inline void Bfx_ToggleBits_<TypeMn>( <Type>* Data )
static inline void Bfx_ToggleBitMask_<TypeMn><TypeMn>( <Type>* Data, <Type> Mask )
static inline void Bfx_ShiftBitRt_<TypeMn>u8( <Type>* Data, uint8 ShiftCnt )
static inline void Bfx_ShiftBitLt_<TypeMn>u8( <Type>* Data, uint8 ShiftCnt )
static inline void Bfx_PutBit_<TypeMn>u8u8( <Type>* Data, uint8 BitPn, boolean Status )
*/

/*
*8bits functions
*/
static inline void Bfx_SetBit_u8u8(uint8* Data, uint8 BitPn);
static inline void Bfx_ClrBit_u8u8(uint8* Data, uint8 BitPn);
static inline boolean Bfx_GetBit_u8u8_u8(uint8,uint8);
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

/*
*32bits functions
*/
static inline void Bfx_SetBit_u32u8(uint32* Data, uint8 BitPn);
static inline void Bfx_ClrBit_u32u8(uint32* Data, uint8 BitPn);
static inline boolean Bfx_GetBit_u32u8_u8(uint32,uint8);
static inline void Bfx_SetBits_u32u8u8u8( uint32* Data, uint8 BitStartPn, uint8 BitLn, uint8 Status );
static inline uint32 Bfx_GetBits_u32u8u8_u8(uint32 Data,uint8 BitStartPin,uint8 BitLn);
static inline void Bfx_SetBitMask_u32u32(uint32* Data, uint32 Mask);
static inline void Bfx_ClrBitMask_u32u32(uint32* Data, uint8 Mask);
static inline boolean Bfx_TstBitMask_u32u32_u8(uint32,uint32);
static inline boolean Bfx_TstBitLnMask_u32u32_u8(uint32,uint32);
static inline void Bfx_ToggleBits_u32(uint32* Data);
static inline void Bfx_ToggleBitMask_u32u32(uint32* Data, uint32 Mask);
static inline void Bfx_ShiftBitRt_u32u8(uint32* Data, uint8 ShiftCnt);
static inline void Bfx_ShiftBitLt_u32u8(uint32* Data, uint8 ShiftCnt);
static inline void Bfx_PutBit_u32u8u8(uint32* Data, uint8 BitPn, boolean Status);


#endif