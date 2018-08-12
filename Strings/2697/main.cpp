# include <iostream>
# include <map>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);

    int K, N, cur, max_key = 0, max_value_freq = 0, freqs[10000];
    map<int, int> count;
    for (int i = 0; i < 10000; ++i) freqs[i] = 0;

    for (auto &e : count) cout << e.first << ' ' << e.second << '\n';

    cin >> K >> N;
    for (int i = 0; i < N; ++i) {
        cin >> cur;
        if (count.find(cur) == count.end()) count[cur] = 1;
        else ++count[cur];
    }


    for (auto &e : count) {
        ++freqs[e.second];
        if (freqs[e.second] > max_value_freq) { max_value_freq = e.second; max_key = e.first; }
    }

    // count.erase(count.begin());
    for (auto &e : count) cout << e.first << ' ' << e.second << '\n';

    cout << "Count size: " << count.size() << '\n';
    cout << "max_value_freq: " << max_value_freq << '\n';

    if (count.size() - max_value_freq > 2) { cout << "*\n"; cout << "Enters first if\n"; }

    else if (count.size() - max_value_freq == 2 || count.size() - max_value_freq == 0) {
        cout << "Enters second if\n";
        int first_diff, second_diff;
        auto it = count.begin();
        if (count.size() - max_value_freq == 0) {
            int max_key = count.begin()->first;
            int min_key = count.begin()->first;
            for (auto &e : count) {
                if (e.second > count[max_key]) max_key = e.first;
                if (e.second < count[min_key]) min_key = e.first;
            }
        }
        cout << "Max key: " << max_key << '\n';
        for (; it != count.end(); ++it) if (it->second != count[max_key]) { first_diff = it->first; break; }
        ++it;
        for (; it != count.end(); ++it) if (it->second != count[max_key]) { second_diff = it->first; break; }

        cout << "First diff: " << first_diff << '\n';
        cout << "Second diff: " << second_diff << '\n';

        int biggest_diff = count[first_diff] > count[second_diff] ? first_diff : second_diff;
        int smallest_diff = count[first_diff] < count[second_diff] ? first_diff : second_diff;

        cout << "Count size: " << count.size() << '\n';
        for (auto &e : count) cout << e.first << ' ' << e.second << '\n';
        if (count.size() == 3) {
            cout << "ENTERED HERE\n";
            cout << "Biggest diff: " << biggest_diff << '\n';
            cout << "Smallest diff: " << smallest_diff << '\n';
            if (count[biggest_diff] - 1 == count[max_key] && count[smallest_diff] + 1 == count[max_key])
                cout << "-" << biggest_diff << " +" << smallest_diff << '\n';
            else cout << "*\n";
        } else {
            if (count[biggest_diff] - 1 == count[smallest_diff] + 1 && count[max_key] == count[biggest_diff] - 1 && count[max_key] == count[smallest_diff] + 1)
            cout << "-" << biggest_diff << " +" << smallest_diff << '\n';
        }
    }
    else if (count.size() - max_value_freq == 1) {
        for (auto &e : count) cout << e.first << ' ' << e.second << '\n';
        cout << "Enters third if\n";
        cout << "count[max_key] = " << count[max_key] << '\n';
        int diff;
        for (auto &e : count) { if (e.second != count[max_key]) { cout << e.first << ' ' << e.second << '\n'; diff = e.first; break; } }
        cout << "The different element is " << diff << '\n';
        if (count[diff] + 1 == count[max_key]) cout << "+" << diff << '\n';
        else if (count[diff] - 1 == count[max_key]) cout << "-" << diff << '\n';
        else cout << "*\n";
    }
    return 0;
}
