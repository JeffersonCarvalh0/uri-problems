# include <iostream>
# include <string>

using namespace std;

int main() {

    int N;
    string texto;

    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; ++i) {
        getline(cin, texto);

        for (char &c : texto)
            if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
                c += 3;

        char aux;
        for (size_t i1 = 0, i2 = texto.size() - 1; i1 < texto.size()/2; ++i1, --i2) {
            aux = --texto[i1];
            texto[i1] = texto[i2];
            texto[i2] = aux;
        }

        if (texto.size() & 1)
            --texto[texto.size()/2];

        cout << texto << '\n';
    }

    return 0;
}
