#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int arrayPartition(int *nums, int start, int end)
{
	int pivot = start;
	int upBound = end;
	int lowBound = start + 1;

	while (lowBound < upBound)
	{
		while (nums[lowBound] < nums[pivot] && lowBound < end)
		{
			lowBound++;
		}
		while (nums[upBound] > nums[pivot] && upBound > start)
		{
			upBound--;
		}
		if (lowBound < upBound)
		{
			swap(&nums[lowBound], &nums[upBound]);
			lowBound++;
			upBound--;
		}
	}

	if (nums[pivot] > nums[upBound])
	{
		swap(&nums[pivot], &nums[upBound]);
	}
	return upBound;
}

void quickSort(int *nums, int low, int high)
{
	if (low < high)
	{
		int index = arrayPartition(nums, low, high);
		quickSort(nums, low, index - 1);
		quickSort(nums, index + 1, high);
	}
}

int main()
{
	int data[] = {9, 4, 19, 21, 7, 10, 6, 1, 2};
	int data2[] = {1, 4, 7, 90, 9};
	size_t sizeData = sizeof(data) / sizeof(data[0]);
	size_t sizeData2 = sizeof(data2) / sizeof(data2[0]);

	printf("data1 before : ");
	for (int i = 0; i < sizeData; i++)
	{
		printf("%d ", data[i]);
	}
	quickSort(data, 0, sizeData - 1);
	printf("\ndata1 after ");
	for (int i = 0; i < sizeData; i++)
	{
		printf("%d ", data[i]);
	}

	printf("\ndata2 before : ");
	for (int i = 0; i < sizeData2; i++)
	{
		printf("%d ", data2[i]);
	}
	quickSort(data2, 0, sizeData2 - 1);
	printf("\ndata2 after ");
	for (int i = 0; i < sizeData2; i++)
	{
		printf("%d ", data2[i]);
	}
	return EXIT_SUCCESS;
}
