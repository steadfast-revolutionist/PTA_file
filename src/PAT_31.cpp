#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct Node {
    string str;
    bool sign = true;
};

map<int, char> set_map();
int average_mod(string &);

int main()
{
    int length = 0, count = 0;
    map<int, char> refer = set_map();

    cin >> length;

    vector<Node> input(length);

    for (Node& item : input) {
        cin >> item.str;
        int key = average_mod(item.str);
        if (refer[key] != item.str[17])
        {
            item.sign = false;
            ++count;
        }
    }

    if (count == 0) {
        cout << "All passed\n";
    } else {
        for_each(input.begin(), input.end(),
                 [](const Node &item)
                 { cout << ((item.sign) ? "" : (item.str + '\n')); });
    }

    return 0;
}

map<int, char> set_map() {
    map<int, char> temp({{2, 'X'}});

    for (int i = 3; i <= 10; i++) {
        temp[i] = '0' + (12 - i);
    }
    temp[0] = '1';
    temp[1] = '0';

    return temp;
}

int average_mod(string& str) {
    vector<int> weight = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    int ans = 0;

    for (int i = 0; i < 17; ++i) {
        ans += (str[i] - '0') * weight[i];
    }

    return ans % 11;
}
