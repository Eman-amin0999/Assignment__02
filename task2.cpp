#include<iostream>
using namespace std;
void sum(int arr[5]) {
	int sum = 0;
	for (int i = 0;i <5;i++) {
		sum += arr[i];
	}
	cout << sum << endl;
}
int main() {

	
	int array[5];

	cout << "enter 5 integers :" << endl;
	for (int i = 0;i <5;i++) {
		cin >> array[i];
	}
	cout << "the sum of integers are :" << endl;
	sum(array);
	return 0;
}