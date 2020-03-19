// https://codeforces.com/problemset/problem/1228/B
// o problema consiste em descobrir a quantidade de célular não reservadas
#include <cstring>
#include <iostream>


#define MOD 1000000007


int r[1002], c[1002];
int fill(int m[][1002], int h, int w) {
    // preenchendo na horizontal:
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < r[i]; ++j) {
            if(m[i][j] == 0) {  // se n foi reservado
                m[i][j] = 'f';  // preenche (full)
            }
            else if(m[i][j]
                    == 'e') {  // se ja ta marcado como vazio, é inválido
                return 0;      // return invalido
            }
        }
        m[i][r[i]] = 'e';  // marcado para empty
    }

    // preenchendo verticalmente:
    for(int j = 0; j < w; ++j) {
        for(int i = 0; i < c[j]; ++i) {
            if(m[i][j] == 0) {
                m[i][j] = 'f';
            }
            else if(m[i][j] == 'e') {
                return 0;
            }
        }
        m[c[j]][j] = 'e';
    }

    int ans = 1;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(m[i][j] == 0)
                ans = (ans * 2) % MOD;
        }
    }

    return ans;
}

int main() {
    int h, w;
    std::cin >> h >> w;
    int m[1002][1002];
    memset(m, 0, sizeof m);

    for(int i = 0; i < h; ++i)
        std::cin >> r[i];
    for(int i = 0; i < w; ++i)
        std::cin >> c[i];

    int ans = fill(m, h, w);
    std::cout << ans << std::endl;

    return 0;
}
