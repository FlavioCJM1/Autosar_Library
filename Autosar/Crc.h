#ifndef CRC_H_
#define CRC_H_

#include "Platform_Types.h"

#define CRC_CRC16ARC_POLYNOMIAL_REFLECTED (uint16) 0xA001
#define CRC_CRC32_POLYNOMIAL_REFLECTED (uint32) 0xEDB88320
#define CRC_CRC32P4_POLYNOMIAL_REFLECTED (uint32) 0xC8DF352F
#define CRC_CRC64P7_POLYNOMIAL_REFLECTED (uint64)  0xC96C5795D7870F42

/*
https://stackoverflow.com/questions/72660217/capl-script-for-checksum-crc-8-sae-j1850-calculation
https://gist.github.com/hunternsk/aa561a5dcba9e3faa683f34f60d95559
http://www.sunshine2k.de/coding/javascript/crc/crc_js.html
http://www.sunshine2k.de/articles/coding/crc/understanding_crc.html
https://modular-mx.slack.com/files/U05PGS9T08G/F05Q82X9NKF/iopt_hwcrc_main.c?origin_team=T05NT5LMQV8&origin_channel=D05P7597TLH
*/

uint8 Crc_CalculateCRC8 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall);
uint8 Crc_CalculateCRC8H2F (const uint8* Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8H2F, boolean Crc_IsFirstCall);
uint16 Crc_CalculateCRC16 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall);
uint16 Crc_CalculateCRC16ARC(const uint8* Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall);
uint32 Crc_CalculateCRC32 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
uint32 Crc_CalculateCRC32P4 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
uint32 Crc_CalculateCRC32_PRUEBA (const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall);
uint32 Reflect(uint32 data, uint8 bit_count);
uint32 Compute_CRC32_Simple(uint8* bytes, uint32 length);
uint16 Crc_SwCalculateCRC16ARC(const uint8* Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall);
uint64 Crc_CalculateCRC64P7 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint64 Crc_StartValue64, boolean Crc_IsFirstCall);


/**
 * @brief   **Crc_CalculateCRC8**
 *
 * This service makes a CRC8 calculation on Crc_Length data bytes, with SAE J1850 parameters
 */
uint8 Crc_CalculateCRC8 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8, boolean Crc_IsFirstCall)
{
    const uint8 Crc_Polynomial = 0x1D;  // Polynomial for CRC-8
    uint8 crcValue = Crc_StartValue8;

    if (Crc_IsFirstCall)
    {
        crcValue = 0xFF;  // Initialize the CRC value with 0xFF
    }

    for (uint32 i = 0; i < Crc_Length; i++)
    {
        crcValue ^= Crc_DataPtr[i];  // XOR with data byte

        for (uint8 bit = 0; bit < 8; bit++)
        {
            if (crcValue & 0x80)  // Check if MSB is 1
            {
                crcValue = (crcValue << 1) ^ Crc_Polynomial;  // XOR with polynomial
            }
            else
            {
                crcValue <<= 1;
            }
        }
    }

    return crcValue ^ 0xFF;
}

uint8 Crc_CalculateCRC8H2F(const uint8* Crc_DataPtr, uint32 Crc_Length, uint8 Crc_StartValue8H2F, boolean Crc_IsFirstCall)
{
    const uint8 Crc_Polynomial = 0x2F; 
    uint8 crcValue = Crc_StartValue8H2F;

    if(Crc_IsFirstCall)
    {
        crcValue = 0xFF;
    }

    for (uint32 i = 0; i < Crc_Length; i++)
    {
        crcValue ^= Crc_DataPtr[i]; 

        for (uint8 bit = 0; bit < 8; bit++)
        {
            if (crcValue & 0x80) 
            {
                crcValue = (crcValue << 1) ^ Crc_Polynomial;
            }
            else
            {
                crcValue <<= 1;
            }
        }
    }

    return crcValue;
}

uint16 Crc_CalculateCRC16(const uint8* Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall)
{
    const uint16 Crc_Polynomial = 0x1021; 
    uint16 crcValue = Crc_StartValue16;

    if(Crc_IsFirstCall)
    {
        crcValue = 0xFFFF;
    }

    for (uint32 i = 0; i < Crc_Length; i++)
    {
        crcValue ^= (uint16)Crc_DataPtr[i] << 8; 

        for (uint8 bit = 0; bit < 8; bit++)
        {
            if (crcValue & 0x8000) 
            {
                crcValue = (crcValue << 1) ^ Crc_Polynomial;
            }
            else
            {
                crcValue <<= 1;
            }
        }
    }

    return crcValue;
}

