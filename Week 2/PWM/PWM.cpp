#include "PWM.h"

PWM::PWM(TIM_HandleTypeDef *timer,uint32_t channel) : timer(timer), channel(channel)
{
	dutycycle = 5; //initial duty 5%
	duty_percentage = 5.0;
	arr = 99; //initial arr for a 10KHz freq
	__HAL_TIM_SET_COMPARE(timer, channel, dutycycle);
}

void PWM::start()
{
	HAL_TIM_Base_Start_IT(timer);
	HAL_TIM_PWM_Start(timer, channel);
}

void PWM::stop()
{
	HAL_TIM_PWM_Stop(timer, channel);
	HAL_TIM_Base_Stop_IT(timer);
}

void PWM::set_duty_cycle(float duty)
{
	duty_percentage = duty;
	arr = __HAL_TIM_GET_AUTORELOAD(timer);
	dutycycle = (uint32_t)((duty_percentage / 100) * arr);
	__HAL_TIM_SET_COMPARE(timer, channel, dutycycle);
}

void PWM::set_frequency(float freq) //varies the freq depending on the ARR
{
	arr = (uint32_t)freq;
	__HAL_TIM_SET_AUTORELOAD(timer, arr);
	set_duty_cycle(duty_percentage);
}

float PWM::get_duty()
{
	return duty_percentage;
}
