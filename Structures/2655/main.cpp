# include <iostream>
# include <vector>
# include <bitset>

using namespace std;

class Node {
public:
    bitset<64> types;
    int num_types, total_types;

    Node(int total_types) : total_types(total_types) {
        num_types = 0;
    }

    void insert(int type) {
        if (!types[type]) { types[type] = true; ++num_types; }
    }

    Node operator + (const Node &rhs) {
        Node node(num_types);
        for (int i = 0; i <= total_types; ++i) {
            if (types[i] || rhs.types[i]) node.insert(i);
        }
        return node;
    }

    void operator += (const Node &rhs) { *this = *this + rhs; }

    void operator = (const Node &rhs) { types = rhs.types; num_types = rhs.num_types; }
};

class SegTree {
private:
    vector<Node> tree;
    int n, total_types;

public:
    SegTree(int *arr, int n, int total_types) : n(n), total_types(total_types) {
        tree = vector<Node>(n * 2, Node(total_types));

        // Leaves
        for (int i = 0; i < n; ++i) {
            tree[n + i] = Node(total_types);
            tree[n + i].insert(arr[i]);
        }

        // Internal nodes
        for (int i = n - 1; i > 0; --i) { tree[i] = tree[i<<1] + tree[i<<1|1]; }
    }

    int query(int l, int r) {
        Node node(total_types);
        for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) node += tree[l++];
            if (!(r & 1)) node += tree[r--];
        }
        return node.num_types;
    }

    void modify(int p, int type) {
        Node node(total_types); node.insert(type);
        for (tree[p += n] = node; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q, M, *road, type, l, r;

    cin >> N >> Q >> M;

    road = new int[N];
    for (int i = 0; i < N; ++i) cin >> road[i];
    auto tree = SegTree(road, N, M);

    while (Q--) {
        cin >> type >> l >> r;

        if (type == 1) cout << tree.query(--l, --r) << '\n';
        if (type == 2) tree.modify(--l, r);
    }

    return 0;
}
