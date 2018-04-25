# include <iostream>
# include <list>

using namespace std;

inline void incrementIt(list<int> &l, list<int>::iterator &it) {
    if (it == prev(l.end()))
        it = l.begin();
    else
        ++it;
}

int main() {
    int NC,                         // Number of test cases
        n,                          // Number of people in the circle
        k,                          // Size of the step
        counter;                    // Counts from 0 to step

    list<int> alive;                // List that represents alive soldiers
    list<int>::iterator it;         // Iterator for alive
    list<int>::iterator toDelete;   // Iterator pointing to element to be deleted

    cin >> NC;
    for (int i = 1; i <= NC; ++i) { // Each loop for each test case
        alive.clear();
        cin >> n >> k;

        for (int j = 1; j <= n; ++j) // Fill the list with the soldiers
            alive.push_back(j);

        counter = 1;
        it = alive.begin();
        while (alive.size() > 1) { // Do the massacre
            if (counter == k) { // Removes the element and restarts the counting
                toDelete = it;
                incrementIt(alive, it);
                alive.erase(toDelete);
                counter = 1;
            } else {
                incrementIt(alive, it);
                ++counter;
            }
        }
        cout << "Case " << i << ": " << alive.front() << "\n";
    }

    return 0;
}
