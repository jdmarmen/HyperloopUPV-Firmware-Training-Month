#include "ADC.h"

ADC::ADC(ADC_HandleTypeDef *hadc,uint32_t SingleDiff,uint32_t* buffer, uint32_t size):hadc(hadc),
SingleDiff(SingleDiff),buffer(buffer),size(size)
{
	HAL_ADCEx_Calibration_Start(hadc,0,SingleDiff);
}

void ADC::start()
{
	HAL_ADC_Start_DMA(hadc,buffer,size);
}
void ADC::stop()
{
	HAL_ADC_Stop_DMA(hadc);
}
double ADC::read()
{
	double voltage = (double)(buffer[0] * 3.3 )/ 65535.0;  //16bit ADC at 3.3V
	return voltage;
}



