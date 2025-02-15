// MAX3420E_BF1.h
// Macros
// See the single bug fix below.
//
// For active-high lights attached to MAX3420E GP-Output pins.
/*#define L0_OFF wreg(rGPIO,(rreg(rGPIO) & 0xFE));
#define L0_ON wreg(rGPIO,(rreg(rGPIO) | 0x01));
#define L1_OFF wreg(rGPIO,(rreg(rGPIO) & 0xFD));
#define L1_ON wreg(rGPIO,(rreg(rGPIO) | 0x02));
#define L2_OFF wreg(rGPIO,(rreg(rGPIO) & 0xFB));
#define L2_ON wreg(rGPIO,(rreg(rGPIO) | 0x04));
#define L3_OFF wreg(rGPIO,(rreg(rGPIO) & 0xF7));
#define L3_ON wreg(rGPIO,(rreg(rGPIO) | 0x08));
#define L0_BLINK wreg(rGPIO,(rreg(rGPIO) ^ 0x01));
#define L1_BLINK wreg(rGPIO,(rreg(rGPIO) ^ 0x02));
#define L2_BLINK wreg(rGPIO,(rreg(rGPIO) ^ 0x04));
#define L3_BLINK wreg(rGPIO,(rreg(rGPIO) ^ 0x08));
*/
#define SETBIT(reg,val) wreg(reg,(rreg(reg)|val));
#define CLRBIT(reg,val) wreg(reg,(rreg(reg)&~val));

// ************ BUG FIX ************
//#define STALL_EP0 wreg(9,0x23); // Set all three EP0 stall bits--data stage IN/OUT and status stage
// BUG FIX 2-9-06. The above statement hard-codes the register number to 9, ignoring the fact that
// the wreg function expects the register numbers to be pre-shifted 3 bits to put them into the 5 MSB's of
// the SPI command byte. Here is the correction:

#define STALL_EP0 wreg(rEPSTALLS,0x23);	// Set all three EP0 stall bits--data stage IN/OUT and status stage

// ******** END OF BUG FIX**********

#define MSB(word) (BYTE)(((WORD)(word) >> 8) & 0xff)
#define LSB(word) (BYTE)((WORD)(word) & 0xff)

// MAX3420E Registers
#define rEP0FIFO    0<<3
#define rEP1OUTFIFO 1<<3
#define rEP2INFIFO  2<<3
#define rEP3INFIFO  3<<3
#define rSUDFIFO    4<<3
#define rEP0BC      5<<3
#define rEP1OUTBC   6<<3
#define rEP2INBC    7<<3
#define rEP3INBC    8<<3
#define rEPSTALLS   9<<3
#define rCLRTOGS    10<<3
#define rEPIRQ      11<<3
#define rEPIEN      12<<3
#define rUSBIRQ     13<<3
#define rUSBIEN     14<<3
#define rUSBCTL     15<<3
#define rCPUCTL     16<<3
#define rPINCTL     17<<3
#define rRevision   18<<3
#define rFNADDR     19<<3
#define rGPIO       20<<3

// MAX3420E bit masks for register bits
// R9 EPSTALLS Register
#define bmACKSTAT   0x40
#define bmSTLSTAT   0x20
#define bmSTLEP3IN  0x10
#define bmSTLEP2IN  0x08
#define bmSTLEP1OUT 0x04
#define bmSTLEP0OUT 0x02
#define bmSTLEP0IN  0x01

// R10 CLRTOGS Register
#define bmEP3DISAB  0x80
#define bmEP2DISAB  0x40
#define bmEP1DISAB  0x20
#define bmCTGEP3IN  0x10
#define bmCTGEP2IN  0x08
#define bmCTGEP1OUT 0x04

// R11 EPIRQ register bits
#define bmSUDAVIRQ  0x20
#define bmIN3BAVIRQ 0x10
#define bmIN2BAVIRQ 0x08
#define bmOUT1DAVIRQ 0x04
#define bmOUT0DAVIRQ 0x02
#define bmIN0BAVIRQ 0x01

// R12 EPIEN register bits
#define bmSUDAVIE   0x20
#define bmIN3BAVIE  0x10
#define bmIN2BAVIE  0x08
#define bmOUT1DAVIE 0x04
#define bmOUT0DAVIE 0x02
#define bmIN0BAVIE  0x01

// R13 USBIRQ register bits
#define bmURESDNIRQ 0x80
#define bmVBUSIRQ   0x40
#define bmNOVBUSIRQ 0x20
#define bmSUSPIRQ   0x10
#define bmURESIRQ   0x08
#define bmBUSACTIRQ 0x04
#define bmRWUDNIRQ  0x02
#define bmOSCOKIRQ  0x01

// R14 USBIEN register bits
#define bmURESDNIE  0x80
#define bmVBUSIE    0x40
#define bmNOVBUSIE  0x20
#define bmSUSPIE    0x10
#define bmURESIE    0x08
#define bmBUSACTIE  0x04
#define bmRWUDNIE   0x02
#define bmOSCOKIE   0x01

// R15 USBCTL Register
#define bmHOSCSTEN  0x80
#define bmVBGATE    0x40
#define bmCHIPRES   0x20
#define bmPWRDOWN   0x10
#define bmCONNECT   0x08
#define bmSIGRWU    0x04

// R16 CPUCTL Register
#define bmIE        0x01

// R17 PINCTL Register
#define bmFDUPSPI   0x10
#define bmINTLEVEL  0x08
#define bmPOSINT    0x04
#define bmGPOB      0x02
#define	bmGPOA      0x01

//
// GPX[B:A] settings (PINCTL register)
#define gpxOPERATE  0x00
#define gpxVBDETECT 0x01
#define gpxBUSACT   0x02
#define gpxSOF      0x03

// ************************
// Standard USB Requests
#define SR_GET_STATUS		0x00	// Get Status
#define SR_CLEAR_FEATURE	0x01	// Clear Feature
#define SR_RESERVED		0x02	// Reserved
#define SR_SET_FEATURE		0x03	// Set Feature
#define SR_SET_ADDRESS		0x05	// Set Address
#define SR_GET_DESCRIPTOR	0x06	// Get Descriptor
#define SR_SET_DESCRIPTOR	0x07	// Set Descriptor
#define SR_GET_CONFIGURATION	0x08	// Get Configuration
#define SR_SET_CONFIGURATION	0x09	// Set Configuration
#define SR_GET_INTERFACE	0x0a	// Get Interface
#define SR_SET_INTERFACE	0x0b	// Set Interface

// Get Descriptor codes	
#define GD_DEVICE		0x01	// Get device descriptor: Device
#define GD_CONFIGURATION	0x02	// Get device descriptor: Configuration
#define GD_STRING		0x03	// Get device descriptor: String
#define GD_HID	            	0x21	// Get descriptor: HID
#define GD_CDC		0x0a
#define GD_REPORT	        0x22	// Get descriptor: Report

// SETUP packet offsets
#define bmRequestType           0
#define	bRequest		1
#define wValueL			2
#define wValueH			3
#define wIndexL			4
#define wIndexH			5
#define wLengthL		6
#define wLengthH		7

// HID bRequest values
#define GET_REPORT		1
#define GET_IDLE		2
#define GET_PROTOCOL            3
#define SET_REPORT		9
#define SET_IDLE		0x0A
#define SET_PROTOCOL            0x0B
#define INPUT_REPORT            1

