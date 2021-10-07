#include <iostream>	

using namespace std;

/*
	Ý tưởng: - Dùng 1 vòng for để duyệt các phần tử trong mảng
			 - Trong vòng for sẽ có 1 vòng for khác cũng duyệt như vậy
			vòng for này để tìm phần tử nào đạt giá trị min thì
			trả về chỉ số cho vòng for lớn.
			 - Vòng for lớn có nhiệm vụ hoán đổi giá trị cho nó!
	
	Sắp xếp từ nhỏ đến lớn: 1 5 7 9 5 8 6 2
*/


void selectionSort(int* arr, int n) {

	int indexMin;
	for	(int i = 0; i < n; i++)
	{
		indexMin = i; 
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j]) {
				indexMin = j; // lưu chỉ số của phần tử có giá trị min trong mảng đang xét
			}
		}

		swap(arr[indexMin], arr[i]);

	}
}


int main() {

	int* a = new int[8]{ 1, 5, 7, 9, 5, 8, 6, 2 };
	selectionSort(a, 8);

	for (size_t i = 0; i < 8; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;


	return 0;
}