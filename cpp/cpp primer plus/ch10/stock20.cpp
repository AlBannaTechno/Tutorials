// stock20.cpp -- augmented version
#include <iostream>
#include "stock20.h"

// constructors
Stock::Stock() {  // default constructor
    company = "no name";
    shares = 0;
    share_val = 0;
    total_val = 0;
}

Stock::Stock(const std::string &co, long n, double pr) {
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
Stock::~Stock() {}  // quiet class destructor

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
        std::cout << "You can't sell more than you have! Transaction aborted.\n";
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

void Stock::show() const {
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

const Stock &Stock::topval(const Stock &s) const {
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}
