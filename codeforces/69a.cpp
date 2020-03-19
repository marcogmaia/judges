// https://codeforces.com/problemset/problem/69/A
#include <iostream>

int main() {
    int sumx = 0, sumy = 0, sumz = 0;
    int cnt;
    std::cin >> cnt;  // pegando a primeira linha

    while(cnt--) {    // fazendo cnt iterações
        int x, y, z;
        std::cin >> x >> y >> z;  // pegando o input de cada linha seguinte
        sumx += x;
        sumy += y;
        sumz += z;
    }

    // se todas as colunas forem 0 -> YES
    if((sumx == sumy) && (sumx == sumz) && (sumz == 0))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

    return 0;
}

