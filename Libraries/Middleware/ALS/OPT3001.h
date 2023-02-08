#ifndef __OPT3001_H
#define __OPT3001_H



#define DEFAULT_CONFIG_800    		0xcc10//0b1100110000010000 // 800ms
#define DEFAULT_CONFIG_800_OS 		0b1100101000010000 // 800ms, one shot
#define DEFAULT_CONFIG_100    		0xC410//0b1100 0100 0001 0000 // 100ms
#define DEFAULT_CONFIG_100_OS 		0b1100001000010000 // 100ms, one shot
#define DEFAULT_CONFIG_SHDWN 	 	0xc810 // Shut down converter



#define OPT3001_CFG_FL          (1 << 5)
#define OPT3001_CFG_FH          (1 << 6)
#define OPT3001_CFG_CRF         (1 << 7)
#define OPT3001_CFG_OVF         (1 << 8)
#define OPT3001_CFG_L           (1 << 4)
#define OPT3001_CFG_POL         (1 << 3)
#define OPT3001_CFG_ME          (1 << 2)
#define OPT3001_CFG_CT          (1 << 11)
#define OPT3001_CFG_FC_SHIFT    0
#define OPT3001_CFG_FC_MASK     (0x03 << OPT3001_CFG_FC_SHIFT)
#define OPT3001_CFG_M_SHIFT     9
#define OPT3001_CFG_M_MASK      (0x03 << OPT3001_CFG_M_SHIFT)
#define OPT3001_CFG_RN_SHIFT    12
#define OPT3001_CFG_RN_MASK     (0xf << OPT3001_CFG_RN_SHIFT)


 bool		OPT3001_int(int16_t config);
 void   	OPT3001_shutDown();
 bool   	OPT3001_startConversion();
 //void   startConversion(uint16_t startArg);
 uint32_t    	OPT3001_readResult();
 uint16_t 	OPT3001_readManufacturerId();
 uint16_t 	OPT3001_readDeviceId();
 uint16_t 	OPT3001_readConfigReg();
 uint16_t 	OPT3001_readLowLimitReg();
 uint16_t 	OPT3001_readHighLimitReg();
 uint8_t  	OPT3001_isConversionReady();
 uint8_t 	OPT3001_interruptPin();
 uint8_t 	OPT3001_Test();
 uint8_t GetLightIntensity(float* Intensity);
uint8_t AutoBackLight(float lux);

#endif
