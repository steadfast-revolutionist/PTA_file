#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int address = 0;
    int data = 0;
    int next = 0;
};

int main()
{
    int start = 0, len = 0, key = 0;

    scanf("%d %d %d", &start, &len, &key);

    vector<Node> input(len);

    for_each(input.begin(), input.end(),
             [](Node &item)
             { scanf("%d %d %d", &item.address, &item.data, &item.next); });

    vector<vector<Node>::iterator> list(len);

    for (auto& item : list) {
        auto ptr = find_if(input.begin(), input.end(),
                           [start](const Node &i)
                           { return i.address == start; });
        item = ptr;
        start = ptr->next;
    }

    reverse(list.begin(), list.begin() + key);

    for_each(list.begin(), list.end() - 1,
             [](vector<Node>::iterator &ptr)
             { ptr->next = (*(&ptr + 1))->address; });

    for (const auto& item : list) {
        printf("%05d %d ", item->address, item->data);
        if (item->next == -1) {
            puts("-1");
        } else {
            printf("%05d\n", item->next);
        }
    }

    return 0;
}
