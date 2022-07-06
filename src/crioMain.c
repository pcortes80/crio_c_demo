/* DEMO to understand how to use the C API Generator
   to communicate RT Processor and FPGA.
   Target: cRIO-9033 Module NI-9344 on Slot1
*/

// System headers
#include <stdio.h>
#include <stdlib.h>

// Project headers
#include "../include/NiFpga_mainFPGA.h"

int main(){

    // Initialize the FPGA interface 
    NiFpga_Status status = NiFpga_Initialize();
    if (NiFpga_IsNotError(status)) {
        NiFpga_Session session;
        // string bitfile = NiFpga_mainFPGA_Bitfile;
        // Open a session and download the bitstream
        NiFpga_MergeStatus(&status,
                           NiFpga_Open(NiFpga_mainFPGA_Bitfile,
                           NiFpga_mainFPGA_Signature,
                           "RIO0",
                           NiFpga_OpenAttribute_NoRun, &session));
 
        if (NiFpga_IsNotError(status)) {
            // Run the FPGA VI on the target
            NiFpga_MergeStatus(&status, NiFpga_Run(session, 0));

            /* Reset UserLED0 */
            NiFpga_MergeStatus(&status, NiFpga_WriteBool(session, NiFpga_mainFPGA_ControlBool_UserLED0,0));
            sleep(2);

            // UserSwitches Initialization
            NiFpga_Bool userSw0 = 0;
            NiFpga_Bool userSw1 = 0;
            NiFpga_Bool userSw2 = 0;
            NiFpga_Bool userSw3 = 0;

            const int SIZE = 256; /// size of FIFOs
            uint8_t inputSwitches[SIZE]; /// input form FPGA switches
            int16_t output[SIZE]; /// output to FPGA FIFO_A
            int16_t input[SIZE];  /// input from FPGA FIFO_B

            /* LEDO = on */
            NiFpga_MergeStatus(&status, NiFpga_WriteBool(session, NiFpga_mainFPGA_ControlBool_UserLED0,1));

            int x = 0;
            while (x < 10)
            {
                // Read UserSwitches
                NiFpga_MergeStatus(&status, NiFpga_ReadBool(session, NiFpga_mainFPGA_IndicatorBool_UserSwitch0,&userSw0));
                //NiFpga_MergeStatus(&status, NiFpga_ReadBool(session, NiFpga_mainFPGA_IndicatorBool_UserSwitch1,&userSw1));
                //NiFpga_MergeStatus(&status, NiFpga_ReadBool(session, NiFpga_mainFPGA_IndicatorBool_UserSwitch2,&userSw2));
                //NiFpga_MergeStatus(&status, NiFpga_ReadBool(session, NiFpga_mainFPGA_IndicatorBool_UserSwitch3,&userSw3));   
            
                //cout << "userSw0=" << ((userSw0) ? "t" : "f") << " " << hex << (int)userSw0;
                printf("iteration = %d\t userSw0 = %d\n",x, (int)userSw0);

                x++;
                sleep(1);
                                                   
            }
            /* LEDO = off */
            NiFpga_MergeStatus(&status, NiFpga_WriteBool(session, NiFpga_mainFPGA_ControlBool_UserLED0,0));

            // Close the session to the FPGA VI
            NiFpga_MergeStatus(&status, NiFpga_Close(session, 0));
        }
        
        // Close the FPGA interface.
        NiFpga_MergeStatus(&status, NiFpga_Finalize());
    }    
     
    // check if anything went wrong
    if (NiFpga_IsError(status)){
        printf("Error\n");
        printf("Press <Enter> to quit...\n");
        getchar();
    }
    return status;
}
