# include <cstdio>
# include <stack>
# include <vector>
# include <algorithm>   // std::binary_search

using namespace std;

int main() {

    char c;

    bool antEsp = false;

    stack<char> parenteses;
    stack<char> outros;

    int contadorFechados = 0;

    char esp[] = {'#', '*', '+', '-', '.', '/', '<', '=', '>', '^', '|'};
    vector<char> especiais(esp, esp + sizeof(esp) / sizeof(char));

    while (scanf("%c", &c)) {
        if (binary_search(especiais.begin(), especiais.end(), c)) {
            if (antEsp) {
                printf("Syntax Error!\n");
                return 0;
            } else {
                outros.push(c);
                antEsp = true;
            }
        } else if (c == '(' || c == ')') {
            parenteses.push(c);
        } else if (c == '\n') {
            break;
        } else if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))) {
            outros.push(c);
            antEsp = false;
        } else {
            printf("Lexical Error!\n");
            return 0;
        }
        // printf("Caractere processado: %c\n", c);
    }

    while (!parenteses.empty()) {
        // printf("Processando parênteses...\n");
        if (parenteses.top() == '(' && contadorFechados == 0) {
            printf("Syntax Error!\n");
            return 0;
        } else if (parenteses.top() == ')')
            ++contadorFechados;
        else
            --contadorFechados;
        parenteses.pop();
    }

    if (contadorFechados > 0) {
        // printf("Processando parênteseAs/parte 2\n");
        printf("Syntax Error!\n");
        return 0;
    }

    return 0;
}
