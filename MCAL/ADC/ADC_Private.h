/*
 * ADC_Private.h
 *
 * Created: 5/2/2022 4:52:21 AM
 *  Author: Ahmed
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_Channel0	0x43
#define ADC_Channel1	0x44
#define ADC_Channel2	0x45
#define ADC_Channel3	0x46
#define ADC_Channel4	0x47
/*
#define ADC_Channel0	0
#define ADC_Channel1	1
#define ADC_Channel2	2
#define ADC_Channel3	3
#define ADC_Channel4	4
#define ADC_Channel5	5
#define ADC_Channel6	6
#define ADC_Channel7	7
*/
/* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/* ADMUX */
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

#define ADC   (*(volatile u16*)(0x24))
#define ADCSRA  (*(volatile u8*)(0x26))
#define ADMUX  (*(volatile u8*)(0x27))

/* analog comparator */
#define ACSR    (*(volatile u8*)(0x28))

/* ACSR */
#define ACD     7
#define ACBG    6
#define ACO     5
#define ACI     4
#define ACIE    3
#define ACIC    2
#define ACIS1   1
#define ACIS0   0


#define SFIOR   (*(volatile u8*)(0x50))


/* SFIOR */
#define ADTS2   7
#define ADTS1   6
#define ADTS0   5
/* bit 4 reserved */
#define ACME    3
#define PUD     2
#define PSR2    1
#define PSR10   0

#endif /* ADC_PRIVATE_H_ */