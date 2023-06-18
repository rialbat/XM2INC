#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFile inputFile("");
    QTextStream in(&inputFile);
    QStringList lines;

    ui->setupUi(this);

    if(!inputFile.open(QIODevice::ReadOnly)){
       qDebug() << inputFile.errorString();
       return;
   }

    while (!in.atEnd()) {
        QString line = in.readLine();
        lines.append(line);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replaceText(QString str)
{
    str = "Some text with hex values like 0x12, 0xA3, 0xFF etc.";
    QRegularExpression pattern("(0x[0-9A-Fa-f]+)");
    QRegularExpressionMatchIterator i = pattern.globalMatch(str);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(1);
        word.remove(0, 2); // remove "0x"
        word.append("h"); // append "h"
        word = word.toUpper(); // make it uppercase
        word.prepend("0"); // prepend "0"
        str.replace(match.captured(1), word);
    }

    qDebug() << str;
}
