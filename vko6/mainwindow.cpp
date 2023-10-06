#include <QPushButton>
#include <functional>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    state(0)
{
    ui->setupUi(this);

    for (const auto &button: {
        ui->pushButtonZero,
        ui->pushButtonOne,
        ui->pushButtonTwo,
        ui->pushButtonThree,
        ui->pushButtonFour,
        ui->pushButtonFive,
        ui->pushButtonSix,
        ui->pushButtonSeven,
        ui->pushButtonEight,
        ui->pushButtonNine
    }) {
        QObject::connect(
            button,
            &QPushButton::clicked,
            this,
            &MainWindow::numberClickedHandler
        );
    }

    for (const auto &button: {
        ui->pushButtonAdd,
        ui->pushButtonSub,
        ui->pushButtonMul,
        ui->pushButtonDiv
    }) {
        QObject::connect(
            button,
            &QPushButton::clicked,
            this,
            &MainWindow::operatorClickedHandler
        );
    }

    QObject::connect(
        ui->pushButtonEnter,
        &QPushButton::clicked,
        this,
        &MainWindow::enterClickedHandler
    );

    QObject::connect(
        ui->pushButtonClear,
        &QPushButton::clicked,
        this,
        &MainWindow::clearClickedHandler
    );

    qStringLineEditPairs[0] = {&operand1, ui->lineEditOperand1};
    qStringLineEditPairs[1] = {&operand2, ui->lineEditOperand2};
    setWidgetColors();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler() {
    if (state == 2) {
        clearClickedHandler();
    }

    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    QStringLineEditPair current = qStringLineEditPairs[state];
    current.operand->append(clickedButton->text());
    current.lineEdit->setText(*current.operand);
}

void MainWindow::operatorClickedHandler() {
    if (operand1.isNull() || state != 0)
        return;

    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    op = clickedButton->property("operation").toInt();
    state = 1;
    setWidgetColors();
}

void MainWindow::enterClickedHandler() {
    if (operand1.isNull() || operand2.isNull())
        return;

    static const std::function<float(float, float)> operations[] {
        [](float a, float b) {return a + b;},
        [](float a, float b) {return a - b;},
        [](float a, float b) {return a * b;},
        [](float a, float b) {return a / b;},
    };

    result = operations[op](operand1.toFloat(), operand2.toFloat());
    ui->lineEditResult->setText(QString::number(result));

    state = 2;
    setWidgetColors();
}

void MainWindow::clearClickedHandler() {
    for (QStringLineEditPair &pair: qStringLineEditPairs) {
        pair.operand->clear();
        pair.lineEdit->clear();
    }

    ui->lineEditResult->clear();
    state = 0;
    setWidgetColors();
}

void MainWindow::setWidgetColors() {
    static QPushButton* const pushButtons[] = {
        ui->pushButtonAdd,
        ui->pushButtonSub,
        ui->pushButtonMul,
        ui->pushButtonDiv
    };

    if (state == 0)
        for (auto &pb: pushButtons)
            pb->setStyleSheet("");
    else if (state == 1)
        pushButtons[op]->setStyleSheet("background-color: Coral");

    static QLineEdit* const lineEdits[] = {
        ui->lineEditOperand1,
        ui->lineEditOperand2,
        ui->lineEditResult
    };

    for (auto &le: lineEdits)
        le->setStyleSheet("");

    lineEdits[state]->setStyleSheet("background-color: Aquamarine;");
}
