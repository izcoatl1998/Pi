#include <Pi.h>
int lectura_adc=0 ;
int16 valor_lectura=0;
#INT_AD
void isr_adc(){
   valor_lectura = read_adc(adc_read_only);
   lectura_adc=1;
}
void main()
{
   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0_TO_AN1);
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   while(TRUE)
   {


      
   }

}
