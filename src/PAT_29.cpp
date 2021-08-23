
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void resort(string &);

int main()
{
    string stand, enter;

    cin >> stand;
    cin >> enter;

    resort(stand);
    resort(enter);

    cout << stand << '\n' << enter << '\n';

    auto ptr = stable_partition(stand.begin(), stand.end(),
                                [enter](auto iter)
                                { return find(enter.begin(), enter.end(),
                                              iter) == enter.end(); });

    stand.erase(ptr, stand.end());

    for_each(stand.begin(), stand.end(),
             [stand](auto iter)
             { cout << iter; });
    cout
        << '\n';

    return 0;
}

void resort(string& test)
{
    for (auto i = test.begin(); i != test.end(); ++i) {
        *i = toupper(*i);
    }

    stable_sort(test.begin(), test.end(),
                [test](const char &a, const char &b)
                { return find(test.begin(), test.end(), a) <
                         find(test.begin(), test.end(), b); });

    auto split = unique(test.begin(), test.end());

    test.erase(split, test.end());
}