/*
* ATMega32_Complete.c
*
* Created: 4/8/2022 5:40:41 PM
* Author : Ahmed
*/
#include "main.h"
#include <util/delay.h>
#define		MAX_WORDS			6
#define		SENSOR_TOLERANCE	20

u16 thumb;
u16 indexfinger;
u16 middle;
u16 ring;
u16 pinky;

typedef struct
{
	u16 Hand_thumb;
	u16 Hand_index;
	u16 Hand_middle;
	u16 Hand_ring;
	u16 Hand_pinky;
}HandGesture;

HandGesture Signs[MAX_WORDS]=
{
	{186,214,218,236,225},
	{109,115,140,131,134},
	{205,227,246,136,224},
	{130,227,133,144,238},
	{205,227,153,160,215},
	{127,195,206,160,157},
};

const u8 *Translatation[MAX_WORDS]=
{
	"Open Hand",
	"Closed Hand",
	"I Really Love U",
	"Rock",
	"I Love You",
	"I'm Watching U"
};

void Print_TranslatedGesture(void);

int main(void)
{
	LCD_enuInit();
	ADC_Callback((&thumb),(&indexfinger),(&middle),(&ring),(&pinky),Print_TranslatedGesture);
	ADC_Init();
	asm("SEI");
	ADC_Start();
	Print_TranslatedGesture();
	while(1);
}

void Print_TranslatedGesture(void)
{
	u8 L_iter;
	u8 flag=0;
	u8 temp=50;
	
		for(L_iter=0;L_iter<MAX_WORDS;L_iter++)
		{
			flag=0;
			if((thumb <= (SENSOR_TOLERANCE+Signs[L_iter].Hand_thumb))&&((thumb >= (Signs[L_iter].Hand_thumb-SENSOR_TOLERANCE))))
			{
				flag++;
			}else{continue;}
			if((indexfinger <= (SENSOR_TOLERANCE+Signs[L_iter].Hand_index))&&((indexfinger >= (Signs[L_iter].Hand_index-SENSOR_TOLERANCE))))
			{
				flag++;
			}else{continue;}
			if((middle <= (SENSOR_TOLERANCE+Signs[L_iter].Hand_middle))&&((middle >= (Signs[L_iter].Hand_middle-SENSOR_TOLERANCE))))
			{
				flag++;
			}else{continue;}
			if((ring <= (SENSOR_TOLERANCE+Signs[L_iter].Hand_ring))&&((ring >= (Signs[L_iter].Hand_ring-SENSOR_TOLERANCE))))
			{
				flag++;
			}else{continue;}
			if((pinky <= (SENSOR_TOLERANCE+Signs[L_iter].Hand_pinky))&&((pinky >= (Signs[L_iter].Hand_pinky-SENSOR_TOLERANCE))))
			{
				flag++;
			}else{continue;}
			if(flag == 5)
			{
				if(temp != L_iter)
				{
					temp = L_iter;
					LCD_enuWriteCommand(0x01);
					LCD_enuWriteString(Translatation[L_iter]);	
				}else{}
			}else{}
		}
			ADC_Start();
}
		