uint32 Reflect(uint32 data, uint8 bit_count)
{
    uint32 reflection = 0;
    for (uint8 bit = 0; bit < bit_count; bit++) 
    {
        if (data & 0x01) 
        {
            reflection |= (1 << ((bit_count - 1) - bit));
        }
        data >>= 1;
    }
    return reflection;
}

/* uint16_t Reflect16(uint16_t val) 
{
    uint16_t resVal = 0;

    for (int i = 0; i < 16; i++) 
    {
        if (val & (1 << i)) 
        {
            resVal |= (uint16_t)(1 << (15 - i));
        }
    }

    return resVal;
} */

/* uint32 Crc_CalculateCRC32 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
{
    const uint32 Crc_Polynomial = 0x04C11DB7; 
    uint32 crcValue = Crc_StartValue32;

    if(Crc_IsFirstCall)
    {
        crcValue = 0xFFFFFFFF;
    }*/

    /*for (uint32 i = 0; i < Crc_Length; i++)
    {
        crcValue ^= Crc_DataPtr[i]; 

        for (uint8 bit = 0; bit < 8; bit++)
        {
            if (crcValue & 0x80000000) 
            {
                crcValue = (crcValue << 1) ^ Crc_Polynomial;
            }
            else
            {
                crcValue <<= 1;
            }
        }
    }*/

    /*for (uint32 i = Crc_Length; i < 0; i--)
    {
        crcValue ^= Reflect(Crc_DataPtr[i], 8); 

        for (uint8 bit = 0; bit < 8; bit++)
        {
            if (crcValue & 0x80000000) 
            {
                crcValue = (crcValue << 1) ^ Crc_Polynomial;
            }
            else
            {
                crcValue <<= 1;
            }
        }
    }

    return Reflect(crcValue ^ 0xFFFFFFFF, 32);
} */

