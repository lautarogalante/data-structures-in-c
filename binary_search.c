#include <stdio.h>

int binary_search(int numbers[], int length, int n) {
	int left = 0;	
	int right = length - 1;

	while(left <= right) {
		int middle = (left + right) / 2;
		if (numbers[middle] < n) {
			left = middle + 1; 
		} else if (numbers[middle] > n) {
			right = middle - 1;
		} else {
			return middle;
		}
	}
	return -1;
}


int main() {
	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int length = sizeof(numbers) / sizeof(numbers[0]);
	int index = binary_search(numbers, length, 9);
	if(index < 0) {
		printf("Number not found.\n");
	}else {
		printf("Index: %d\n", index);
	}
	return 0;
}

