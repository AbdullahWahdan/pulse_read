#ifndef MATH_H_
#define MATH_H_


#define SET_BIT(REG,BIT) 	(REG|=(0x01<<BIT))
#define CLR_BIT(REG,BIT) 	(REG&=~(0x01<<BIT))
#define TOOGLE_BIT(REG,BIT) (REG^=(0x01<<BIT))
#define GET_BIT(REG,BIT)	((REG>>BIT) & 0x01)







#endif