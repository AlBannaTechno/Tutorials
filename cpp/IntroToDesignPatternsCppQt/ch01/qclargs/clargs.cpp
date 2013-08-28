#include <QTextStream>
#include <QCoreApplication>
#include <QStringList>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    QTextStream cout(stdout);
    QStringList arglist = app.arguments();

    cout << "argc = " << argc << endl;
    for (int i = 0; i < arglist.size(); i++)
        cout << QString("arg#%1 is %2").arg(i).arg(arglist[i]) << endl;

    int num = arglist[argc - 1].toInt();
    cout << num * 2 << endl;

    return EXIT_SUCCESS;
}
