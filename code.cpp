#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string generatePassword(int length, bool useUpper, bool useDigits, bool useSymbols) {
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string symbols = "!@#$%^&*";

    string all = lower;
    if (useUpper) all += upper;
    if (useDigits) all += digits;
    if (useSymbols) all += symbols;

    string password = "";
    for (int i = 0; i < length; i++) {
        password += all[rand() % all.size()];
    }
    return password;
}

int main() {
    srand(time(0));

    int length;
    char upper, digits, symbols;

    cout << "Enter password length: ";
    cin >> length;

    cout << "Include uppercase? (y/n): ";
    cin >> upper;

    cout << "Include digits? (y/n): ";
    cin >> digits;

    cout << "Include symbols? (y/n): ";
    cin >> symbols;

    string pass = generatePassword(length,
                                   upper == 'y',
                                   digits == 'y',
                                   symbols == 'y');

    cout << "\nGenerated Password: " << pass << endl;
    return 0;
}
