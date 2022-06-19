#include "sort.h"

int getMax(int array[], int n)
{
	int max = array[0];
	int i = 0;

	for (i = 1; i < n; i++)
	if (array[i] > max)
		max = array[i];
	return (max);
}

void countingSort(int array[], int size, int place)
{
	int max = (array[0] / place) % 10;
	int i = 0;
	int output[size + 1];
	int count[max + 1];

	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > max)
			max = array[i];
	}

	for (i = 0; i < max; ++i)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];
}

void radix_sort(int *array, size_t size)
{
	int place = 0;
	int max = getMax(array, size);

	for (place = 1; max / place > 0; place *= 10)
		countingSort(array, size, place);
}
