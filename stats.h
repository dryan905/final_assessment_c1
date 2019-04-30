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
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Prints out statistics on an array of data.
 *
 * This function will print out statistical analysis done on an arry of data
 *
 * @param min: The min value from an array of data.
 * @param max: The max value from an array of data.
 * @param mean: The mean value from an array of data.
 * @param med: The median value from an array of data.
 *
 * @return No return value.
 */
void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char med);


/**
 * @brief Prints out an array of data.
 *
 * This function will print out an arry of data to the terminal.
 *
 * @param data_array: Unsigned char pointer to an n-element data array.
 * @param data_size: Unsigned integer which indicates the size of the array.
 *
 * @return No return value.
 */

void print_array(unsigned char * data_array, unsigned int data_size);


/**
 * @brief Finds the median value of an array of data.
 *
 * This function takes an unsigned char pointer to an 
 * n-element data array and an unsigned integer which
 * inicates the size of the array. This function will
 * first sort the array and then find the median of
 * the data_array. 
 *
 * @param data_array: Unsigned char pointer to an n-element data array.
 * @param data_size: Unsigned integer which indicates the size of the array.
 *
 * @return Unsigned char value which represents the median value of the data_array.
 */

unsigned char find_median(unsigned char * data_array, unsigned int data_size);


/**
 * @brief Finds the mean value of an array of data.
 *
 * This function takes an unsigned char pointer to an
 * n-element data array and an unsigned integer which
 * inicates the size of the array. This function will
 * find the mean of the data_array.
 *
 * @param data_array: Unsigned char pointer to an n-element data array.
 * @param data_size: Unsigned integer which indicates the size of the array.
 *
 * @return Unsigned char value which represents the mean value of the data_array.
 */

unsigned char find_mean(unsigned char * data_array, unsigned int data_size);


/**
 * @brief Finds the max value in an array of data.
 *
 * This function takes an unsigned char pointer to an
 * n-element data array and an unsigned integer which
 * inicates the size of the array. This function will
 * find the max value in the data_array.
 *
 * @param data_array: Unsigned char pointer to an n-element data array.
 * @param data_size: Unsigned integer which indicates the size of the array.
 *
 * @return Unsigned char value which represents the max value of the data_array.
 */

unsigned char find_maximum(unsigned char * data_array, unsigned int data_size);


/**
 * @brief Finds the min value in an array of data.
 *
 * This function takes an unsigned char pointer to an
 * n-element data array and an unsigned integer which
 * inicates the size of the array. This function will
 * find the min value in the data_array.
 *
 * @param data_array: Unsigned char pointer to an n-element data array.
 * @param data_size: Unsigned integer which indicates the size of the array.
 *
 * @return Unsigned char value which represents the min value in the data_array.
 */

unsigned char find_minimum(unsigned char * data_array, unsigned int data_size);


/**
 * @brief Sorts an array from largest to smallest.
 *
 * This function takes an unsigned char pointer to an
 * n-element data array and an unsigned integer which
 * inicates the size of the array. This function will
 * sort the array so the zeroth element is the largest 
 * value and the last element is the smallest value.
 *
 * @param data_array: Unsigned char pointer to an n-element data array.
 * @param data_size: Unsigned integer which indicates the size of the array.
 *
 * @return No return value.
 */

void sort_array(unsigned char * data_array, unsigned int data_size);


#endif /* __STATS_H__ */
