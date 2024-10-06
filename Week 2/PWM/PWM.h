#pragma once

#include "main.h"
#include "string.h"

class PWM
{
	private:

		TIM_HandleTypeDef *timer;
		uint32_t channel;
		uint32_t dutycycle;
		float duty_percentage;
		uint32_t arr;

	public:

		PWM(TIM_HandleTypeDef *timer,uint32_t channel);

		void start();
		void stop();
		void set_duty_cycle(float duty);
		void set_frequency(float freq); //varies the freq depending on the ARR
		float get_duty();
};
