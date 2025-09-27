#include <iostream>
#include <string>
#include "f.h"
using namespace std;

int main () {
    string first;
    cout << "Enter string: ";
    cin >> first;
    
    string second = replaceLetters(first);
    cout << "Result: " << second << endl;

    return 0;   
}