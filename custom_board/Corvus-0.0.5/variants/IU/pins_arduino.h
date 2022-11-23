/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NUM_DIGITAL_PINS            20
#define NUM_ANALOG_INPUTS           6
#define analogInputToDigitalPin(p)  ((p < 6) ? (p) + 14 : -1)

#if defined(__AVR_ATmega8__)
#define digitalPinHasPWM(p)         ((p) == 9 || (p) == 10 || (p) == 11)
#else
#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 5 || (p) == 6 || (p) == 9 || (p) == 10 || (p) == 11)
#endif

#define PIN_SPI_SS    (10)
#define PIN_SPI_MOSI  (11)
#define PIN_SPI_MISO  (12)
#define PIN_SPI_SCK   (13)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_WIRE_SDA        (18)
#define PIN_WIRE_SCL        (19)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define LED_BUILTIN 13

#define PIN_A0   (14)
#define PIN_A1   (15)
#define PIN_A2   (16)
#define PIN_A3   (17)
#define PIN_A4   (18)
#define PIN_A5   (19)
#define PIN_A6   (20)
#define PIN_A7   (21)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))

#ifdef ARDUINO_MAIN

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

// ATMEL ATMEGA8 & 168 / ARDUINO
//
//                  +-\/-+
//            PC6  1|    |28  PC5 (AI 5)
//      (D 0) PD0  2|    |27  PC4 (AI 4)
//      (D 1) PD1  3|    |26  PC3 (AI 3)
//      (D 2) PD2  4|    |25  PC2 (AI 2)
// PWM+ (D 3) PD3  5|    |24  PC1 (AI 1)
//      (D 4) PD4  6|    |23  PC0 (AI 0)
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5 (D 13)
// PWM+ (D 5) PD5 11|    |18  PB4 (D 12)
// PWM+ (D 6) PD6 12|    |17  PB3 (D 11) PWM
//      (D 7) PD7 13|    |16  PB2 (D 10) PWM
//      (D 8) PB0 14|    |15  PB1 (D 9) PWM
//                  +----+
//
// (PWM+ indicates the additional PWM pins on the ATmega168.)

// ATMEL ATMEGA1280 / ARDUINO
//
// 0-7 PE0-PE7   works
// 8-13 PB0-PB5  works
// 14-21 PA0-PA7 works 
// 22-29 PH0-PH7 works
// 30-35 PG5-PG0 works
// 36-43 PC7-PC0 works
// 44-51 PJ7-PJ0 works
// 52-59 PL7-PL0 works
// 60-67 PD7-PD0 works
// A0-A7 PF0-PF7
// A8-A15 PK0-PK7


// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PD, // PD 0 ** 0 ** USART_TX	
	PD, // PD 1 ** 1 **	USART_RX
	PD, // PD 2 ** 2 **
	PD, // PD 3 ** 3 **
	PD, // PD 4 ** 4 **
	PD, // PD 5 ** 5 **
	PD, // PD 6 ** 6 **
	PD, // PD 7 ** 7 **
	PB, // PB 0 ** 8 **
	PB, // PB 1 ** 9 **
	PB, // PB 2 ** 10 **
	PB, // PB 3 ** 11 **
	PB, // PB 4 ** 12 **
	PB, // PB 5 ** 13 **
	PC, // PC 0 ** 14 ** A0
	PC, // PC 1 ** 15 ** A1
	PC, // PC 2 ** 16 ** A2
	PC, // PC 3 ** 17 ** A3
	PC, // PC 4 ** 18 ** A4
	PC, // PC 5 ** 19 ** A5
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0), // PD 0 ** 0 ** USART_TX
	_BV(1), // PD 1 ** 1 **	USART_RX
	_BV(2), // PD 2 ** 2 **
	_BV(3), // PD 3 ** 3 **
	_BV(4), // PD 4 ** 4 **
	_BV(5), // PD 5 ** 5 **
	_BV(6), // PD 6 ** 6 **
	_BV(7), // PD 7 ** 7 **
	_BV(0), // PB 0 ** 8 **
	_BV(1), // PB 1 ** 9 **
	_BV(2), // PB 2 ** 10 **
	_BV(3), // PB 3 ** 11 **
	_BV(4), // PB 4 ** 12 **
	_BV(5), // PB 5 ** 13 **
	_BV(0), // PC 0 ** 14 ** A0
	_BV(1), // PC 1 ** 15 ** A1
	_BV(2), // PC 2 ** 16 ** A2
	_BV(3), // PC 3 ** 17 ** A3
	_BV(4), // PC 4 ** 18 ** A4
	_BV(5), // PC 5 ** 19 ** A5
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER, /* 0 - port D */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	// on the ATmega168, digital pin 3 has hardware pwm
#if defined(__AVR_ATmega8__)
	NOT_ON_TIMER,
#else
	TIMER2B,
#endif
	NOT_ON_TIMER,
	// on the ATmega168, digital pins 5 and 6 have hardware pwm
#if defined(__AVR_ATmega8__)
	NOT_ON_TIMER,
	NOT_ON_TIMER,
#else
	TIMER0B,
	TIMER0A,
#endif
	NOT_ON_TIMER,
	NOT_ON_TIMER, /* 8 - port B */
	TIMER1A,
	TIMER1B,
#if defined(__AVR_ATmega8__)
	TIMER2,
#else
	TIMER2A,
#endif
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER, /* 14 - port C */
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

// ATMEGA328 GPIO on IU board
// PORT B
#define PIN_PB0   (8)	// default UNO
#define PIN_PB1   (9)	// default UNO
#define PIN_PB2   (10)	// default UNO
#define PIN_PB3   (11)	// default UNO
#define PIN_PB4   (12)	// default UNO
#define PIN_PB5   (13)	// default UNO
//#define PIN_PB6   ()	// default UNO - XTAL
//#define PIN_PB7   ()	// default UNO - XTAL

// PORT C
#define PIN_PC0   (14)	// default UNO
#define PIN_PC1   (15)	// default UNO
#define PIN_PC2   (16)	// default UNO
#define PIN_PC3   (17)	// default UNO
#define PIN_PC4   (18)	// default UNO
#define PIN_PC5   (19)	// default UNO
//#define PIN_PC6   ()	//--RESET--

// PORT D
#define PIN_PD0   (0)	// default UNO
#define PIN_PD1   (1)	// default UNO
#define PIN_PD2   (2)	// default UNO
#define PIN_PD3   (3)	// default UNO
#define PIN_PD4   (4)	// default UNO
#define PIN_PD5   (5)	// default UNO
#define PIN_PD6   (6)	// default UNO
#define PIN_PD7   (7)	// default UNO

// ADC6 ??
// ADC7 ??

#endif
