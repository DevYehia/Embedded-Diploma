/*
 * bitwise.h
 *
 * Created: 5/27/2024 7:52:40 PM
 *  Author: user
 */ 


#ifndef BITWISE_H_
#define BITWISE_H_

#define SET_BIT(reg,bit) ((reg) |= (1 << (bit)))
#define CLR_BIT(reg,bit) ((reg) &= ~(1 << (bit)))
#define TGL_BIT(reg,bit) ((reg) ^= (1 << (bit)))
#define GET_BIT(reg,bit) (((reg) >> (bit)) & 1)





#endif /* BITWISE_H_ */