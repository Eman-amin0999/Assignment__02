#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void character(char str[100]) {
	for(int i = 0;str[i] != '\0';i++){
		cout << str[i] << endl;
	
	}
}
int main() {

	char s[100];
	cout << "enter string :" << endl;
	cin.getline(s, 100);
	cout << "the characters are:" << endl;
	character(s);

	return 0;
}