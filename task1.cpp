#include<iostream>
using namespace std;
void passarray(int arr[],int size) {
	
	for (int i = 0;i <= 4;i++) {
		cout << arr[i] << " " << endl;
	}
}
int main() {
	int array[4];
	cout << "enter 5 integers :" << endl;
	for (int i = 0;i <= 4;i++) {
		cin >> array[i];
	}
	passarray(array,4);
	return 0;
}