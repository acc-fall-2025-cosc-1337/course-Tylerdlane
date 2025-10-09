//add include statements
#include "repetition.h"

//add function(s) code here
int get_factorial(int num)
{
	int result = 1;
	
	// Using for loop to calculate factorial
	for (int i = 1; i <= num; ++i)
	{
		result *= i;
	}
	
	return result;
}

int sum_odd_numbers(int num)
{
	int sum = 0;
	int i = 1;
	
	// Using while loop to sum odd numbers
	while (i <= num)
	{
		if (i % 2 != 0)
		{
			sum += i;
		}
		++i;
	}
	
	return sum;
}
