/*
 * main.c
 * Created: 12/13/2022 8:25:43 PM
 *  Author: Ahmed Hatem
 */



#include"delay.h"
#include"STD.H"
#include"Dioo.h"
#include"LCD.h"
#include"UltraSonic.h"
#include"DcMotor.h"
#include"Servo.h"



int main (){
//Initialize the Servo Motor and the Other External Hardware Modeules
	
	HCSR04Init();  //ultrasonic initialize
	Lcd_init();
	DcMotor_init();
	Servo_init();
	//Move Servo At Position zero at first
	Possition_Zero();

	while(1){
		//Clear LCD To Update the Distance
		Lcd_Poss(0,0);
		//Display The Distance on LCD
		Lcd_DisplayStr("Forward");
		LCD_DisplayFloat(GetPulseWidth());
		//Check if there is an object in front of the vehicle
		if(GetPulseWidth()<=40){
			//Stop the Car
			Stop();
			//turn servo at position 90
			Possition_90();			
			//Check if there is an object in right of the vehicle
			if(GetPulseWidth()<=40){
				//turn servo at position 180
				Possition_180();
				//Check if there is an object in left of the vehicle
				if(GetPulseWidth()<=40){
					//if there was an object of it's left the car should stop
					Stop();
				}
				else{
					//if not the left side is the suitable side
					Lcd_DisplayStr("Turning left");
					TurnLeft();
					_delay_ms(10000);
					Lcd_DisplayStr("Forward left");
				//Move to Position 90 first to adjust the servo on right position
					Possition_90();
					_delay_ms(500);
					Possition_Zero();
					GoForward();
				}

			}
			else{
				//if the right side is the suitable one go right
				Lcd_DisplayStr("Turning right");
				TurnRight();
				Possition_Zero();
				_delay_ms(10000);
				Lcd_DisplayStr("Forward right");

				GoForward();

			}

		}
		else
			//if there was no object in front of the car
			GoForward();
			Lcd_DisplayStr("Forward");
	}


	return 0;

}