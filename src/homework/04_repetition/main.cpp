//write include statements
#include <iostream>
#include "repetition.h"

//write using statements
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int choice;
	
	do
	{
		cout << "\nHomework 4 Menu" << endl;
		cout << "1-Factorial" << endl;
		cout << "2-Sum odd numbers" << endl;
		cout << "3-Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		
		if (choice == 1)
		{
			int num;
			do
			{
				cout << "Enter a number (1-9): ";
				cin >> num;
				
				if (num < 1 || num >= 10)
				{
					cout << "Number must be greater than 0 and less than 10." << endl;
				}
			} while (num < 1 || num >= 10);
			
			int result = get_factorial(num);
			cout << "Factorial of " << num << " is " << result << endl;
		}
		else if (choice == 2)
		{
			int num;
			do
			{
				cout << "Enter a number (1-99): ";
				cin >> num;
				
				if (num < 1 || num >= 100)
				{
					cout << "Number must be greater than 0 and less than 100." << endl;
				}
			} while (num < 1 || num >= 100);
			
			int result = sum_odd_numbers(num);
			cout << "Sum of odd numbers up to " << num << " is " << result << endl;
		}
		else if (choice == 3)
		{
			cout << "Exiting program." << endl;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
		}
		
	} while (choice != 3);
	
	return 0;
}
