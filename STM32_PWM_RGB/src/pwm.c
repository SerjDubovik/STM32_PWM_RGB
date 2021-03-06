#include "stm32f10x.h"
#include "pwm.h"




// ���������� ��� PP ������ ���������� (�����������/���������� ���������������)
/*
unsigned short	PWM_1 = 0;									// �������� ��� ������� 1. ��� ������.
unsigned short	PWM_2 = 0;
unsigned short	PWM_3 = 0;
*/

unsigned short TMR_T 			= period;					//	4500 - 16kHz COMPL_MODE		// 360 - 100 kHz PP_MODE
															// ��� PP_MODE:  TMR_T = (72 000 / ����������) / 2
															// 				 �������(���) = 72 000/(TMR_T * 2)


void set_pwm_R(unsigned short pwm)
{
	TIM1->CCR1=pwm;
}

void set_pwm_G(unsigned short pwm)
{
	TIM1->CCR2=pwm;
}

void set_pwm_B(unsigned short pwm)
{
	TIM1->CCR3=pwm;
}




void init_pwm(void)
{

	init_timer3();

	RCC->APB2ENR|= RCC_APB2ENR_TIM1EN;

    TIM1->CCMR1=TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE;
    TIM1->CCMR2=TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE;


    TIM1->CCER=TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E;	// ���������� ���������������� ������.
    TIM1->BDTR=TIM_BDTR_MOE | DEADTIME;

    TIM1->ARR=TMR_T;				// ������� �������������� ������������
    TIM1->CR1=TIM_CR1_ARPE;			// ��������� ���������������� ����� ������ � ������� ������������
    TIM1->CR1|=TIM_CR1_CEN;			// ��������� ������ ��������
    TIM1->EGR=TIM_EGR_UG;			// ������� ��������� �������. ��������� ������������

}




void init_timer3(void)						// ��������� ������� 3. ����� ��� �������� ��������
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->CR1 |= TIM_CR1_ARPE; 				//shadow
	TIM3->CR1 |= TIM_CR1_DIR;

	TIM3->PSC = 71;							// 72MHz/(PSC+1)	���� ���  - 1 ���
	TIM3->ARR = 25;							// 1000 - 1 ��
											// 50 - 55,55 ��
											// 25 - 111,111 ��

	TIM3->DIER |= TIM_DIER_UIE;
	TIM3->CR1 |= TIM_CR1_CEN;

	NVIC_EnableIRQ (TIM3_IRQn);
}



void TIM3_IRQHandler (void)									// ���������� ������� ��� ������� ������� ������� ������
{
	unsigned short status;
	status = TIM3->SR;
	TIM3->SR = ~status;

	if(status & TIM_SR_UIF)
	{

	}
} // ������ TIM2_IRQHandler





