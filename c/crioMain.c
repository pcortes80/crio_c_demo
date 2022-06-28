/* DEMO to understand how to use the C API Generator
   to communicate RT Processor and FPGA.
*/

// Project headers
#include "NiFpga_FPGA_code.h"

// Call a session function to open an FPGA session
NiFpga_Status status = NiFpga_Initialize();
    if (NiFpga_IsNotError(status)) {
        NiFpga_Session session;
        string bitfile = NiFpga_FPGA_code_Bitfile;
        NiFpga_MergeStatus(&status,
                           NiFpga_Open(bitfile.c_str(),
                           NiFpga_FPGA_code>_Signature,
                           "RIO0",
                           NiFpga_OpenAttribute_NoRun, &session));
 
        if (NiFpga_IsNotError(status)) {
            // run the FPGA application
            NiFpga_MergeStatus(&status, NiFpga_Run(session, 0));

            // UserSwitches Initialization
            NiFpga_Bool userSw0 = 0;
            NiFpga_Bool userSw1 = 0;
            NiFpga_Bool userSw2 = 0;
            NiFpga_Bool userSw3 = 0;

            const int SIZE = 256; /// size of FIFOs
            uint8_t inputSwitches[SIZE]; /// input form FPGA switches
            int16_t output[SIZE] = {0}; /// output to FPGA FIFO_A
            int16_t input[SIZE];  /// input from FPGA FIFO_B

            while (1)
            {
                // Read UserSwitches
                NiFpga_MergeStatus(&status, NiFpga_ReadBool(session, NiFpga_FPGA_code_IndicatorBool_UserSwitch0,&userSw0));
                NiFpga_MergeStatus(&status, NiFpga_ReadBool(session, NiFpga_FPGA_code_IndicatorBool_UserSwitch1,&userSw1));
                NiFpga_MergeStatus(&status, NiFpga_ReadBool(session, NiFpga_FPGA_code_IndicatorBool_UserSwitch2,&userSw2));
                NiFpga_MergeStatus(&status, NiFpga_ReadBool(session, NiFpga_FPGA_code_IndicatorBool_UserSwitch3,&userSw3));   
            
                //cout << "userSw0=" << ((userSw0) ? "t" : "f") << " " << hex << (int)userSw0;
                printf("userSw0=%d",(int)userSw0);
  
            
            
            
            }
            
        }
        // must be called after all other calls
        NiFpga_MergeStatus(&status, NiFpga_Finalize());
    }    
    // check if anything went wrong
    if (NiFpga_IsError(status)){
        // ****************
        // Handle the error
        // ****************
    }
    return status;
