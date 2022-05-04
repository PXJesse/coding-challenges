#include <iostream>
#include <string>

using namespace std;

string reformatNumber(string number);

int main() {
    string input = "123 4-5678";
    string output = reformatNumber(input);
    cout << output;

    return 0;
}


/**
 * @brief Reformat a phone number string.
 * 
 * Runtime: 2ms
 * Memory: 6.2mb
 * 
 * @param number the given phone number string
 * @returns string the phone number after formatting
 */
string reformatNumber(string number) {
    string numOnly;
    string result;
    int numLength;
    int i = 0;

    // 1. Remove all dashes and spaces
    for (char& c: number) {
        if (isdigit(c)) {
            numOnly += c;
        }
    }
    numLength = numOnly.length();

    // 2. Group in blocks of three digits until <= 4 digits left
    while (i < numLength - 4) {
        result += numOnly.substr(i, 3) + "-";
        i += 3;
    }

    // 3. Format final digits
    int n_left = numLength - i;
    if (n_left == 4) {
        result += numOnly.substr(i, 2) + "-" + numOnly.substr(i + 2, 2);
    } else {
        result += numOnly.substr(i, n_left);
    }

    return result;
}
