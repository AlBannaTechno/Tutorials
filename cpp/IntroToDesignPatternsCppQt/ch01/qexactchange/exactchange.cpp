#include <QTextStream>
#include <QString>

struct change_types {
    int penny, nickel, dime, quarter, loonie, toonie,
        bill_5, bill_10, bill_20, bill_50, bill_100,  bill_1000;
};

int main() {
    QTextStream cout(stdout);
    QTextStream cin(stdin);
    QTextStream cerr(stderr);

    double price, payment, change;
    int dollars, cents;
    change_types full_change;
    QString input, output;

    cout << "== Exact Change ==\n"
         << "This program will display exact change for given amounts.\n\n";

    cout << "Please enter the total price: $" << flush;
    input = cin.readLine();
    price = input.toDouble();

    cout << "Please enter the amount given for payment: $" << flush;
    input = cin.readLine();
    payment = input.toDouble();

    change = payment - price;
    dollars = static_cast<int>(change);
    cents = static_cast<int>(change * 100) % 100;
    cout << "Change: " << change << endl;

    full_change.bill_1000 = dollars / 1000;
    dollars %= 1000;
    full_change.bill_100 = dollars / 100;
    dollars %= 100;
    full_change.bill_50 = dollars / 50;
    dollars %= 50;
    full_change.bill_20 = dollars / 20;
    dollars %= 20;
    full_change.bill_10 = dollars / 10;
    dollars %= 10;
    full_change.bill_5 = dollars / 5;
    dollars %= 5;

    full_change.toonie = dollars / 2;
    dollars %= 2;
    full_change.loonie = dollars / 1;
    dollars %= 1;
    full_change.quarter = cents / 25;
    cents %= 25;
    full_change.dime = cents / 10;
    cents %= 10;
    full_change.nickel = cents / 5;
    cents %= 5;
    full_change.penny = cents / 1;
    cents %= 1;

    if (dollars != 0 || cents != 0) {
        cerr << "Error: $" << dollars << "." << cents << " was somehow left over";
        return EXIT_FAILURE;
    }

    output = "Full change:\n";
    if (full_change.bill_1000 != 0)
        output += QString("%1 1000$ bill(s)\n").arg(full_change.bill_1000);
    if (full_change.bill_100 != 0)
        output += QString("%1 100$ bill(s)\n").arg(full_change.bill_100);
    if (full_change.bill_50 != 0)
        output += QString("%1 50$ bill(s)\n").arg(full_change.bill_50);
    if (full_change.bill_20 != 0)
        output += QString("%1 20$ bill(s)\n").arg(full_change.bill_20);
    if (full_change.bill_10 != 0)
        output += QString("%1 10$ bill(s)\n").arg(full_change.bill_10);
    if (full_change.bill_5 != 0)
        output += QString("%1 5$ bill(s)\n").arg(full_change.bill_5);

    if (full_change.toonie != 0)
        output += QString("%1 toonie(s)\n").arg(full_change.toonie);
    if (full_change.loonie != 0)
        output += QString("%1 loonie(s)\n").arg(full_change.loonie);
    if (full_change.quarter != 0)
        output += QString("%1 quarter(s)\n").arg(full_change.quarter);
    if (full_change.dime != 0)
        output += QString("%1 dime(s)\n").arg(full_change.dime);
    if (full_change.nickel != 0)
        output += QString("%1 nickel(s)\n").arg(full_change.nickel);
    if (full_change.penny != 0)
        output += QString("%1 penny(ies)\n").arg(full_change.penny);

    cout << output;

    return EXIT_SUCCESS;
}
