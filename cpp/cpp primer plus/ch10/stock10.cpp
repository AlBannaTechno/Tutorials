// stock10.cpp -- Stock class with constructors and destructor added
#include <iostream>
#include "stock10.h"

// constructors (verbose versions)
Stock::Stock() {  // default constructor
    std::cout << "Default constructor called.\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr) {
    std::cout << "Constructor using " << co << " called\n";
    company = co;

    if (n < 0) {
        std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock() {  // verbose class destructor
    std::cout << "Bye. " << company << "!\n";
}

// other methods
void Stock::buy(long num, double price) {
    if (num < 0)
        std::cout << "Number of shares purchased can't be negative. Transaction aborted.\n";
    else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    if (num < 0)
        std::cout << "Number of shares sold can't be negative. Transaction aborted.\n";
    else if (num > shares)
        std::cout << "You can't sell more shares than you have! Transaction aborted.\n";
    else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() {
    // set format to #.###
    std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::streamsize prec = std::cout.precision(3);

    std::cout << "Company: " << company << "  Shares: " << shares << "\n"
              << "  Share Price: $" << share_val;
    // set format to #.##
    std::cout.precision(2);
    std::cout << "  Total Worth: $" << total_val << "\n";

    // restore original format
    std::cout.setf(orig, std::ios_base::floatfield);
    std::cout.precision(prec);
}
