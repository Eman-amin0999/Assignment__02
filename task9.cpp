#include<iostream>
#include<string>
using namespace std;
void palindrome() {
	char str[100];
	cout << "enter a string:" << endl;
	cin.getline(str, 100);
	int len = 0;
	int palindrome = true;
	while (str[len] != '\0') {
		len++;
	}
	for (int i = 0; i < len / 2; i++) {
		if (str[i] != str[len - i - 1]) {
			palindrome = false;
			break;
		}
	}
	    if (palindrome) {
			cout << "string is palindrome" << endl;
		}
		else {
			cout << "the string not is palindrome" << endl;
		}
}
int main()
{
	palindrome();
	return 0;
}