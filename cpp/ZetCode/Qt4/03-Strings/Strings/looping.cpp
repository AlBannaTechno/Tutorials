#include "strings.h"
#include <QtCore/QTextStream>


int looping() {
    QTextStream out(stdout);
    QString str = "There are many stars.";
    
    foreach (QChar qc, str) 
        out << qc << " ";
    
    out << endl;
    
    for (QChar *iter = str.begin(); iter != str.end(); ++iter) 
        out << *iter << " ";
    
    out << endl;
    
    for (int i = 0; i < str.size(); ++i) 
        out << str.at(i) << " ";
    
    out << endl;
    
    return 0;
}
