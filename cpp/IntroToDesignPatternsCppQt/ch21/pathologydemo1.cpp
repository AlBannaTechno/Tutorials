#include <iostream>

int main() {
    int *jp = new int(13);
    std::cout << jp << '\t' << *jp << std::endl;
    delete jp;
//  delete jp;  // why?! Commented out because this will corrupt the rest of the memory
    jp = new int(3);
    std::cout << jp << '\t' << *jp << std::endl;
    jp = new int(10);  // NOOOOOOoOOoOOoooOOoooOOOOoooOOOooOOOO
    std::cout << jp << '\t' << *jp << std::endl;
    int *kp = new int(17);
    std::cout << kp << '\t' << *kp << std::endl;

    return 0;
}
