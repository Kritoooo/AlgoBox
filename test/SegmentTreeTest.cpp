#include "../include/data_structure/SegmentTree.h"
#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    SegmentTree st(1, n, SegmentTree::Operation::ADD);
    std::vector<int> data(n);
    for(int i = 0; i < n; i ++) {
        std::cin >> data[i];
        st.update(i + 1, i + 1, data[i]);
    }
    while(q --) {
        int op;
        std::cin >> op;
        if(op == 1) {
            int x, y, z;
            std::cin >> x >> y >> z;
            st.update(x, y, z);
        } else {
            int x, y;
            std::cin >> x >> y;
            std::cout << st.query(x, y) << "\n";
        }
    }
}

