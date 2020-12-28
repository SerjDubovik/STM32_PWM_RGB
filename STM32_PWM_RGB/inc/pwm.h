#ifndef SRC_PWM
#define SRC_PWM


#define period              	4500	//	4500 - 16kHz COMPL_MODE		// 360 - 100 kHz PP_MODE
#define DEADTIME            	20

void set_pwm_R(unsigned short pwm);
void set_pwm_G(unsigned short pwm);
void set_pwm_B(unsigned short pwm);

void init_pwm(void);
void init_timer3(void);
void TIM3_IRQHandler(void);


#endif // SRC_PWM
