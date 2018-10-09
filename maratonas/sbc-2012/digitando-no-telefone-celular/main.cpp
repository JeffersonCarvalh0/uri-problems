# include <iostream>
# include <iomanip>
# include <string>
# include <cstring>

using namespace std;

struct Node {
    int child_num;
    bool word;
    Node *alpha[26];

    Node() {
        word = false; child_num = 0;
        for (int i = 0; i < 26; ++i) alpha[i] = nullptr;
    }
};

class Trie {
public:
    Node *root;

    Trie() { root = nullptr; }

    void insert(string &s) {
        if (root == nullptr) root = new Node();
        Node *cur = root;

        for (auto &ch : s) {
            int pos = int(ch - 'a');
            if (cur->alpha[pos] == nullptr) {
                cur->alpha[pos] = new Node();
                ++cur->child_num;
            }
            cur = cur->alpha[pos];
        }
        cur->word = true;
    }

    int count(string &s) {
        Node *cur = root;
        int n = 1;

        for (auto &ch : s) {
            int pos = int(ch - 'a');
            cur = cur->alpha[pos];
            if (cur->word || cur->child_num > 1) ++n;
        }

        return --n;
    }

    void removeNode(Node *node) {
        for (int i = 0; i < 26; ++i) if (node->alpha[i] != nullptr) removeNode(node->alpha[i]);
        delete node;
    }

    void clear() {
        if (root != nullptr) removeNode(root);
        root = nullptr;
    }

    ~Trie() {
        clear();
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.setf(ios::fixed);

    double n, mean;
    string dict[100005];
    Trie trie;

    while (cin >> n) {
        trie.clear();
        for (int i = 0; i < n; ++i) cin >> dict[i], trie.insert(dict[i]);

        mean = 0.0;
        for (int i = 0; i < n; ++i) mean += trie.count(dict[i]);
        mean /= n;

        cout << setprecision(2) << mean << '\n';
    }

    return 0;
}
