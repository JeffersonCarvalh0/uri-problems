# include <iostream>
# include <algorithm>
# include <set>

using namespace std;

enum Notes {
    Do = 0, Dos, Re, Res, Mi, Fa, Fas, Sol, Sols, La, Las, Si
};

Notes d[7] = { Do, Re, Mi, Fa, Sol, La, Si };
Notes ds[7] = { Dos, Res, Fa, Fas, Sols, Las, Do };
Notes re[7] = { Re, Mi, Fas, Sol, La, Si, Dos };
Notes res[7] = { Res, Fa, Sol, Sols, Las, Do, Re };
Notes mi[7] = { Mi, Fas, Sols, La, Si, Dos, Res };
Notes fa[7] = { Fa, Sol, La, Las, Do, Re, Mi };
Notes fas[7] = { Fas, Sols, Las, Si, Dos, Res, Fa };
Notes sol[7] = { Sol, La, Si, Do, Re, Mi, Fas };
Notes sols[7] = { Sols, Las, Do, Dos, Res, Fa, Sol };
Notes la[7] = { La, Si, Dos, Re, Mi, Fas, Sols };
Notes las[7] = { Las, Do, Re, Res, Fa, Sol, La };
Notes si[7] = { Si, Dos, Res, Mi, Fas, Sols, Las };

inline bool check_tune(set<Notes> &song, int n, Notes *scale) {
    for (auto &note : song)
        if (find(scale, scale + 7, note) == scale + 7) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, cur;
    set<Notes> song;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> cur, song.insert(Notes((cur - 1) % 12));

    int tune = -1;
    if (check_tune(song, n, d)) tune = Do;
    else if (check_tune(song, n, ds)) tune = Dos;
    else if (check_tune(song, n, re)) tune = Re;
    else if (check_tune(song, n, res)) tune = Res;
    else if (check_tune(song, n, mi)) tune = Mi;
    else if (check_tune(song, n, fa)) tune = Fa;
    else if (check_tune(song, n, fas)) tune = Fas;
    else if (check_tune(song, n, sol)) tune = Sol;
    else if (check_tune(song, n, sols)) tune = Sols;
    else if (check_tune(song, n, la)) tune = La;
    else if (check_tune(song, n, las)) tune = Las;
    else if (check_tune(song, n, si)) tune = Si;

    switch (tune) {
        case -1: cout << "desafinado"; break;
        case Do: cout << "do"; break;
        case Dos: cout << "do#"; break;
        case Re: cout << "re"; break;
        case Res: cout << "re#"; break;
        case Mi: cout << "mi"; break;
        case Fa: cout << "fa"; break;
        case Fas: cout << "fa#"; break;
        case Sol: cout << "sol"; break;
        case Sols: cout << "sol#"; break;
        case La: cout << "la"; break;
        case Las: cout << "la#"; break;
        case Si: cout << "si"; break;
    }

    cout << '\n';

    return 0;
}
