#ifndef STM32G0B1RE_H__
#define STM32G0B1RE_H__

typedef struct 
{
    volatile unsigned long CR;
    volatile unsigned long ICSCR;
    volatile unsigned long CFGR;
    volatile unsigned long PLLCFGR;
    volatile unsigned long RESERVED;
    volatile unsigned long CRRCR;
    volatile unsigned long CIER;
    volatile unsigned long CIFR;
    volatile unsigned long CICR;
    volatile unsigned long IOPRSTR;
    volatile unsigned long AHBRSTR;
    volatile unsigned long APBRSTR1;
    volatile unsigned long APBRSTR2;
    volatile unsigned long IOPENR;
    volatile unsigned long AHBENR;
    volatile unsigned long APBENR1;
    volatile unsigned long APBENR2;
    volatile unsigned long IOPSMENR;
    volatile unsigned long AHBSMENR;
    volatile unsigned long APBSMENR1;
    volatile unsigned long APBSMENR2;
    volatile unsigned long CCIPR;
    volatile unsigned long CCIPR2;
    volatile unsigned long BDCR;
    volatile unsigned long CSR;
}RCC_TypeDef;

typedef struct 
{
    volatile unsigned long MODER;
    volatile unsigned long OTYPER;
    volatile unsigned long OSPEEDR;
    volatile unsigned long PUPDR;
    volatile unsigned long IDR;
    volatile unsigned long ODR;
    volatile unsigned long BSRR;
    volatile unsigned long LCKR;
    volatile unsigned long AFRL;
    volatile unsigned long AFRH;
    volatile unsigned long BRR;
}Port_RegisterType;

#define RCC         ((RCC_TypeDef*)0x40021000)
                                     
#define GPIOA       ((Port_RegisterType*)0x50000000)
#define GPIOB       ((Port_RegisterType*)0x50000400)
#define GPIOC       ((Port_RegisterType*)0x50000800)
#define GPIOD       ((Port_RegisterType*)0x50000C00)
#define GPIOE       ((Port_RegisterType*)0x50001000)
#define GPIOF       ((Port_RegisterType*)0x50001400)

#endif