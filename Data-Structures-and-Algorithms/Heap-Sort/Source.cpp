#include<iostream>

using namespace std;


/*
	Sắp xếp từ nhỏ đến lớn: 1 5 7 9 5 8 6 2
	

		   1(0)
		  /	  \
		5(1)   7(2)
       /  \   /  \
	9(3) 5(4) 8(5) 6(6)
	 /   
	2(7)
*/



// Xây dựng hàm Heap chất đống 
// Hàm có giá trị từ node i = largest của nó trờ xuống
void heapify(int* arr, int n, int i) {
	int largest = i; // phần tử đang xét
	int left = 2 * i + 1; // chỉ số bên trái 
	int right = 2 * i + 2; // chỉ số bên phải

	if (left < n && arr[largest] < arr[left]) {
		largest = left;
	}

	if (right < n && arr[largest] < arr[right]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}

}


void heapSort(int* arr, int n) {

	// Duyệt từ node số gần cuối về 0
	for (int i = n/2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	// Duyệt từ cuối về đầu để lấy các phần tử chỉ số 0 về cuối
	for (int i = n -1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}



int main() {
	
	int* a = new int[8]{ 1, 5, 7, 9, 5, 8, 6, 2 };
	heapSort(a, 8);

	for (size_t i = 0; i < 8; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;


	return 0;
}