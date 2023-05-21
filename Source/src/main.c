//
// Created by lsc on 23-5-19.
//
#include "air32f103cx.h"
#include "air32f103_rcc.h"
void SET_CLOCK(){
    RCC->CR |= (1<<16);
    int pc=0;
    while(pc==0){
        pc=((RCC->CR) >> 17)&1;
    }
    RCC->CFGR |= (1<<16);
    RCC->CFGR &= ~(1<<17);
    RCC->CFGR |= (31<<18);
    RCC->CR |= (1<<24);
    pc =0;
    while(pc==0){
        pc = ((RCC->CR)>>25)&1;
    }
    RCC->CFGR |= (1<<1);
    RCC->CFGR &= ~(1<<0);
    pc =0;
    while(pc==0){
        pc = ((RCC->CFGR)>>2)&3;
    }
}
void led_init(){
    RCC->APB2ENR |= (1<<4);
    GPIOC->CRH &= ~((1<<22)|(1<<23));
    GPIOC->CRH |= (1<<20)|(1<<21);
}
int main(){
    SET_CLOCK();
    led_init();
    while(1){
        GPIOC->ODR |= 1<<13;
        for(int i=1;i<=5000000;i++);
        GPIOC->ODR &= ~(1<<13);
        for(int i=1;i<=5000000;i++);
    }
}