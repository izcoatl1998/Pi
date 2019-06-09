#include <Pi.h>
int lectura_adc=0 ;
int16 valor_lectura=0,pot_humedad=0,pot_presion=0;
int flag_an0=0, flag_an1=0;

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
   flag_an0=1;
   set_adc_channel(0);
   read_adc(ADC_START_ONLY);
   while(TRUE)
   {
         if(flag_an0 == 1 && lectura_adc == 1){
         pot_humedad = valor_lectura;
         flag_an0 = 0;
         flag_an1 = 1;
         lectura_adc = 0;
         set_adc_channel(1);
         read_adc(ADC_START_ONLY);
      }
         if(flag_an1 == 1 && lectura_adc == 1){
         pot_presion = valor_lectura;
         flag_an0 = 1;
         flag_an1 = 0;
         lectura_adc = 0;
         set_adc_channel(0);
         read_adc(ADC_START_ONLY);
      }
      printf("\f");
      printf("valor %li: ",pot_humedad);
      
      
      
   }

}
