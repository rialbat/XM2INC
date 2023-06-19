#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->inputPushButton, SIGNAL(clicked()), this, SLOT(openFromFile()));
    connect(ui->outputPushButton, SIGNAL(clicked()), this, SLOT(saveToFile()));
    connect(ui->processPushButton, SIGNAL(clicked()), this, SLOT(convertFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::replaceText(QString str)
{
    //str = "Some text with hex values like 0x12, 0xA3, 0xFF etc.";
    QStringList hexBuffer;
    QRegularExpression pattern("(0x[0-9A-Fa-f]+)");
    QRegularExpressionMatchIterator i = pattern.globalMatch(str);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(1);
        word.remove(0, 2); // remove "0x"
        word = word.toUpper(); // make it uppercase
        word.prepend("0"); // prepend "0"
        word.append("h"); // append "h"
        hexBuffer.append(word);
    }

    return hexBuffer;
}

void MainWindow::extractFromBin(QFile file)
{
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return;
    }

    QByteArray byteBuffer = file.readAll();
    uint byteBufferSize = byteBuffer.size();
    QString hexBuffer = byteBuffer.toHex();
    QString formattedString;

    formattedString.append("xm_length EQU " + QString::number(byteBufferSize) + "\n");
    formattedString.append("xm LABEL BYTE\n");
    formattedString.append("	db ");
    for (int i = 0; i < hexBuffer.length(); i += 2) {
       formattedString.append("0");
       formattedString.append(hexBuffer.mid(i, 2).toUpper());
       formattedString.append("h,");
       if ((i / 2 + 1) % 16 == 0) {
           formattedString.chop(1);
           formattedString.append("\n	db ");
       }
    }

       // Remove the trailing comma
       if (!formattedString.isEmpty()) {
           formattedString.chop(1);
       }
       QFile outFile(ui->outputLineEdit->text());
       if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
           qDebug() << outFile.errorString();
           return;
       }

       QTextStream out(&outFile);
       out << formattedString;

       outFile.close();

       file.close();
}

void MainWindow::openFromFile()
{
    QString filterOption("XM Files (*.xm)");
    QString fileName = QFileDialog::getOpenFileName(0, "Open File", QCoreApplication::applicationDirPath(),
                                                    "XM Files (*.xm);;All Files (*.*)", &filterOption);
    ui->inputLineEdit->setText(fileName);
}

void MainWindow::saveToFile()
{
    QString filterOption("INC Files (*.inc)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save File", QCoreApplication::applicationDirPath(),
                                                    "INC Files (*.inc);;All Files (*.*)", &filterOption);
    ui->outputLineEdit->setText(fileName);
}

void MainWindow::convertFile()
{
    if (ui->inputLineEdit->text() != "" && ui->outputLineEdit->text() != ""){
        if (ui->XMRadioButton->isChecked()){
            extractFromBin(QFile(ui->inputLineEdit->text()));
        }
        else{
            QFile inputFile(ui->inputLineEdit->text());
            QFile outFile(ui->outputLineEdit->text());
            QTextStream in(&inputFile);
            QStringList lines;
            if(!inputFile.open(QIODevice::ReadOnly)){
               qDebug() << inputFile.errorString();
               return;
            }

            while (!in.atEnd()) {
                lines.append(replaceText(in.readLine()));
            }

            if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
                qDebug() << outFile.errorString();
                return;
            }
            QTextStream out(&outFile);
            out << "xm_length EQU " + QString::number(lines.count()) + "\n";
            out << "xm LABEL BYTE\n";
            out << "	db ";
            for (int i = 0; i < lines.count(); i ++) {
                if ((i+1) % 16 == 0) {
                    out << lines[i];
                    out << "\n	db ";
                    //continue;
                }
                else if (i + 1 == lines.count()){
                    out << lines[i];
                    //continue;
                }
                else
                {
                    out << lines[i] + ",";
                }
            }

            outFile.close();
        }
    }

}
