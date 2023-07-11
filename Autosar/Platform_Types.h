#ifndef PLATFORM_TYPES_H__
#define PLATFORM_TYPES_H__

/**
 * @name    unsigned
 * @reqs    SWS_Platform_00013, SWS_Platform_00014, SWS_Platform_00015
 *
 * Cross platform type definitions to declare max or min ranges of unsigned 8, 16, 32 and 62 values
 */
/**@{*/
typedef unsigned char uint8;   /*!< standar type to declare max or min ranges for an unsigned
                                        one byte variable */
typedef unsigned short uint16; /*!< standar type to declare max or min ranges for an unsigned
                                        two byte variable */
typedef unsigned long uint32;  /*!< standar type to declare max or min ranges for an unsigned
                                        four byte variable */
typedef unsigned long uint64;  /*!< standar type to declare max or min ranges for an unsigned
                                        four byte variable */
/**@}*/

/**
 * @name    signed
 * @reqs    SWS_Platform_00016, SWS_Platform_00017, SWS_Platform_00018
 *
 * Cross platform type definitions to declare max or min ranges of signed 8, 16, 32 and 62 values
 */
/**@{*/
typedef signed char sint8;    /*!< standar type to declare max or min ranges for a signed
                                        one byte variable */
typedef signed short sint16;  /*!< standar type to declare max or min ranges for a signed
                                        two byte variable */
typedef signed long sint32;   /*!< standar type to declare max or min ranges for a signed
                                        four byte variable */
typedef signed long sint64;   /*!< standar type to declare max or min ranges for a signed
                                        four byte variable */
/**@}*/

/**
 * @name    unsigned_least
 * @reqs    SWS_Platform_00020, SWS_Platform_00021, SWS_Platform_00022
 *
 * Cross platform type definitions to declare max or min ranges of unsigned 8, 16, 32 and 62 values
 */
/**@{*/
typedef unsigned char uint8_least;   /*!< standar type to declare max or min ranges for an unsigned
                                        one byte variable */
typedef unsigned short uint16_least; /*!< standar type to declare max or min ranges for an unsigned
                                        two byte variable */
typedef unsigned long uint32_least;  /*!< standar type to declare max or min ranges for an unsigned
                                        four byte variable */
typedef unsigned long uint64_least;  /*!< standar type to declare max or min ranges for an unsigned
                                        four byte variable */
/**@}*/

/**
 * @name    signed_least
 * @reqs    SWS_Platform_00023, SWS_Platform_00024, SWS_Platform_00025
 *
 * Cross platform type definitions to declare max or min ranges of signed 8, 16, 32 and 62 values
 */
/**@{*/
typedef signed char sint8_least;    /*!< standar type to declare max or min ranges for a signed
                                        one byte variable */
typedef signed short sint16_least;  /*!< standar type to declare max or min ranges for a signed
                                        two byte variable */
typedef signed long sint32_least;   /*!< standar type to declare max or min ranges for a signed
                                        four byte variable */
typedef signed long sint64_least;   /*!< standar type to declare max or min ranges for a signed
                                        four byte variable */
/**@}*/



/**
 * @name    CPU_BIT_ORDER
 * @reqs    SWS_Platform_00038
 *
 * Symbols to specify the bit order according to the CPU endianess, LSB for little endian and MSB
 * for big endian
 */
/**@{*/
#define MSB_FIRST       1 /*!< CPU with most significant bit aranged first */
#define LSB_FIRST       0 /*!< CPU with least significant bit aranged first */
#define CPU_BIT_ORDER   MSB_FIRST 
/**@}*/

/**
 * @name    CPU_TYPE
 * @reqs    SWS_Platform_00064
 *
 * Symbols to specify the bit order according to the CPU endianess, LSB for little endian and MSB
 * for big endian
 */
/**@{*/
#define CPU_TYPE_8       8 /*!< Indicating a 8 bit processor */
#define CPU_TYPE_16       16 /*!< Indicating a 16 bit processor */
#define CPU_TYPE_32       32 /*!< Indicating a 32 bit processor */
#define CPU_TYPE_64       64 /*!< Indicating a 64 bit processor */
#define CPU_TYPE          CPU_TYPE_32 /*!< Type of processor */
/**@}*/

/**
 * @name     CPU_BYTE_ORDER
 * @reqs    SWS_Platform_00039
 *
 * Symbols to specify the bit order according to the CPU endianess, LSB for little endian and MSB
 * for big endian
 */
/**@{*/
#define HIGH_BYTE_FIRST         1 /*!< High byte is located before the low byte */
#define LOW_BYTE_FIRST          0 /*!< The low byte is located before the high byte */
#define CPU_BYTE_ORDER          HIGH_BYTE_FIRST
/**@}*/

/**
 * @name     TRUE_FALSE
 * @reqs    SWS_Platform_00056
 *
 * TRUE and FALSE symbols
 */
/**@{*/
#ifdef TRUE
#define TRUE       0x01 /*!< True Symbol */
#endif

#ifdef FALSE
#define FALSE       0x00 /*!< False Symbol */
#endif
/**@}*/

#endif