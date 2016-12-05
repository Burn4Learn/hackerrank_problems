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
	if (allOfAIsFactor(a, a[size - 1], size))
		return 16;
	return 0;
}


