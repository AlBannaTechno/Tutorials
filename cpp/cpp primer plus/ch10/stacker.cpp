// stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype>
#include "stack.h"

int main() {
    Stack st;  // create an empty stack
    char ch;
    unsigned long po;

    std::cout << "Please enter A to add a purchase order,\n"
              << "P to process a PO, or Q to quit.\n";

    while (std::cin >> ch && std::toupper(ch) != 'Q') {
        while (std::cin.get() != '\n')
            continue;

        if (!isalpha(ch)) {
            std::cout << "\a";
            continue;
        }

        switch (ch) {
            case 'A':
            case 'a':
                std::cout << "Enter a PO number to add: ";
                std::cin >> po;
                if (st.isfull())
                    std::cout << "stack already full\n";
                else
                    st.push(po);
                break;

            case 'P':
            case 'p':
                if (st.isempty())
                    std::cout << "stack already empty\n";
                else {
                    st.pop(po);
                    std::cout << "PO #" << po << " popped\n";
                }
                break;
        }

        std::cout << "Please enter A to add a purchase order,\n"
                  << "P to process a PO, or Q to quit.\n";
    }

    std::cout << "Bye\n";
    return 0;
}
