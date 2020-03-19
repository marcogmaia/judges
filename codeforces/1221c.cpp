// https://codeforces.com/problemset/problem/1221/C
#include <iostream>

int main() {
    int q;
    std::cin >> q;
    while(q--) {
        int c, m, x;
        int pteams = 0;
        std::cin >> c >> m >> x;
        if(c != m) {
            int req = std::min(c, m);
            x += std::max(c, m) - req;
            c = m = req;
        }
        // a partir daqui C e M estao equalizados
        if(x <= c) {
            c = m = (c - x);
            pteams += x;
            pteams += (c + m) / 3;
        }
        else if(x > c) {
            pteams += c;
        }

        std::cout << pteams << std::endl;
    }
    return 0;
}
