#include "stm32f10x.h"
#include "modbus.h"
#include "GPIO.h"
#include "pwm.h"



unsigned short	array_mb[100]						= {};			// ������ ��� �������� ��������/���������� ����






int main(void)
{


	init_GPIO();
    init_modbus();

    init_pwm();


    relay_1(off);
    relay_2(off);

    blue_led(off);
    red_led(off);





	for(;;)
	{

		set_pwm_R(array_mb[1]);
		set_pwm_G(array_mb[2]);
		set_pwm_B(array_mb[3]);


		array_mb[8]++;								// ������� �������� ��������� �����

		Modbus_slave();

	} // ������ ������������ �����
} // ������ �����
