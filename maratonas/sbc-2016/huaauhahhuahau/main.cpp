# include <iostream>
# include <string>

using namespace std;

inline bool is_vogal(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    bool funny = true;

    cin >> s;
    for (auto &c : s) if (is_vogal(c)) t += c;

    for (int i = 0; i <= t.size() / 2; ++i) {
        if (t[i] != t[t.size() - i - 1]) funny = false;
    }

    funny ? cout << "S\n" : cout << "N\n";

    return 0;
}
