/*
 * pinDefines.h
 *
 * Created: 27-05-2021 10:11:04 AM
 *  Author: Kunal
 */ 


#define DELAYTIME   85
#define LED_PORT	PORTB
#define LED_PIN		PINB
#define LED_DDR		DDRB

#define LED0		PB0
#define LED1		PB1
#define LED2		PB2
#define LED3		PB3
#define LED4		PB4
#define LED5		PB5
#define LED6		PB6
#define LED7		PB7

#define BUTTON_PORT	PORTD
#define BUTTON_PIN	PIND
#define BUTTON_DDR	DDRD

#define BUTTON		PD2
#define BUTTON2		PD3
#define BUTTON3		PD4

// SPI and I2C serial mode defines
#define SPI_SS                     PB2
#define SPI_SS_PORT                PORTB
#define SPI_SS_PIN                 PINB
#define SPI_SS_DDR                 DDRB

#define SPI_MOSI                     PB3
#define SPI_MOSI_PORT                PORTB
#define SPI_MOSI_PIN                 PINB
#define SPI_MOSI_DDR                 DDRB

#define SPI_MISO                     PB4
#define SPI_MISO_PORT                PORTB
#define SPI_MISO_PIN                 PINB
#define SPI_MISO_DDR                 DDRB

#define SPI_SCK                     PB5
#define SPI_SCK_PORT                PORTB
#define SPI_SCK_PIN                 PINB
#define SPI_SCK_DDR                 DDRB

#define I2C_SDA                     PC4
#define I2C_SDA_PORT                PORTC
#define I2C_SDA_PIN                 PINC
#define I2C_SDA_DDR                 DDRC

#define I2C_SCL                     PC5
#define I2C_SCL_PORT                PORTC
#define I2C_SCL_PIN                 PINC
#define I2C_SCL_DDR                 DDRC



