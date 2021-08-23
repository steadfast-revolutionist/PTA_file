#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string broken, input;
    string output = "";

    getline(cin, broken);
    cin >> input;

    bool up_broken = find(broken.begin(), broken.end(), '+') != broken.end();

    for (const char& ch : input) {
        if (up_broken) {
            if (!isupper(ch) &&
                find(broken.begin(), broken.end(), toupper(ch)) == broken.end()) {
                output += ch;
            }
        } else {
            if (find(broken.begin(), broken.end(),
                toupper(ch)) == broken.end()) {
                output += ch;
            }
        }
    }

    for (const char& ch : output) {
        cout << ch;
    }
    cout << '\n';

    return 0;
}
