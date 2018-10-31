#include <iostream>
#include <algorithm>

#define NMAX 51
#define INF 0x3f3f3f3f

int main(int argc, char const *argv[]) {
    int n, m;
    // n == number of childrens
    // m == number of puzzles
    std::cin >> n >> m;
    // v[i] == number of pieces of puzzle_i
    int *v = new int[NMAX];

    for(int i = 0; i < m; ++i)
        std::cin >> v[i];
    std::sort(v, v+m);

    int minimum = INF;

    for(int i = 0; i <= m - n; ++i)
        minimum = std::min(v[i+n-1] - v[i], minimum);
    std::cout << minimum << std::endl;

    delete[] v;    
    return 0;
}
