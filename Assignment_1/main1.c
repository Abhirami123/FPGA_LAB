#include <stdio.h>
#include <stdbool.h>

unsigned char Demorgan1(unsigned char a,unsigned char b,unsigned char c)
{
    unsigned char out;
    out = (~(~b | c))&(~a);
    return out;
}

int main()
{
    unsigned char num;                             //input number
    unsigned char a = 0x00,b = 0x00,c = 0x00;	    //binary inputs
    unsigned char one = 0x01;
    unsigned char f,f_comp1,f_comp2;
    
    //Different combinations of a,b,c
    for (num = 0x00; num<0x08; num++)               
    {
        //changing the inputs
        a = num>>2;
        b = num>>1;    
        c = num>>0;    
        
        f = ((~b) | c) | a;
        f_comp1 = ~f;
        
        f_comp2 = Demorgan1(a,b,c);
    
        printf("a=  %x, b= %x, c= %x", one&a, one&b, one&c);    
        printf("\t\tcomplement of ((b_bar+c)+a) = %x\n", one&f_comp1);  
        printf("\t\t\t\t comp(b_bar+c) & comp(a) = %x\n",one&f_comp2);
    }
    
   
    return 0;
}
