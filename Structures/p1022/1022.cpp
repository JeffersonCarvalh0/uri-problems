# include <cstdio>

# define ABS(N) (N < 0) ? -(N) : (N)

inline void simplificar(int &Rn, int &Rd) {
    int menor = (Rn < Rd) ? Rn : Rd;
    int i = ABS(menor);

    while (i >= 2) {
        if (Rn % i == 0 && Rd % i == 0) {
            Rn /= i;
            Rd /= i;
        }
        --i;
    }
}

int main() {

    int N, Xn, Xd, Yn, Yd, Rn, Rd;
    char op;

    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        scanf("%d%*c%*c%*c%d%*c%c%*c%d%*c%*c%*c%d", &Xn, &Xd, &op, &Yn, &Yd); // stdio > iostream

        switch(op) {
            case '+':
                Rn = (Xn * Yd) + (Yn * Xd);
                Rd = Xd * Yd;
                break;
            case '-':
                Rn = (Xn * Yd) - (Yn * Xd);
                Rd = Xd * Yd;
                break;
            case '*':
                Rn = Xn * Yn;
                Rd = Xd * Yd;
                break;
            case '/':
                Rn = Xn * Yd;
                Rd = Xd * Yn;
                break;
        }
        printf("%d/%d = ", Rn, Rd);
        simplificar(Rn, Rd);
        printf("%d/%d\n", Rn, Rd);

    }
    return 0;
}
