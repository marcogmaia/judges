#include <cstdio>
#include <string>
#include <vector>

int string_len(const char *str) {
    int i = 0;
    for(;*str;++str, ++i);
    return i;
}

int main(int argc, char const *argv[]) {
    // char my_str[] = "mas que coisa";
    printf("%d\n", string_len("noisqvoa"));
    return 0;
}
