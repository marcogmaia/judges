#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
    std::string str = "testando";
    std::vector<int> vec(10);

    for(size_t i = 0; i < vec.size(); ++i) {
        vec[i] = i;
    }

    for(int i = 0; i < 10; vec[i++]++) {
    }

    for(std::vector<int>::iterator p = vec.begin(); p != vec.end(); ++p) {
        std::cout << *p;
    }

    std::cout << str << std::endl;
    std::cout
        << "a string está fazendo uso de wchar para a criação dos caracteres."
        << std::endl;
    std::cout << vec.size() << std::endl;

    return 0;
}
