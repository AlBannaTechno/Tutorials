// namesp.h
#include <string>

// create the pers and debts namespaces
namespace pers {
    struct Person {
        std::string fname;
        std::string lname;
    };
    void getPerson(Person &rp);
    void showPerson(const Person &rp);
}

namespace debts {
    using namespace pers;
    struct Debt {
        Person name;
        double amount;
    };
    void getDebt(Debt &rd);
    void showDebt(const Debt &rd);
    double sumDebts(const Debt ar[], int n);
}
