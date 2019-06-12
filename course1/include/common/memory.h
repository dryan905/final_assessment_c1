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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__



#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief moves memory from its source destination to a new destination
 *
 * This function takes two pointers (one source and one destination) 
 * and a length of bytes to move from the source location to the destination 
 *
 * @param src: Pointer to source memory location 
 * @param dst: Pointer to destination memory location 
 * @param length: Length of bytes to move
 *
 * @return A pointer to the dst memory address.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies data from memory location to another
 *
 * This function takes two pointers (one source and one destination) 
 * and a length of bytes to copy from the source location to the destination
 *
 * @param src: Pointer to source memory location 
 * @param dst: Pointer to destination memory location 
 * @param length:  Length of bytes to copy
 *
 * @return A pointer to the dst memory address.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets the value for a given memory range
 *
 * This function takes one  pointer (the source),
 * the length in bytes  and a value to assign to each memory location  
 *
 * @param src: Pointer to memort location 
 * @param length: length of memory locations to change
 * @param value: The value to assign at each memory location
 *
 * @return A pointer to the src memory address.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets the value for a given memory range to 0
 *
 * This function takes one  pointer (the source),
 * the length in bytes. At each memory location,set the value to 0.
 *
 * @param src: Pointer to memory location 
 * @param length: length of memory locations to change
 *
 *
 * @return A pointer to the src memory address.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse the data at a given memory location
 *
 * This function takes pointer to a memory location and a length in bytes 
 * and reverse the order of all of the bytes 
 *
 * @param src: Pointer to memory location
 * @param length: Number of bytes to reverse
 *
 * @return A pointer to the src memory address.
 */
uint8_t * my_reverse(uint8_t * src, size_t );

/**
 * @brief reserve a certain size of memory
 *
 * This function reserves memory of a certain size.
 * This is determined by the length parameter.
 *
 * @param length: Size of memory to reserve.
 *
 * @return A pointer to memory if successful, or a Null Pointer if not successful.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief release a memory location back to the heap.
 *
 * This function takes a pointer to a memory location
 * and releases it back to the heap.
 *
 * @param src: location of memory to release
 *
 * @return void.
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
