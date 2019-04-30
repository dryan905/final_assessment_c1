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
 * @file stats.c
 * @brief A program that performs statistical analytics on a dataset.
 *
 * This program contains functions that can analyze an array of unsigned char
 * data items. These functions report the maximum, minimum, mean and median 
 * of the dataset. Other funstions in this program are used to print the results 
 * from the statistical analyics and to print the unsigned char array. Also there
 * is a function used to sort the array.
 *
 * @author David Ryan
 * @date 26/04/2019
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char med){

}

void print_array(unsigned char * data_array){

}

unsigned char find_median(unsigned char * data_array, unsigned int data_size){

}

unsigned char find_mean(unsigned char * data_array, unsigned int data_size){

}

unsigned char find_maximum(unsigned char * data_array, unsigned int data_size){

}

unsigned char find_minimum(unsigned char * data_array, unsigned int data_size){

}

void find_maximum(unsigned char * data_array, unsigned int data_size){

}




