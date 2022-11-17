#include <iostream>
#include <cstdlib>

using namespace std;

//takes an array and its length as parameters
void displayList(int list[], int length) {
	cout << "[ ";
	//iterates through it and displays all of its elements
	for (int i = 0; i < length; i++) {
		cout << list[i] << ", ";
	}
	cout << "]";
}

//is the sorting ascending or descending? return true if ascending and false if not
bool isAscending() {
	cout	<< "Diurut secara?\n"
			<< "1. Ascending\n"
			<< "2. Descending\n"
			<< ">> ";
	int x;
	cin >> x;
	return x == 1;
}

//swaps two integers
void swapInt(int* m, int* n) {
	int temp = *m;
	*m = *n;
	*n = temp;
}

void bubbleSort(int list[], int len) {
	bool order_asc = isAscending();

	//iterate from the end of the array to the 2nd element
	for (int i = len-1; i >= 1; i--) {
		//iterate from the first element to the current i value
		for (int j = 0; j < i; j++) {
			//if two elements are out of order, swap
			if (order_asc) {
				if (list[j] > list[j + 1]) {
					swap(list[j], list[j + 1]);
				}
			}
			else {
				if (list[j] < list[j + 1]) {
					swap(list[j], list[j + 1]);
				}
			}
		}
	}

}

void selectionSort(int list[], int len) {
	bool order_asc = isAscending();

	//from the 1st element to one before last
	for (int i = 0; i < len-1; i++) {
		int current_index = i;
		//from the element after current element to last
		for (int j = i+1; j < len; j++) {
			//if out of order, track its index
			if (order_asc) {
				if (list[j] < list[current_index]){
					current_index = j;
				}
			}
			else {
				if (list[j] > list[current_index]) {
					current_index = j;
				}
			}
			//if theres an element out of place, swap
			if (current_index != i) {
				swapInt(&list[i], &list[current_index]);
			}
		}
	}
}

void insertionSort(int list[], int len) {
	bool order_asc = isAscending();
	//start inserting from the 2nd element to last element
	for (int i = 1; i < len; i++) {
		int key = list[i];
		int j = i - 1;
		//check all previous elements and shift them while the element is still smaller
		//we can assume all previous elements are already trivially sorted and in order
		if (order_asc) {
			while ((j >= 0) && (list[j] > key)) {
				list[j + 1] = list[j];
				j--;
			}
		}
		else {
			while ((j >= 0) && (list[j] < key)) {
				list[j + 1] = list[j];
				j--;
			}
		}
		//
		list[j + 1] = key;
	}
}

int main() {
	//Alexander Yuanata
	//211401032

	while (true) {
		system("cls");
		//reset array each loop
		int list[8] = { 10, 11, 23, 21, 0, 0, 8, 7 };

		//menu
		cout << "Proses pengurutan pada data "; displayList(list, sizeof(list) / sizeof(*list)); cout << " dengan algoritma:\n"
			<< "1. Bubble Sort\n"
			<< "2. Selection Sort\n"
			<< "3. Insertion Sort\n"
			<< "4. Exit\n"
			<< ">> ";
		int selection;
		cin >> selection;

		//switch case
		switch (selection) {
			case 1: {
				bubbleSort(list, sizeof(list) / sizeof(*list));
				displayList(list, sizeof(list) / sizeof(*list));
				cout << endl;
				break;
			}
			
			case 2: {
				selectionSort(list, sizeof(list) / sizeof(*list));
				displayList(list, sizeof(list) / sizeof(*list));
				cout << endl;
				break;
			}
	
			case 3: {
				insertionSort(list, sizeof(list) / sizeof(*list));
				displayList(list, sizeof(list) / sizeof(*list));
				cout << endl;
				break;
			}

			case 4: {
				exit(0);
				break;
			}

			default: {
				cerr << "False input, please retry!\n";
			}
		}
		system("pause");
	}

	return 0;
}