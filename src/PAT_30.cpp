
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int len = 0, key = 0, count = 0;

    scanf("%d %d", &len, &key);

    vector<int> vec(len);

    for_each(vec.begin(), vec.end(),
             [](int &item)
             { scanf("%d", &item); });

    sort(vec.begin(), vec.end());

    for (auto max = vec.end() - 1; max != vec.begin(); --max) {
        if (count >= max - vec.begin() + 1) {
            break;
        }

        auto split = find_if(vec.begin(), vec.end(),
                             [max, key](const int &value)
                             { return key * value >= *max; });

        int phase = max - split  + 1;

        count = (count > phase) ? count : phase;
    }

    printf("%d\n", count);

    return 0;
}
