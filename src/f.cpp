#include <algorithm>
#include <string>
#include "f.h"
using namespace std;

std::string replaceLetters(std::string str) {

    replace(str.begin(), str.end(), 'a', 't');
    replace(str.begin(), str.end(), 'b', 'a');
    replace(str.begin(), str.end(), 't', 'b');

    return str;
}   
