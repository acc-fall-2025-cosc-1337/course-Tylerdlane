//write include statement for decisions header
#include "decisions.h"


//Write code for function(s) code here
std::string get_letter_grade_using_if(int numerical_grade)
{
	if (numerical_grade < 0 || numerical_grade > 100)
	{
		return "Invalid";
	}

	if (numerical_grade >= 90)
	{
		return "A";
	}
	else if (numerical_grade >= 80)
	{
		return "B";
	}
	else if (numerical_grade >= 70)
	{
		return "C";
	}
	else if (numerical_grade >= 60)
	{
		return "D";
	}
	else
	{
		return "F";
	}
}

std::string get_letter_grade_using_switch(int numerical_grade)
{
	if (numerical_grade < 0 || numerical_grade > 100)
	{
		return "Invalid";
	}

	int grade_bucket = numerical_grade / 10;

	switch (grade_bucket)
	{
	case 10:
	case 9:
		return "A";
	case 8:
		return "B";
	case 7:
		return "C";
	case 6:
		return "D";
	default:
		return "F";
	}
}