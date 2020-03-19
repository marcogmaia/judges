// https://codeforces.com/problemset/problem/1231/C
#include <iostream>

int max_in_between(int dr, int dl) {  // top down left right
    for(int m = dr - 1; m > dl; --dr) {
        return m;
    }
    return -1;  // valor impossível
}


int main() {
    int r, c;
    std::cin >> r >> c;

    int matrix[r][c];

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int min_dr = 8002;                // diag right
    int max_dl = -1;                  // diag left
    for(int i = r - 2; i > 0; --i) {  // começa da penultima linha e vai até 1
        // fazemos as checagens de trás pra frente
        // porque assim garantimos que sempre estaremos
        // atribuindo o maior valor possível
        for(int j = c - 2; j > 0; --j) {
            if(matrix[i][j] == 0) {
                max_dl = std::max(matrix[i - 1][j], matrix[i][j - 1]);
                min_dr = std::min(matrix[i + 1][j], matrix[i][j + 1]);
                int m = max_in_between(min_dr, max_dl);
                // se for impossível atribuir um valor, para a execução print -1
                if(m == -1) {
                    std::cout << -1 << std::endl;
                    return 0;
                }
                matrix[i][j] = m;
            }
        }
    }

    bool is_increasing = true;
    // compare row
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c - 1; j++) {
            if(matrix[i][j] >= matrix[i][j+1] )
                is_increasing = false;
        }
    }

    // compare column
    for(int i = 0; i < r - 1; ++i) {
        for(int j = 0; j < c; j++) {
            if(matrix[i][j] >= matrix[i+1][j])
                is_increasing = false;
        }
    }

    if(is_increasing) {
        int sum = 0;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; j++) {
                sum += matrix[i][j];
            }
        }

        std::cout << sum << std::endl;
    }
    else {
        std::cout << -1 << std::endl;
    }


    return 0;
}
