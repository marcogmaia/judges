// http://codeforces.com/problemset/problem/71/A
#include <iostream>

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    while(n--) {
        std::string my_str;
        std::cin >> my_str;
        int word_length = my_str.length();
        if(word_length > 10) {
            std::cout << my_str.front() + std::to_string(word_length - 2)
                             + my_str.back()
                      << std::endl;
        }
        else {
            std::cout << my_str << std::endl;
        }
    }
    return 0;
}
