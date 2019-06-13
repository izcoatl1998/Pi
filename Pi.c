#include <Pi.h>
int lectura_adc=0 ;
double valor_lectura=0,pot_humedad=0,pot_presion=0,pot_temperatura;
int flag_an0=0, flag_an1=0,flag_an2=0;
double porcentaje_presion=0, porcentaje_humedad;
#INT_AD
void isr_adc(){
   valor_lectura = read_adc(adc_read_only);
   lectura_adc=1;
}
void main()
{
   setup_adc(ADC_CLOCK_INTERNAL | ADC_TAD_MUL_4);
   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);
   setup_adc_ports(AN0_TO_AN2);
   flag_an0=1;
   set_adc_channel(0);
   read_adc(ADC_START_ONLY);
   while(TRUE)
   {
         if(flag_an0 == 1 && lectura_adc == 1){
         pot_temperatura = valor_lectura;
         pot_temperatura =(pot_temperatura*125)/308;
         flag_an0 = 0;
         flag_an1 = 1;
         lectura_adc = 0;
         set_adc_channel(1);
         read_adc(ADC_START_ONLY);
      }
         if(flag_an1 == 1 && lectura_adc == 1){
         pot_presion = valor_lectura;
         flag_an0 = 0;
         flag_an1 = 0;
         flag_an2=1;
         lectura_adc = 0;
         set_adc_channel(2);
         read_adc(ADC_START_ONLY);
      }
      if(flag_an2 == 1 && lectura_adc == 1){
         pot_humedad = valor_lectura;
         porcentaje_humedad = ((pot_humedad/1023)*100);
         flag_an0 = 1;
         flag_an1 = 0;
         flag_an2=0;
         lectura_adc = 0;
         set_adc_channel(0);
         read_adc(ADC_START_ONLY);
         
      }
      printf("\f");
      printf("valor: %.0f ",pot_temperatura);
      printf("\r valor: %.0f ",pot_presion);
      printf("\r valor: %.0f porcentaje : %f",pot_humedad,porcentaje_humedad);
      
      
   }

}
