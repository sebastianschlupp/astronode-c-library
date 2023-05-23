#ifndef ASTRONODE_DEFINITIONS_H
#define ASTRONODE_DEFINITIONS_H

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
// Standard
#include <stdint.h>


//------------------------------------------------------------------------------
// Definitions
//------------------------------------------------------------------------------
#define ASTRONODE_TRANSPORT_BLOCKING_MODE
#define ASTRONODE_TRANSPORT_ASYNC_MODE

#define ASTRONODE_TRANSPORT_STX 0x02
#define ASTRONODE_TRANSPORT_ETX 0x03

#define ASTRONODE_WLAN_SSID_MAX_LENGTH  33
#define ASTRONODE_WLAN_KEY_MAX_LENGTH   64
#define ASTRONODE_AUTH_TOKEN_MAX_LENGTH 97

#define ASTRONODE_MAX_LENGTH_RESPONSE 178

#define ASTRONODE_ANSWER_TIMEOUT_MS 1500

#define ASTRONODE_APP_MSG_MAX_LEN_BYTES     194 // Wi-Fi write is 194 bytes
#define ASTRONODE_APP_PAYLOAD_MAX_LEN_BYTES 160 // 152 if geolocation is used


//------------------------------------------------------------------------------
// Type definitions
//------------------------------------------------------------------------------
typedef enum as_return_status_t
{
    RS_ASSET_SUCCESS = 0U,  /*!< Operation succeed */
    RS_ASSET_CRC_ERROR,     /*!< CRC error on Astronode answer */
    RS_ASSET_BUSY,          /*!< Waiting for Astronode answer */
    RS_ASSET_TIMEOUT,       /*!< Astronode did not answer before timeout */
    RS_ASSET_FAILURE,       /*!< Failure in communication with the Astronode */
    RS_ASTRONODE_FAILURE,   /*!< Astronode answers an error (0xFF opcode) */
} as_return_status_t;

typedef enum astronode_op_code
{
    ASTRONODE_OP_CODE_CFG_FA = 0x91,
    ASTRONODE_OP_CODE_CFG_FR = 0x11,
    ASTRONODE_OP_CODE_CFG_RA = 0x95,
    ASTRONODE_OP_CODE_CFG_RR = 0x15,
    ASTRONODE_OP_CODE_CFG_SA = 0x90,
    ASTRONODE_OP_CODE_CFG_SR = 0x10,
    ASTRONODE_OP_CODE_CFG_WA = 0x85,
    ASTRONODE_OP_CODE_CFG_WR = 0x05,
    ASTRONODE_OP_CODE_CTX_SA = 0xe6,
    ASTRONODE_OP_CODE_CTX_SR = 0x66,
    ASTRONODE_OP_CODE_END_RA = 0xeb,
    ASTRONODE_OP_CODE_END_RR = 0x6b,
    ASTRONODE_OP_CODE_NCO_RA = 0x98,
    ASTRONODE_OP_CODE_NCO_RR = 0x18,
    ASTRONODE_OP_CODE_ERROR  = 0xff,
    ASTRONODE_OP_CODE_EVT_RA = 0xe5,
    ASTRONODE_OP_CODE_EVT_RR = 0x65,
    ASTRONODE_OP_CODE_GEO_WA = 0xb5,
    ASTRONODE_OP_CODE_GEO_WR = 0x35,
    ASTRONODE_OP_CODE_GPI_RA = 0xe3,
    ASTRONODE_OP_CODE_GPI_RR = 0x63,
    ASTRONODE_OP_CODE_GPO_SA = 0xe2,
    ASTRONODE_OP_CODE_GPO_SR = 0x62,
    ASTRONODE_OP_CODE_LCD_RA = 0xea,
    ASTRONODE_OP_CODE_LCD_RR = 0x6a,
    ASTRONODE_OP_CODE_MPN_RA = 0x9b,
    ASTRONODE_OP_CODE_MPN_RR = 0x1b,
    ASTRONODE_OP_CODE_MGI_RA = 0x99,
    ASTRONODE_OP_CODE_MGI_RR = 0x19,
    ASTRONODE_OP_CODE_MSN_RA = 0x9a,
    ASTRONODE_OP_CODE_MSN_RR = 0x1a,
    ASTRONODE_OP_CODE_MST_RA = 0xe9,
    ASTRONODE_OP_CODE_MST_RR = 0x69,
    ASTRONODE_OP_CODE_PER_CA = 0xe8,
    ASTRONODE_OP_CODE_PER_CR = 0x68,
    ASTRONODE_OP_CODE_PER_RA = 0xe7,
    ASTRONODE_OP_CODE_PER_RR = 0x67,
    ASTRONODE_OP_CODE_PLD_DA = 0xa6,
    ASTRONODE_OP_CODE_PLD_DR = 0x26,
    ASTRONODE_OP_CODE_PLD_EA = 0xa5,
    ASTRONODE_OP_CODE_PLD_ER = 0x25,
    ASTRONODE_OP_CODE_PLD_FA = 0xa7,
    ASTRONODE_OP_CODE_PLD_FR = 0x27,
    ASTRONODE_OP_CODE_RES_CA = 0xd5,
    ASTRONODE_OP_CODE_RES_CR = 0x55,
    ASTRONODE_OP_CODE_RTC_RA = 0x97,
    ASTRONODE_OP_CODE_RTC_RR = 0x17,
    ASTRONODE_OP_CODE_SAK_CA = 0xc6,
    ASTRONODE_OP_CODE_SAK_CR = 0x46,
    ASTRONODE_OP_CODE_SAK_RA = 0xc5,
    ASTRONODE_OP_CODE_SAK_RR = 0x45,
    ASTRONODE_OP_CODE_SSC_WA = 0x87,
    ASTRONODE_OP_CODE_SSC_WR = 0x07,
    ASTRONODE_OP_CODE_WIF_WA = 0x86,
    ASTRONODE_OP_CODE_WIF_WR = 0x06,
    ASTRONODE_OP_CODE_CMD_CA = 0xc8,
    ASTRONODE_OP_CODE_CMD_CR = 0x48,
    ASTRONODE_OP_CODE_CMD_RA = 0xc7,
    ASTRONODE_OP_CODE_CMD_RR = 0x47,
} astronode_op_code;

typedef enum astronode_error_code
{
    ASTRONODE_ERR_CODE_CRC_NOT_VALID        = 0x0001,
    ASTRONODE_ERR_CODE_LENGTH_NOT_VALID     = 0x0011,
    ASTRONODE_ERR_CODE_OPCODE_NOT_VALID     = 0x0121,
    ASTRONODE_ERR_CODE_FORMAT_NOT_VALID     = 0x0601,
    ASTRONODE_ERR_CODE_FLASH_WRITING_FAILED = 0x0611,
    ASTRONODE_ERR_CODE_BUFFER_FULL          = 0x2501,
    ASTRONODE_ERR_CODE_DUPLICATE_ID         = 0x2511,
    ASTRONODE_ERR_CODE_BUFFER_EMPTY         = 0x2601,
    ASTRONODE_ERR_CODE_INVALID_POS          = 0x3501,
    ASTRONODE_ERR_CODE_NO_ACK               = 0x4501,
    ASTRONODE_ERR_CODE_NO_CLEAR             = 0x4601
} astronode_error_code;

typedef struct astronode_app_msg_t
{
    astronode_op_code   op_code;
    char                p_payload[ASTRONODE_APP_MSG_MAX_LEN_BYTES];
    uint16_t            payload_len;
} astronode_app_msg_t;

#endif /* ASTRONODE_DEFINITIONS_H */