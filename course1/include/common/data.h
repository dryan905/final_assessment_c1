/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Header file which contains function declarations 
 *
 * This header file contains the function declarations and descriptions 
 * for the functions used in stats.c
 *
 * @author David Ryan
 * @date 26/04/2019 
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Converts an integer to an ASCII string
 *
 * This function takes a signed 32-bit integer, a pointer
 * to a memory location to store the ASCII string and base
 * value used to convert the data.
 *
 * @param data: The value to be converted to an ASCII string
 * @param ptr: pointer to memory location to store the result
 * @param base: The base you want to convert the data to
 *
 * @return Length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Converts an ASCII string to a integer
 *
 *  This function takes a pointer to a memory location which holds
 *  the ASCII string. digits is the legth of the string and base
 *  base is what number representation you want to convert to.
 *
 * @param ptr: memory location which holds the ASCII string
 * @param digits: length of the ASCII string
 * @param base: The base you want to convert the data to
 *
 * @return converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */

