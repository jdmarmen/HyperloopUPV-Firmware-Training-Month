#pragma once
#include "main.h"
#include "string.h"


class ADC
{
	private:

	ADC_HandleTypeDef *hadc;
	uint32_t SingleDiff;
	uint32_t* buffer;
	uint32_t size;


	public:

	ADC(ADC_HandleTypeDef *hadc,uint32_t SingleDiff,uint32_t* buffer, uint32_t size);
	void start();
	void stop();
	double read();

};
