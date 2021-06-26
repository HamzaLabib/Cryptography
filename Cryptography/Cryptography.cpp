#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int countDigits(int n);
double power(double base, int exponent);
int absValue(int input);

//..Part 1..//
void encryptionDisplay(int OriginalNumber);
//..Part 2..//
int encryption(int OriginalNumber);
void decryption(int encryptedNumber);


int main()
{
	//..Part 1..//
	encryptionDisplay(3201);
	//..Part 2..//
	int encryptedNumber = encryption(3201);
	decryption(encryptedNumber);

	system("pause");
	return 0;
}

double power(double base, int exponent)
{
	double result = 1;

	bool negativeExponent = exponent < 0;
	if (negativeExponent)
		exponent *= -1;

	for (int i = 0; i < exponent; i++)
		result *= base;
	if (negativeExponent)
		result = 1 / result;

	return result;
}

int countDigits(int n)
{
	int numberOfDigits = 0;
	int constant = 10;

	n = absValue(n);

	do
	{
		numberOfDigits += 1;
		n /= constant;
	} while (n >= 1);

	return numberOfDigits;
}

int absValue(int input)
{
	return input < 0 ? input * -1 : input;
}


//.. Part 1..//
void encryptionDisplay(int originalNumber)
{
	int numberOfDigit;
	int digit1, digit2, digit3, digit4;
	int newDigit1, newDigit2, newDigit3, newDigit4;
	int encryptedNumber;

	numberOfDigit = countDigits(originalNumber);

	if (numberOfDigit == 4)
	{
		// 1st digit //
		digit1 = (originalNumber / 1000) % 10;
		newDigit1 = (digit1 + 7) % 10;

		// 2nd digit //
		digit2 = (originalNumber / 100) % 10;
		newDigit2 = (digit2 + 7) % 10;

		// 3rd digit //
		digit3 = (originalNumber / 10) % 10;
		newDigit3 = (digit3 + 7) % 10;

		// 4th digit //
		digit4 = (originalNumber / 1) % 10;
		newDigit4 = (digit4 + 7) % 10;

		encryptedNumber = (newDigit3 * power(10, numberOfDigit - 1)) + (newDigit4 * power(10, numberOfDigit - 2)) +
			(newDigit1 * power(10, numberOfDigit - 3)) + (newDigit2 * power(10, numberOfDigit - 4));

		cout << encryptedNumber << endl;
	}
	else
		cout << "The number must conatins 4 digits" << endl;
}



//..Part 2..//
int encryption(int originalNumber)
{
	int numberOfDigit;
	int digit1, digit2, digit3, digit4;
	int newDigit1, newDigit2, newDigit3, newDigit4;
	//int process;
	int encryptedNumber;

	numberOfDigit = countDigits(originalNumber);

	if (numberOfDigit == 4)
	{
		// 1st digit //
		digit1 = (originalNumber / 1000) % 10;
		newDigit1 = (digit1 + 7) % 10;

		// 2nd digit //
		digit2 = (originalNumber / 100) % 10;
		newDigit2 = (digit2 + 7) % 10;

		// 3rd digit //
		digit3 = (originalNumber / 10) % 10;
		newDigit3 = (digit3 + 7) % 10;

		// 4th digit //
		digit4 = (originalNumber / 1) % 10;
		newDigit4 = (digit4 + 7) % 10;


		encryptedNumber = (newDigit3 * power(10, numberOfDigit - 1)) + (newDigit4 * power(10, numberOfDigit - 2)) +
			(newDigit1 * power(10, numberOfDigit - 3)) + (newDigit2 * power(10, numberOfDigit - 4));
	}
	else
		encryptedNumber = 0;

	return encryptedNumber;
}


void decryption(int encryptedNumber)
{
	int numberOfDigit;
	int digit1, digit2, digit3, digit4;
	int originalDigit1, originalDigit2, originalDigit3, originalDigit4;
	//int process;
	int originalNumber;

	numberOfDigit = countDigits(encryptedNumber);

	if (numberOfDigit == 1)
		cout << "Error !!" << endl;
	else
	{
		// 1st encrypted digit //
		digit1 = (encryptedNumber / 1000) % 10;
		originalDigit1 = (digit1 + 3) % 10;
		// 2nd encrypted digit //
		digit2 = (encryptedNumber / 100) % 10;
		originalDigit2 = (digit2 + 3) % 10;
		// 3rd encrypted digit //
		digit3 = (encryptedNumber / 10) % 10;
		originalDigit3 = (digit3 + 3) % 10;
		// 4th encrypted digit //
		digit4 = (encryptedNumber / 1) % 10;
		originalDigit4 = (digit4 + 3) % 10;

		originalNumber = (originalDigit3 * power(10, numberOfDigit - 1)) + (originalDigit4 * power(10, numberOfDigit - 2)) +
			(originalDigit1 * power(10, numberOfDigit - 3)) + (originalDigit2 * power(10, numberOfDigit - 4));

		cout << originalNumber << endl;
	}
}