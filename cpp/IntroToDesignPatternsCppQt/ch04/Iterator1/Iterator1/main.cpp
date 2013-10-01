#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtCore/QFileInfo>
#include <QtCore/QStringList>

void recurseAddDir(QDir d, bool recursive=true, bool syslinks=false);

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QDir dir = QDir::current();
    if (app.arguments().size() > 1)
        dir = app.arguments()[1];

    recurseAddDir(dir);
}

void recurseAddDir(QDir d, bool recursive, bool symlinks) {
    d.setSorting(QDir::Name);
    QDir::Filters df = QDir::Files | QDir::NoDotAndDotDot;

    if (recursive)
        df |= QDir::Dirs;
    if (not symlinks)
        df |= QDir::NoSymLinks;

    QStringList qsl = d.entryList(df, QDir::Name | QDir::DirsFirst);

    foreach (const QString &entry, qsl) {
        QFileInfo finfo(d, entry);
        if (finfo.isDir()) {
            QDir ad(finfo.absoluteFilePath());
            recurseAddDir(ad);
        }
        else
            if (finfo.completeSuffix() == "mp3")
                addMp3File(finfo.absoluteFilePath());
    }
}
