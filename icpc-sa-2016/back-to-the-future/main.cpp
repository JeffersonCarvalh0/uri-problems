// Not done yet

# include <iostream>
# include <vector>
# include <list>
# include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b, v1, v2, ans;
    set<pair<int, int>> s;

    cin >> n >> m >> a >> b
    vector<list<int>> adj_list(n);
    vector<int> deg(n);
    ans = 0;

    while (m--) {
        cin >> v1 >> v2; --v1; --v2;
        adj_list[v1].push_back(v2); adj_list[v2].push_back(v1);
        ++deg[v1]; ++deg[v2];
    }

    for (int i = 0; i < n; ++i) s.insert({ deg[i], i });

    bool finished = false;
    int cur;
    ans = n;
    while (!finished && !s.empty()) {
        cur = s.begin()->second;
        if (adj_list[cur].size() < a || n - (adj_list[cur] + 1) < b) {
            s.erase(s.begin()); --ans;
            for (auto adj : adj_list[cur]) --deg[adj], s.erase()
        }

        cur = prev(s.end())->second;
        if (adj_list[cur].size() < a || n - (adj_list[cur] + 1) < b) {
            s.erase(prev(s.end())); --ans;
        }
    }

    cout << ans << '\n';

    return 0;
}
