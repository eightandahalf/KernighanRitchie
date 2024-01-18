// Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
// the price of more tests outside.) Write a version with only one test inside the loop and
// measure the difference in run-time. 

#include <stdio.h>

int binsearch(int x, int v[]);
void insertion_sert(int v[]);
void print(int v[]);

int main()
{
	int v[] = {10, 3, 4, 0}; // 0 at the end is sort of like end of number sequence
	print(v);
	insertion_sert(v);
	print(v);
	int res = binsearch(3, v);
	printf("res after binsearch is equal to %d\n", res);
		
	printf("Press any key to exit..\n");
	getchar();
	return 0;
}

void print(int v[])
{
	int i = 0;
	while(v[i] != '\0' && v[i] != EOF)
		printf("@%d ", v[i++]);
	printf("\n");
}

void insertion_sert(int v[])
{
	int key,j;
	for(int i = 0; v[i+1] != '\0' && v[i+1] != EOF; i++)
	{
		key = v[i+1];
		j = i;
		while(j >= 0 && v[j] > key)
		{
			v[j+1] = v[j];
			v[j] = key;	
			j--;
		}
	}
}

int binsearch(int x, int v[])
{
	int arr_size = 0;
	while(v[arr_size] != '\0' && v[arr_size] != EOF)
		arr_size++;

	int low = 0;
	int mid = 0;
	int high = arr_size - 1;

	while(low <= high)
	{
		mid = (low + high) / 2;
		if(x < v[mid])
			high = mid-1;// -1 since we have already 
						 // checked that x is less than v[mid], 
						 // so the bounds of the next subarray must start at v[mid - 1]
		else if(x > v[mid])
			low = mid+1; // +1 since we have already 
						 // checked that x is greater than v[mid], 
						 // so the bounds of the next subarray must start at v[mid + 1]
		else 
			return x;		
	}
	
	return -1;
}