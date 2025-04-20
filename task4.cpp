#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void write(char str[100]) {

	ofstream file("output.txt");
	if (file.is_open()) {
		for (int i = 0;str[i] != '\0';i++) {
			file << str[i];
		}
		file.close();
	}
}
int main() {

	char s[100];
	cout << "enter string :" << endl;
	cin.getline(s, 100);
	cout << "the string saved successfully :" << endl;
	write(s);

	return 0;
}