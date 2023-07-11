#ifndef STD_TYPES_H__
#define STD_TYPES_H__

#include "Platform_Types.h"

/**
 * @brief  This type can be used as standard API return type which is shared between the RTE
 *         and the BSW modules. range: E_OK and E_NOT_OK
 *
 * @reqs   SWS_Std_00005
 */
typedef uint8 Std_ReturnType;

/**
 * @brief  This type shall be used to request the version of a BSW module using the <Module name>_Get
 * VersionInfo() function.
 *
 * @reqs   SWS_Std_00015
 */
typedef struct 
{
    uint16 vendorID;
    uint16 moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
}Std_VersionInfoType;


/**
 * @brief  The specific meaning of the values of Std_TransformerErrorCode is to 
 * be seen for the specific transformer chain for which the data type 
 * represents the transformer error.
 *
 * @reqs   SWS_Std_00022
 */
typedef uint8 Std_TransformerErrorCode;


/**
 * @brief  This type is used to encode the different type of messages. - Currently this encoding is limited to 
 * the distinction between requests and responses in C/S communication.
 *
 * @reqs   SWS_Std_91001
 */
typedef enum
{
    STD_TRANSFORMER_UNSPECIFIED = 0x00,
    STD_TRANSFORMER_SERIALIZER = 0x01,
    STD_TRANSFORMER_SAFETY = 0x02,
    STD_TRANSFORMER_SECURITY = 0x03,
    STD_TRANSFORMER_CUSTOM = 0x04
}Std_TransformerClass;

/**
 * @brief  The data type Std_TransformerError is a struct which contains the error code and the 
 * transformer class to which the error belongs.
 *
 * @reqs   SWS_Std_00021
 */
typedef struct 
{
    Std_TransformerErrorCode errorCode;
    Std_TransformerClass    transformerClass;
} Std_TransformerError;


/**
 * @brief  This type is used to encode different types of results for response messages. - Currently this
 * encoding is limited to the distinction between OK and ERROR responses.
 *
 * @reqs   SWS_Std_91002
 */
typedef enum
{
    STD_MESSAGERESULT_OK = 0x00,
    STD_MESSAGERESULT_ERROR = 0x01
}Std_MessageResultType;

typedef enum
{
    STD_MESSAGETYPE_REQUEST = 0x00,
    STD_MESSAGETYPE_RESPONSE = 0x01
}Std_MessageTypeType;

/**
 * @brief  Type for the function pointer to extract the relevant protocol header fields of the message and 
 * the type of the message result of a transformer. - At the time being, this is limited to the types 
 * used for C/S communication (i.e., REQUEST and RESPONSE and OK and ERROR).
 *
 * @reqs   SWS_Std_91003
 */
typedef Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType) 
(const uint8* buffer,
uint32 bufferLength,
Std_MessageTypeType* messageType,
Std_MessageResultType* messageResult);

/**
 * @brief  The implementation shall provide the NULL_PTR define with a void pointer to zero 
 * definition.
 *
 * @reqs   SWS_Std_00031
 */
//typedef void* NULL_PTR;
#define NULL_PTR ((void *)0)

/**
 * @name    E_OK, E_NOT_OK
 * @reqs    SWS_Std_00006
 *
 * Because E_OK is already defined within OSEK, the symbol E_OK has to be shared. To avoid 
 * name clashes and redefinition problems.
 */
/**@{*/
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u
typedef unsigned char StatusType; /* OSEK compliance */
#endif
#define E_NOT_OK 0x01u
/**@}*/

/**
 * @name    STD_ACTIVE, STD_IDLE
 * @reqs    SWS_Std_00007
 *
 * Symbols to specify the physical state.
 */
/**@{*/
#define STD_HIGH 0x01u /* Physical state 5V or 3.3V */
#define STD_LOW 0x00u /* Physical state 0V */
/**@}*/

/**
 * @name    STD_ACTIVE, STD_IDLE
 * @reqs    SWS_Std_00013
 *
 * Symbols to specify the logical state.
 */
/**@{*/
#define STD_ACTIVE 0x01u /* Logical state active */
#define STD_IDLE 0x00u /* Logical state idle */
/**@}*/

/**
 * @name    STD_ON, STD_OFF
 * @reqs    SWS_Std_00010
 *
 * Symbols to specify the logical state.
 */
/**@{*/
#define STD_ON 0x01u
#define STD_OFF 0x00u
/**@}*/

#endif /* STD_TYPES_H */