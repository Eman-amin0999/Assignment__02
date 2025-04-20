#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void add() {
	int rollno;
	float gpa;
	string dep;
	string name;
	ofstream file("student.txt", ios::app);
	if (file.is_open()) {

		cout << "enter name:" << endl;
		cin.ignore();
		getline(cin,name);
		cout << "enter roll no. :" << endl;
		cin >> rollno;
		cout << "enter department name:" << endl;
		getline(cin, dep);
		cin.ignore();
		cout << "enter your GPA:" << endl;
		cin >> gpa;

		file << name << " " << rollno << " " << dep << " " << gpa << " " << endl;
		cout << "record add successfully" << endl;
		
	}
	file.close();
}
void showrecord() {
	ifstream file("student.txt");
	string s;
	if (file.is_open()) {
		while (getline(file, s)) {
			cout << s << endl;
		}
	}
	cout << "record show successfully" << endl;
	file.close();
}
void searchrollno() {
	int rollnotosearch;
	int rollno;
	float gpa;
	string depsearch;
	string namesearch;
	bool found = false;

	cout << "enter roll no to search:" << endl;
	cin >> rollnotosearch;

	ifstream search("student.txt");
	if (search.is_open()) {
		while (getline(search,namesearch)) {
			search >> namesearch >> rollno >> depsearch >> gpa;
			if (rollnotosearch == rollno) {
				found = true;
				break;
			}
		}
	}
		if (found == true) {
			cout << "Name: " << namesearch << " Roll No: " << rollno << " Department: " << depsearch << " GPA: " << gpa << endl;;
			cout << "data found successfuly" << endl;
		}
		else {
			cout << "Not Found" << endl;
		}
}
void update() {
	int rollnotoupdate;
	float newgpa;

	int oldrollno;
	float oldgpa;
	string depupdate;
	string nameupdate;
	bool found = false;
	cout << "enter roll no to update:" << endl;
	cin >> rollnotoupdate;
	
	ifstream searchGpa("student.txt");
	ofstream tempfile("temp.txt");

	if (searchGpa.is_open() && tempfile.is_open()) {
		while (searchGpa >> nameupdate >> oldrollno >> depupdate >> oldgpa) {

			if (rollnotoupdate == oldrollno) {
				cout << "enter GPA to update: " << endl;
				cin >> newgpa;
				tempfile << nameupdate << " " << oldrollno << " " << depupdate << " " << newgpa << endl;
				cout << nameupdate << " " << oldrollno << " " << depupdate << " " << newgpa << endl;
				found = true;
			}
			else {
				
				tempfile << nameupdate << " " << oldrollno << " " << depupdate << " " << oldgpa << endl;
			}
		}
	}
	            searchGpa.close();
	             tempfile.close();

			if (found) 
			{
				remove("student.txt");
				rename("temp.txt", "student.txt");
				cout << "GPA Updated Successfully" << endl;
			}
			else
			{
				remove("temp.txt");
				cout << "Enter Roll No. Not Found,GPA not updated. " << endl;
			}
}
void delRecord() {
	int rollnotodel;
	int rollnodel;
	float gpadel;
	string depdel;
	string namedel;
	bool found = false;

	cout << "enter roll no to search:" << endl;
	cin >> rollnotodel;
	ifstream file("student.txt");
	ofstream tempfile("temp.txt");

	if (file.is_open() && tempfile.is_open()) {
		while (file >> namedel >> rollnodel >> depdel >> gpadel) {
			if (rollnotodel != rollnodel) {
				tempfile << namedel << " " << rollnodel << " " << depdel <<  " " << gpadel << endl;
			}
			else {
				found = true;
			}

		}
		if (found) {
			remove("student.txt");
			rename("temp.txt", "student.txt");
			cout << "your record delete successfully" << endl;
		}
		else
		{
			remove("temp.txt");
			cout << "enter Roll No. not found" << endl;
		}
	}
			file.close();
			tempfile.close();
    }

int main() {
	while (true) {
		int n;
		cout << "menu" << endl;
		cout << "press 1 for add record " << endl;
		cout << "press 2 to show student record " << endl;
		cout << "press 3 for search student record " << endl;
		cout << "press 4 for update student record " << endl;
		cout << "press 5 for delete record " << endl;
		cout << "press 6 for break" << endl;
		cin >> n;

		if (n == 1)
		{
			add();
		}
		else if (n == 2)
		{
			showrecord();
		}
		else if (n == 3)
		{
			searchrollno();
		}
		else if (n == 4)
		{
			update();
		}
		else if (n == 5)
		{
			delRecord();
		}
		else if (n == 6)
		{
			break;
		}
	}
}