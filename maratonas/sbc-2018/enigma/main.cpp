# include <iostream>
# include <string>

using namespace std;

int main() {
    string msg, crib;
    int ans = 0;

    cin >> msg >> crib;

    for (int i = 0; i <= (int)msg.size() - (int)crib.size(); ++i) {
        bool ok = true;
        for (int j = 0; j < (int)crib.size(); ++j) {
            if (crib[j] == msg[i + j]) { ok = false; break; }
        }
        if (ok) ++ans;
    }

    cout << ans << '\n';

    return 0;
}
