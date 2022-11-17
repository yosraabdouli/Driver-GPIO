#include "gpio.h"

void GPIO_Clock_Enable(uint32_t *GPIOx){
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
  uint16_t *RCCAHB1=(uint16_t *)(0x40023830);
   uint8_t *Moder=(uint8_t *)   (0x4002c000);
    uint8_t *OTYPER=(uint8_t *) (0x4002c004);
  
   if (GPIOx == GPIOA){
   *RCCAHB1 |=(1<<0);
   }
   else if (GPIOx == GPIOB){
   *RCCAHB1 |=(1<<1);
   }
  else if (GPIOx == GPIOC){
   *RCCAHB1 |=(1<<2);
  }
  else if (GPIOx == GPIOD){
   *RCCAHB1 |=(1<<3);
  } 
}
void GPIO_Config(uint32_t *GPIOx, uint8_t Pin, uint8_t Mode,uint8_t Type)
{
  
  if (Mode == INPUT){
   *Moder &= ~(1<<24);
   *Moder &= ~(1<<25);
   }
   else if (Mode == OUTPUT){
   *Moder |=(1<<24);
   *Moder &= ~(1<<25);
   }
  else if (Mode == ALTERNATE){
   *Moder &= ~(1<<24);
   *Moder |=(1<<25);
   
  }
  else if (Mode== ANALOG_INPUT){
   *Moder |=(1<<24);
   *Moder |=(1<<25);
  } 
  
  if (Type == OUTPUT_PUSH_PULL ){
   *OTYPER |=(1<<12);
   }
   else if (Type == OUTPUT_OPEN_DRAIN){
   *OTYPER |=(1<<12);
   }

  //GPIOD->MODER |= (1<<24);  // pin 12(bits 25:24) as Output (01)
  //GPIOD->OTYPER &= ~(1<<12);  // bit 12=0 --> Output push pull
 }
