#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct tree {
    long long int key;
    long long int num;
    string lr;
    long long int low = LONG_LONG_MIN;
    long long int high = LONG_LONG_MAX;
};

int main() {
    ifstream in("bst.in");
    tree a;
    long long int count;
    in >> count;
    long long int root_key;
    in >> root_key;
    vector<tree> node(count);
    a.key = root_key;
    node[0] = a;
    ofstream out("bst.out");
    for (int i = 1; i < count; i++) {
        int f;
        in >> node[i].key;
        in >> node[i].num;
        in >> node[i].lr;
        if (node[i].lr == "L") {
            node[i].high = node[node[i].num - 1].key;
            node[i].low = node[node[i].num - 1].low;
        } else {
            node[i].low = node[node[i].num - 1].key;
            node[i].high = node[node[i].num - 1].high;
        }

        if (node[i].key >= node[i].low && node[i].key < node[i].high) {
            f = 1;
        } else
            f = 0;
        if (f == 0) {
            out << "NO" << '\n';
            return 0;
        }
    }
    out << "YES" << '\n';
    in.close();
    out.close();
}
