# include <iostream>
# include <vector>

typedef unsigned long long ul;

using namespace std;

ul max(ul a, ul b) { return a > b ? a : b; }
ul min(ul a, ul b) { return a < b ? a : b; }

class Node {
public:
    ul maxPrice, minPrice, diff;

    Node(ul value = 0) { maxPrice = minPrice = diff = value; }

    Node operator - (const Node &rhs) {
        Node node;
        node.maxPrice = max(maxPrice, rhs.maxPrice);
        node.minPrice = min(minPrice, rhs.minPrice);
        node.diff = node.maxPrice - node.minPrice;
        return node;
    }

    void operator = (const Node &rhs) {
        maxPrice = rhs.maxPrice;
        minPrice = rhs.minPrice;
        diff = rhs.diff;
    }

    void operator -= (const Node &rhs) { *this = *this - rhs; }
};

class SegTree {
public:
    vector<Node> tree;
    int n;

    SegTree(const ul *arr, const ul n) : n(n) {
        tree = vector<Node>(n * 2, Node());
        for (ul i = 0; i < n; ++i) tree[i + n] = Node(arr[i]);
        for (ul i = n - 1; i > 0; --i) tree[i] = tree[i<<1] - tree[i<<1|1];
    }

    int query(ul l, ul r) {
        Node node;
        node.minPrice = 1e6;
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) node -= tree[l++];
            if (!(r & 1)) node -= tree[r--];
        }
        return node.diff;
    }

    void modify(ul p, ul value) {
        for (tree[p += n] = Node(value); p > 1; p >>= 1) tree[p>>1] = tree[p] - tree[p^1];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ul N, P[ul(1e6)], Q, op, l, r;

    while(cin >> N) {
        for (ul i = 0; i < N; ++i) cin >> P[i];
        auto tree = SegTree(P, N);
        cin >> Q;

        while (Q--) {
            cin >> op >> l >> r;
            if (op == 1) tree.modify(--l, r);
            if (op == 2) cout << tree.query(--l, --r) << '\n';
        }
    }
    return 0;
}
