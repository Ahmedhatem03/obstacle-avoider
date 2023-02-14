/*
 * Servo.c
 *
 * Created: 12/13/2022 8:25:43 PM
 *  Author: hp
 */
#include"Servo.h"
//Configure the The Servo PIN Using DIO Module
void Servo_init(){
	DIO_ConfigChannel(DIO_PORTD,DIO_PIN7,OUTPUT);
}
//I used to Do PWM using Software
// Turn The Servo on Position Zero
void Possition_Zero(void){
	//Apply PWM for some time To move the Servo to Zero Position
	for(int i=0;i<100;i++){
		DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_LOW);
			_delay_ms(18.5);
			DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_HIGH);
			_delay_ms(1.5);}
}
// Turn The Servo on Position 90
void Possition_90(void){
//Same as Position Zero
	for(int i=0;i<100;i++){
		DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_LOW);
			_delay_ms(1);
			DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_HIGH);
			_delay_ms(2);}
}
// Turn The Servo on Position 180
void Possition_180(void){
//Same as Position Zero
	for(int i=0;i<1000;i++){
		DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_LOW);
			_delay_ms(19);
			DIO_WriteChannel(DIO_PORTD,DIO_PIN7,STD_HIGH);
			_delay_ms(1);}
}