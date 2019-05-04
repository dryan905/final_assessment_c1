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
 * from the statistical analyics and the unsigned char array to the screen. Also 
 * there is a function used to sort the array. This function will place the largest
 * value at the head of the array and the lowest value at the end of the array.
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

  
  // Find the min, max, mean and median of test dataset.
  unsigned char min_value = find_minimum(test, SIZE);
  unsigned char max_value = find_maximum(test, SIZE);
  unsigned char mean_value = find_mean(test, SIZE);
  unsigned char median_value = find_median(test, SIZE);

  // Print the results of the analytics.
  print_statistics(min_value, max_value, mean_value, median_value);

  // Print the test dataset on the screen.
  print_array(test, SIZE);

}

void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char med){

	printf("minimum value is: %d\n", min);
	printf("maximum value is: %d\n", max);
	printf("mean value is: %d\n", mean);
	printf("median value is: %d\n", med);

}

void print_array(unsigned char * data_array, unsigned int data_size){

	for (int i = 0; i < data_size; ++i)
	{
		printf("Array[%d] = %d\n ", i, data_array[i]);
	}
	printf("\n");


}



unsigned char find_minimum(unsigned char * data_array, unsigned int data_size){

	unsigned char min = data_array[0];

	for (int i = 1; i < data_size; ++i)
	{
		if (data_array[i] < min)
		{
			min = data_array[i];
		}
	}

	return min;

}

unsigned char find_maximum(unsigned char * data_array, unsigned int data_size){

	unsigned char max = data_array[0];

	for (int i = 1; i < data_size; ++i)
	{
		if (data_array[i] > max)
		{
			max = data_array[i];
		}
	}

	return max;

}

unsigned char find_mean(unsigned char * data_array, unsigned int data_size){

	int sum_total = 0;
	unsigned char mean = 0;

	for (int i = 0; i < data_size; ++i)
	{
		sum_total += data_array[i];
	}

	mean = sum_total/data_size;

	return mean;

}

unsigned char find_median(unsigned char * data_array, unsigned int data_size){

	sort_array(data_array, data_size);
	int index = (data_size/2);

	return data_array[index];

}

void sort_array(unsigned char * data_array, unsigned int data_size){

	int start = 0;
	int end = data_size;

	// Outer loop used to select the next value to be sorted.
	for (int i = start + 1; i < end; ++i)
	{
		// Inner loop used to place the current value in its correct place in the array.
		for (int j = i; j > start && data_array[j-1] < data_array[j]; j--)
		{
			unsigned char temp = data_array[j-1];
			data_array[j-1] = data_array[j];
			data_array[j] = temp;
		}
	}

}




