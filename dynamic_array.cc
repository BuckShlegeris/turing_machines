#include <iostream>

class DynamicIntArray {
public:
	DynamicIntArray() {
		contents = new int[2];
		capacity = 2;
		current_usage = 0;
	}
	int capacity, current_usage;
	int *contents;
	void printArray();
	void push(int x);
};

void DynamicIntArray::printArray() {
	int i;
	printf("here's your array: ");

	for(i = 0; i < current_usage; i++) {
		printf("%d, ", contents[i]);
	}

	printf("\ncapacity: %d. current_usage: %d\n\n", capacity, current_usage);
}

void DynamicIntArray::push(int x) {
	contents[current_usage++] = x;
}

int main () {
	DynamicIntArray x;

	int y;
	for (y=0; y<10000; y++) {
		x.push(y);
	}
	x.printArray();
}

