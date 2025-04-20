#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void count() {
    ifstream file("data.txt");
    string word;
    int count = 0;

    if (file.is_open()) {
        while (file >> word) {
            count++;
        }
        file.close();
        cout << "Total number of words: " << count << endl;
    }
    else {
        cout << "error in file opening" << endl;
    }
}
    int main() {
        count();
    return 0;
}
