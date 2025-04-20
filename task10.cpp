#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void copy() {
	int arr1[100];
	int arr2[100];
	int n;
	cout << "enter size  of elements:" << endl;
	cin >> n;
	cout << "enter integer array: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		arr2[i] = arr1[i];
	}
	cout << "array copied successfully" << endl;
	cout << "copied array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << " ";
	}
}
int main() {
	copy();
	return 0;
}