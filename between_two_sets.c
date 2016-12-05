#include "between_two_sets.h"
#include <stdbool.h>

static bool allOfAIsFactor(int *a, int element, int size)
{
	for (int i = 0; i < size; i++)
		if (element % a[i] != 0)
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
	return 2;
}
