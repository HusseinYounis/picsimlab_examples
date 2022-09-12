/*
 * File:   newmain.c
 * Author: hussein younis
 *
 * Created on September 12, 2022, 6:55 PM
 */


#include <xc.h>
#include "newxc8_header.h"
#include <pic18f4550.h> 

#define _XTAL_FREQ 8000000 

#define LENA  PORTAbits.RA2
#define LDAT  PORTAbits.RA1
#define LPORT PORTD


#define L_ON	0x0F
#define L_OFF	0x08
#define L_CLR	0x01
#define L_L1	0x80
#define L_L2	0xC0
#define L_CR	0x0F		
#define L_NCR	0x0C	

#define L_L3	0x90
#define L_L4	0xD0


#define L_CFG   0x38


void lcd_init(void);
void lcd_cmd(unsigned char val); 
void lcd_dat(unsigned char val);
void lcd_str(const char* str);


void main(){
    
    TRISA=0x00;
    TRISD=0x00;
    LPORT = 0;
    lcd_init();
    lcd_cmd(L_CLR);
    lcd_cmd(L_NCR);
    lcd_cmd(L_L1);
    lcd_str(" Serial console");
    while(1);
}

void lcd_str(const char* str)
{
 unsigned char i=0;
  
 while(str[i] != 0 )
 {
   lcd_dat(str[i]);
   i++;
 }  
}

void lcd_cmd(unsigned char val)
{
	LENA=1;
        LPORT=val;
        LDAT=0;
        __delay_ms(3);
        LENA=0;
        __delay_ms(3);
	LENA=1;
}
 
void lcd_dat(unsigned char val)
{
	LENA=1;
        LPORT=val;
        LDAT=1;
        __delay_ms(3);
        LENA=0;
        __delay_ms(3);
	LENA=1;
}

void lcd_init(void)
{
	LENA=0;
	LDAT=0;
	__delay_ms(20);
	LENA=1;
	
	lcd_cmd(L_CFG);
	__delay_ms(5);
	lcd_cmd(L_CFG);
    __delay_ms(1);
	lcd_cmd(L_CFG);
	lcd_cmd(L_OFF);
	lcd_cmd(L_ON);
	lcd_cmd(L_CLR);
	lcd_cmd(L_CFG);
    lcd_cmd(L_L1);
}

