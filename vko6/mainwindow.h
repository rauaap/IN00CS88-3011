#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct QStringLineEditPair {
    QString* operand;
    QLineEdit* lineEdit;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void setWidgetColors();
    QString operand1, operand2;
    QStringLineEditPair qStringLineEditPairs[2];
    int state;
    short op;
    float result;

private slots:
    void numberClickedHandler();
    void operatorClickedHandler();
    void enterClickedHandler();
    void clearClickedHandler();
};

#endif // MAINWINDOW_H
