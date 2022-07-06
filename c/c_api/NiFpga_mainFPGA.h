/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_mainFPGA_h__
#define __NiFpga_mainFPGA_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_mainFPGA_Bitfile;
 */
#define NiFpga_mainFPGA_Bitfile "NiFpga_mainFPGA.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_mainFPGA_Signature = "E941780C7E1DB0244EDFBE6EA01FD01F";

typedef enum
{
   NiFpga_mainFPGA_IndicatorBool_FIFO_ATimedOut = 0x18006,
   NiFpga_mainFPGA_IndicatorBool_FIFO_BTimedOut = 0x18002,
   NiFpga_mainFPGA_IndicatorBool_UserSwitch0 = 0x1802A,
   NiFpga_mainFPGA_IndicatorBool_UserSwitch1 = 0x18026,
   NiFpga_mainFPGA_IndicatorBool_UserSwitch2 = 0x18012,
   NiFpga_mainFPGA_IndicatorBool_UserSwitch3 = 0x1800E,
} NiFpga_mainFPGA_IndicatorBool;

typedef enum
{
   NiFpga_mainFPGA_IndicatorU8_UserSwitch30 = 0x18032,
} NiFpga_mainFPGA_IndicatorU8;

typedef enum
{
   NiFpga_mainFPGA_IndicatorI32_iterations_fifo_AB = 0x18034,
   NiFpga_mainFPGA_IndicatorI32_iterations_loop_switches = 0x18008,
   NiFpga_mainFPGA_IndicatorI32_iterations_u8fifo = 0x18038,
} NiFpga_mainFPGA_IndicatorI32;

typedef enum
{
   NiFpga_mainFPGA_ControlBool_UserLED0 = 0x18022,
   NiFpga_mainFPGA_ControlBool_UserLED1 = 0x1801E,
   NiFpga_mainFPGA_ControlBool_UserLED2 = 0x1801A,
   NiFpga_mainFPGA_ControlBool_UserLED3 = 0x18016,
} NiFpga_mainFPGA_ControlBool;

typedef enum
{
   NiFpga_mainFPGA_ControlU32_WaitmSec = 0x1802C,
} NiFpga_mainFPGA_ControlU32;

typedef enum
{
   NiFpga_mainFPGA_IndicatorArrayBool_UserSwitches30 = 0x1803E,
} NiFpga_mainFPGA_IndicatorArrayBool;

typedef enum
{
   NiFpga_mainFPGA_IndicatorArrayBoolSize_UserSwitches30 = 8,
} NiFpga_mainFPGA_IndicatorArrayBoolSize;

typedef enum
{
   NiFpga_mainFPGA_TargetToHostFifoU8_U8_FIFO = 0,
} NiFpga_mainFPGA_TargetToHostFifoU8;

typedef enum
{
   NiFpga_mainFPGA_TargetToHostFifoI16_FIFO_B = 1,
} NiFpga_mainFPGA_TargetToHostFifoI16;

typedef enum
{
   NiFpga_mainFPGA_HostToTargetFifoI16_FIFO_A = 2,
} NiFpga_mainFPGA_HostToTargetFifoI16;

#endif