uint32 Crc_CalculateCRC32_PRUEBA (const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
{
    uint8 i;
    uint32 startValueTemp;
    startValueTemp = Crc_StartValue32;

    if(Crc_Length != 0)
    {
        if(Crc_IsFirstCall)
        {
            startValueTemp = 0xFFFFFFFF;
        }
        else
        {
            startValueTemp ^= 0xFFFFFFFF;
        }
        while (Crc_Length != 0)
        {
            startValueTemp ^= (uint32) *Crc_DataPtr;
            for(i = 0; i < 8; i++)
            {
                if((startValueTemp & 0x00000001u) != 0u)
                {
                    startValueTemp = (startValueTemp >> 1) ^ CRC_CRC32_POLYNOMIAL_REFLECTED;
                }
                else
                {
                    startValueTemp >> 1;
                }
            }
            Crc_DataPtr++;
            Crc_Length--;
        }
        startValueTemp ^= 0xFFFFFFFF;
    }
    return startValueTemp;
}

uint32 Crc_CalculateCRC32 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
{
    const uint32 Crc_Polynomial = 0xEDB88320; 
    uint32 crcValue = Crc_StartValue32;
    uint8 bit;

    if(Crc_Length != 0u)
    {
        if(Crc_IsFirstCall)
        {
            crcValue = 0xFFFFFFFF;
        }
        else
        {
            crcValue ^= 0xFFFFFFFF;
        }

        for (uint32 i = Crc_Length; i != 0; i--)
        //while(Crc_Length != 0u)
        {
            crcValue ^= (uint32) *Crc_DataPtr; 

            for ( bit = 0; bit < 8; bit++)
            {
                if ((crcValue & 0x00000001u) != 0u) 
                {
                    crcValue = (crcValue >> 1) ^ Crc_Polynomial;
                }
                else
                {
                    crcValue >>= 1;
                }
            }
            Crc_DataPtr++;
            //Crc_Length--;
        }
        crcValue ^= 0xFFFFFFFF;
    }
    return crcValue;
}

uint32 Crc_CalculateCRC32P4 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
{
    uint8 i;
    uint32 startvalueTemp;
    startvalueTemp = Crc_StartValue32;
    if(Crc_Length != 0)
    {
        if(Crc_IsFirstCall)
        {
            startvalueTemp = 0xFFFFFFFF;
        }
        else
        {
            startvalueTemp ^= 0xFFFFFFFF;
        }
        //while (Crc_Length != 0)
        for(uint32 i = Crc_Length; i != 0; i--)
        {
            startvalueTemp ^= (uint32) *Crc_DataPtr;
            for(i = 0; i < 8; i++)
            {
                if((startvalueTemp & 0x00000001u) != 0u)
                {
                    startvalueTemp = (startvalueTemp >> 1) ^ CRC_CRC32P4_POLYNOMIAL_REFLECTED;
                }
                else
                {
                    startvalueTemp >>= 1;
                }
            }
            Crc_DataPtr++;
            //Crc_Length--;
        }
        startvalueTemp ^= 0xFFFFFFFF;
    }
    return startvalueTemp;
}

uint32 Compute_CRC32_Simple(uint8* bytes, uint32 length) 
{
    const uint32 polynomial = 0x04C11DB7; /* divisor is 32bit */
    uint32 crc = 0; /* CRC value is 32bit */

    for (uint32 byteIndex = 0; byteIndex < length; ++byteIndex) 
    {
        uint8 byte = bytes[byteIndex];
        crc ^= ((uint32)byte << 24); /* move byte into MSB of 32bit CRC */

        for (uint8 bit = 0; bit < 8; ++bit) 
        {
            if (crc & 0x80000000) /* test for MSB = bit 31 */
            {
                crc = (crc << 1) ^ polynomial;
            } 
            else 
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}

uint16 Crc_CalculateCRC16ARC(const uint8* Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall)
{
    const uint16 Crc_Polynomial = 0xA001;
    uint16 crcValue             = Crc_StartValue16;
    uint8 bit;

    if(Crc_Length != 0)
    {
        if( Crc_IsFirstCall )
        {
            crcValue = (uint16) 0x0000; // Cast (uint16)
        }
        // for (uint32 i = Crc_Length; i >= 0; i++)
        for( uint32 i = Crc_Length; i != 0; i-- )
        //while(Crc_Length != 0)
        {
            // crcValue ^= Reflect(Crc_DataPtr[i], 8) << 8;
            crcValue ^= (uint16) *Crc_DataPtr;

            for( bit = 0; bit < 8; bit++ )
            {
                if( ((crcValue) & 0x00001) != 0 ) // Change 0x00001
                {
                    crcValue = ( crcValue >> 1 ) ^ Crc_Polynomial;
                }
                else
                {
                    crcValue >>= 1;
                }
            }
            Crc_DataPtr++;
            //Crc_Length--;
        }
    }
    return crcValue;
}

uint16 Crc_SwCalculateCRC16ARC(const uint8* Crc_DataPtr, uint32 Crc_Length, uint16 Crc_StartValue16, boolean Crc_IsFirstCall)
{
    uint8 i;
    uint16 startValuetemp = Crc_StartValue16;
    
    if(Crc_Length != 0)
    {
        if(Crc_IsFirstCall)
        {
            startValuetemp = (uint16) 0x0000;
        }
        else
        {
            
        }
        while(Crc_Length != 0)
        {
            startValuetemp ^= (uint16) *Crc_DataPtr;
            for(i = 0; i < 8; i++)
            {
                if(((startValuetemp) & 0x00001) != 0)
                {
                    startValuetemp = (startValuetemp >> 1) ^ CRC_CRC16ARC_POLYNOMIAL_REFLECTED;
                }
                else
                {
                    startValuetemp >>= 1;
                }
            }
            Crc_DataPtr++;
            Crc_Length--;
        }
    }
    return startValuetemp;
}

uint64 Crc_CalculateCRC64p7 (const uint8* Crc_DataPtr, uint32 Crc_Length, uint64 Crc_StartValue64, boolean Crc_IsFirstCall)
{
    uint8 i;
    uint64 startvalueTemp;
    startvalueTemp = Crc_StartValue64;
    if(Crc_Length != 0)
    {
        if(Crc_IsFirstCall)
        {
            startvalueTemp = 0xFFFFFFFFFFFFFFFF;
        }
        else
        {
            startvalueTemp ^= 0xFFFFFFFFFFFFFFFF;
        }
        //while (Crc_Length != 0)
        for(uint32 i = Crc_Length; i != 0; i--)
        {
            startvalueTemp ^= (uint64) *Crc_DataPtr;
            for(i = 0; i < 8; i++)
            {
                if((startvalueTemp & 0x0000000000000001UL) != 0u)
                {
                    startvalueTemp = (startvalueTemp >> 1) ^ CRC_CRC64P7_POLYNOMIAL_REFLECTED;
                }
                else
                {
                    startvalueTemp >>= 1;
                }
            }
            Crc_DataPtr++;
            //Crc_Length--;
        }
        startvalueTemp ^= 0xFFFFFFFFFFFFFFFF;
    }
    return startvalueTemp;
}

#endif