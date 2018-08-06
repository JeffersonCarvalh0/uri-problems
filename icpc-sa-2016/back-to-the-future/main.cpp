# include <iostream>
# include <vector>
# include <list>
# include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b, v1, v2, ans;
    set<pair<int, int>> s;

    cin >> n >> m >> a >> b;
    vector<list<int>> adj_list(n);
    vector<int> deg(n);
    vector<bool> inset(n, true);

    while (m--) {
        cin >> v1 >> v2; --v1; --v2;
        adj_list[v1].push_back(v2); adj_list[v2].push_back(v1);
        ++deg[v1]; ++deg[v2];
    }

    for (int i = 0; i < n; ++i) s.insert({ deg[i], i });

    bool erased_first, erased_second; erased_first = erased_second = true;
    int cur;
    ans = n;
    while ((erased_first || erased_second) && !s.empty()) {
        erased_first = false; erased_second = false;
        cur = s.begin()->second;
        if (deg[cur] < a || ans - (deg[cur] + 1) < b) {
            s.erase(s.begin()); --ans; inset[cur] = false;
            for (auto adj : adj_list[cur])
                if (inset[adj]) {
                    s.erase({ deg[adj], adj });
                    --deg[adj];
                    s.insert({ deg[adj], adj });
                }
            erased_first = true;
        }

        if (!s.empty()) {
            cur = prev(s.end())->second;
            if (deg[cur] < a || ans - (deg[cur] + 1) < b) {
                s.erase(prev(s.end())); --ans; inset[cur] = false;
                for (auto adj : adj_list[cur])
                    if (inset[adj]) {
                        s.erase({ deg[adj], adj });
                        --deg[adj];
                        s.insert({ deg[adj], adj });
                    }
                erased_second = true;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
