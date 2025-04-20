#include<iostream>
using namespace std;
void maximum(int array[5]) {

	int maxvalue = array[0];

	for (int i = 0;i< 5;i++) {

		if (array[i] > maxvalue) {
			maxvalue = array[i];
		}
	}
	cout << maxvalue << endl;
}
int main() {

	int arr[5];

	cout << "enter integers: ";
	for (int i = 0;i <5;i++)
		cin >> arr[i];
	cout << "the maximum element is :" << endl;
	maximum(arr);

	return 0;
}