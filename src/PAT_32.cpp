#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int key = 0;
    int mapped = 0;
};

int main()
{
    int length = 0;

    scanf("%d", &length);

    vector<Node> map(length);

    for (Node& item : map) {
        scanf("%d %d", &item.key, &item.mapped);
    }

    sort(map.begin(), map.end(),
         [](const Node &node1, const Node &node2)
         { return node1 > node2; });

    auto head = map.begin(), tail = map.begin();


    return 0;
}

inline bool
operator > (const Node& self, const Node& other) {
    return ((self.key != other.key) ? (self.key > other.key) : (self.mapped > other.mapped));
}
