#include <avr/io.h>
#include <util/delay.h>

 
int main (void)
{
	
 DDRD |= 0b00000000;
 DDRB |= ((1 << DDB5));

 int i,a,b,c,output;
 while(1)
 {
     i = PIND;
	   
     c = i & 0b00000100;
     b = i & 0b00001000;
     a = i & 0b00010000;
     output = (!b)||c||a;

     if(output == 1)
       PORTB = ((1 <<  PB5));
     else
       PORTB = ((0 <<  PB5));
  }

  /* . */
  return 0;

}
