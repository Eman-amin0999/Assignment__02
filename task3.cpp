#include<iostream>
#include<string>
using namespace std;
void vowel(char str[100]) {
	int count = 0;
	for (int i = 0;str[i] != '\0';i++) {
		if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ||
			str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
		{
			count++;
		}
	}
	cout << count << endl;
}
	int main() {
		char s[100];
		cout << "enter string :" << endl;
		cin.getline(s, 100);
		cout << "the number of vowels are :" << endl;
		vowel(s);
		return 0;
	}