#include <iostream>	

using namespace std;

/*

	Ý tưởng: - Ta sẽ viết 2 hàm 
				+ Hàm thứ nhất dùng để trộn
				+ Hàm thứ hai dùng để merge




	Sắp xếp từ nhỏ đến lớn: 1 5 7 9 5 8 6 2 3

		1 5 7 9 5 8 6 2 5
		   /          \
	 1 5 7 9 5       8 6 2 5  
		/  \          /   \
	1 5 7   9 5     8 6   2 5
	/  \    / \    /  \   /  \
 1 5    7  9   5  8    6  2   5
 / \ 
 1  5   7   9  5  8   6   2    5
 1  5  5  7  9 |  2   5   6   8


*/



void merge(int* arr, int left, int mid, int right) {
	int sizeArrOne = mid - left + 1;
	int sizeArrTwo = right - mid;

	int* ArrOne = new int[sizeArrOne];
	int* ArrTwo = new int[sizeArrTwo];

	//Sao chep 
	for (int i = 0; i < sizeArrOne; i++)
	{
		ArrOne[i] = arr[left + i];
	}
	// Sao chep
	for (int i = 0; i < sizeArrTwo; i++)
	{
		ArrTwo[i] = arr[mid + i + 1];
	}

	int indexOne = 0;
	int indexTwo = 0;
	int indexArr = left;

	// Thao tác trộn
	while (indexOne < sizeArrOne && indexTwo < sizeArrTwo)
	{
		if (ArrOne[indexOne] <= ArrTwo[indexTwo]) {
			arr[indexArr] = ArrOne[indexOne];
			indexOne += 1;
		}
		else
		{
			arr[indexArr] = ArrTwo[indexTwo];
			indexTwo += 1;
		}

		indexArr += 1;
	}

	while (indexOne < sizeArrOne)
	{
		arr[indexArr] = ArrOne[indexOne];
		indexOne += 1;
		indexArr += 1;
	}

	while (indexTwo < sizeArrTwo)
	{
		arr[indexArr] = ArrTwo[indexTwo];
		indexTwo += 1;
		indexArr += 1;
	}

}


void MergeSort(int* arr, int left, int right) {
	if (left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;

	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

int main() {

	int* a = new int[9]{ 1, 5, 7, 9, 5, 8, 6, 2, 3 };
	MergeSort(a, 0, 8);

	for (size_t i = 0; i < 9; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;

	return 0;
}