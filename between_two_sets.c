#include "between_two_sets.h"
#include <stdbool.h>
#include <stdio.h>

static bool allOfAIsFactor(int *a, int element, int size)
{
	for (int i = 0; i < size; i++)
		if (element % a[i] != 0)
			return false;
	return true;
}

static bool isFactorOfAllB(int *a, int element, int size)
{
	for (int i = 0; i < size; i++)
		if (a[i] % element != 0)
			return false;
	return true;
}

int findGCD_inA(int *a, int size)
{
	int gcd = 0;
	for (int i = 0; i < size; i++)
		if (allOfAIsFactor(a, a[i], size))
			if (gcd < a[i])
				gcd = a[i];
	return gcd;
}

int findLCD_inB(int *b, int size)
{
	int lcd = 101;
	for (int i = 0; i < size; i++)
		if (isFactorOfAllB(b, b[i], size))
			if (b[i] < lcd)
				lcd = b[i];
	return lcd;
}

int getBetweens(int *a, int *b, int sizeA, int sizeB)
{
	int gcd_A = findGCD_inA(a, sizeB);
	int lcd_B = findLCD_inB(b, sizeA);
	return lcd_B / gcd_A;
}
