/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_FPGA_code_h__
#define __NiFpga_FPGA_code_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_FPGA_code_Bitfile;
 */
#define NiFpga_FPGA_code_Bitfile "NiFpga_FPGA_code.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_FPGA_code_Signature = "3299193BF9D300D13755D2625BE2F72C";

typedef enum
{
   NiFpga_FPGA_code_IndicatorBool_FIFO_ATimedOut = 0x1800E,
   NiFpga_FPGA_code_IndicatorBool_FIFO_BTimedOut = 0x1800A,
   NiFpga_FPGA_code_IndicatorBool_UserSwitch0 = 0x18032,
   NiFpga_FPGA_code_IndicatorBool_UserSwitch1 = 0x1802E,
   NiFpga_FPGA_code_IndicatorBool_UserSwitch2 = 0x1801A,
   NiFpga_FPGA_code_IndicatorBool_UserSwitch3 = 0x18016,
} NiFpga_FPGA_code_IndicatorBool;

typedef enum
{
   NiFpga_FPGA_code_IndicatorU8_UserSwitch30 = 0x18006,
} NiFpga_FPGA_code_IndicatorU8;

typedef enum
{
   NiFpga_FPGA_code_IndicatorI32_iterations = 0x18010,
} NiFpga_FPGA_code_IndicatorI32;

typedef enum
{
   NiFpga_FPGA_code_ControlBool_UserLED0 = 0x1802A,
   NiFpga_FPGA_code_ControlBool_UserLED1 = 0x18026,
   NiFpga_FPGA_code_ControlBool_UserLED2 = 0x18022,
   NiFpga_FPGA_code_ControlBool_UserLED3 = 0x1801E,
} NiFpga_FPGA_code_ControlBool;

typedef enum
{
   NiFpga_FPGA_code_ControlU32_WaitmSec = 0x18034,
} NiFpga_FPGA_code_ControlU32;

typedef enum
{
   NiFpga_FPGA_code_IndicatorArrayBool_UserSwitch30_array = 0x18002,
} NiFpga_FPGA_code_IndicatorArrayBool;

typedef enum
{
   NiFpga_FPGA_code_IndicatorArrayBoolSize_UserSwitch30_array = 8,
} NiFpga_FPGA_code_IndicatorArrayBoolSize;

typedef enum
{
   NiFpga_FPGA_code_TargetToHostFifoU8_U8_FIFO = 0,
} NiFpga_FPGA_code_TargetToHostFifoU8;

typedef enum
{
   NiFpga_FPGA_code_TargetToHostFifoI16_FIFO_B = 1,
} NiFpga_FPGA_code_TargetToHostFifoI16;

typedef enum
{
   NiFpga_FPGA_code_HostToTargetFifoI16_FIFO_A = 2,
} NiFpga_FPGA_code_HostToTargetFifoI16;

#endif
