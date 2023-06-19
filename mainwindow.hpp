#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QTextStream>
#include <QFile>
#include <QCoreApplication>
#include <QRegularExpression>
#include <QDebug>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QStringList replaceText(QString str);
    void extractFromBin(QFile file);

private slots:
    void openFromFile();
    void saveToFile();
    void convertFile();
};
#endif // MAINWINDOW_HPP
