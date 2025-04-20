#include<iostream>
#include<string>
using namespace std;
void reverse() {
	char str[100];
	int len = 0;
	cout << "Enter a string:" << endl;
		cin.getline(str, 100);
	
		while (str[len] != '\0') {
			len++;
		}
		for (int i = 0; i < len / 2; i++) {
			int temp = str[i];
			str[i] = str[len-i - 1];
			str[len-i - 1] = temp;
		}
		cout << "reverse array is :" << str<< endl;
}
int main() 
{
	reverse();
	return 0;
}