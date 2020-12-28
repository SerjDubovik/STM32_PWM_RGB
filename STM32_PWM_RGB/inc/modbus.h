#ifndef SRC_MODBUS
#define SRC_MODBUS

#define adrr_devise 					81 // 2				// адрес этого устройства в сети модбас
#define leth_array						100					// длинна массива для принятых/отправленых данных. служит для проверки возможности записи по адресу






	unsigned short CRC16(int *puchMsg,unsigned short usDataLen );
	extern void USART2_IRQHandler(void);
	void Modbus_slave(void);
	void init_modbus(void);
	void init_timer2(void);
	void TIM2_IRQHandler (void);


	/*
	 *  Адресное пространство и что за что отвечает:
	 *
	 *  Адрес 			Описание
	 *
	 *  0				резерв
	 *  1				R - канал
	 *  2				G - канал
	 *  3				B - канал
	 */






#endif // SRC_MODBUS
