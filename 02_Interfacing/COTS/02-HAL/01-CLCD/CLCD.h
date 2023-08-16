#ifndef CLCD_H_
#define CLCD_H_

#define CLCD_DATA_PORT    DIO_PORTA
#define CLCD_CTRL_PORT    DIO_PORTC

#define CLCD_RS_PIN       DIO_PIN0
#define CLCD_RW_PIN       DIO_PIN1
#define CLCD_E_PIN        DIO_PIN2

void CLCD_voidSendData(u8 u8DataCopy);
void CLCD_voidSendCommand(u8 u8CommandCopy);
void CLCD_voidInit(void);

#define CLCD_READ         1
#define CLCD_WRITE        0
#endif
