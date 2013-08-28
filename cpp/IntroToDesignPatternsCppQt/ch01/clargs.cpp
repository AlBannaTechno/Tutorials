#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    std::cout << "argc = " << argc << std::endl;

    for (int i = 0; i < argc; i++)
        std::cout << "argv# " << i << " is " << argv[i] << std::endl;

    int num = std::atoi(argv[argc - 1]);
    std::cout << num * 2 << std::endl;

    return 0;
}
