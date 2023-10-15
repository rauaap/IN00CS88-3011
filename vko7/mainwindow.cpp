#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPushButton>
#include <array>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pQTimer(new QTimer)
    , gameStarted(false)
    , currentPlayer(0)
    , selectedGameTime(0)
{
    ui->setupUi(this);

    QObject::connect(
        pQTimer,
        &QTimer::timeout,
        this,
        [this]() {
            static const std::array<QProgressBar*, 2> progressBars = {
                ui->progressBarPlayerA, ui->progressBarPlayerB
            };

            short timeToSet = --(playerTimes[currentPlayer]);
            progressBars[currentPlayer]->setValue(timeToSet);

            if (!timeToSet) {
               setGameInfoText(
                    QString("Player ")
                        .append(QString::number((currentPlayer ^ 1) + 1))
                        .append(" won")
                    , 20
                );

                gameStarted = false;
                //selectedGameTime = 0;
                currentPlayer = 0;
                pQTimer->stop();
            }
        }
    );

    for (auto &playTimeButton: {
        ui->pushButtonPlaytime120,
        ui->pushButtonPlaytime300
    }) {
        QObject::connect(
            playTimeButton,
            &QPushButton::clicked,
            this,
            [this]() {
                if (gameStarted) return;
                ui->pushButtonPlaytime120->setStyleSheet("");
                ui->pushButtonPlaytime300->setStyleSheet("");
                QPushButton* pushedButton = qobject_cast<QPushButton*>(sender());
                pushedButton->setStyleSheet("background-color: Coral");
                selectedGameTime = pushedButton->property("gameTime").toInt();
                setGameInfoText("Ready to play", 20);
            }
        );
    }

    QObject::connect(
        ui->pushButtonStart,
        &QPushButton::clicked,
        this,
        [this]() {
            if (gameStarted || !selectedGameTime) return;
            gameStarted = true;

            playerTimes[0] = selectedGameTime;
            playerTimes[1] = selectedGameTime;
            ui->progressBarPlayerA->setMaximum(selectedGameTime);
            ui->progressBarPlayerB->setMaximum(selectedGameTime);
            ui->progressBarPlayerA->setValue(selectedGameTime);
            ui->progressBarPlayerB->setValue(selectedGameTime);

            pQTimer->start(1000);
            setGameInfoText("Game ongoing", 20);
        }
    );

    QObject::connect(
        ui->pushButtonStop,
        &QPushButton::clicked,
        this,
        [this]() {
            if (!gameStarted) return;
            gameStarted = false;
            pQTimer->stop();
            currentPlayer = 0;
            //selectedGameTime = 0;
            ui->progressBarPlayerA->reset();
            ui->progressBarPlayerB->reset();
            setGameInfoText("New game via start button", 20);
        }
    );

    for (auto &switchPlayerButton: {ui->pushButtonPlayerA, ui->pushButtonPlayerB}) {
        QObject::connect(
            switchPlayerButton,
            &QPushButton::clicked,
            this,
            [this]() {
                short sendingPlayer = qobject_cast<QPushButton*>(sender())->property("player").toInt();
                if ((currentPlayer != sendingPlayer) || !gameStarted) return;
                pQTimer->start(1000);
                currentPlayer ^= 1;
            }
        );
    }

    setGameInfoText("Set paytime and start game!", 20);
    ui->progressBarPlayerA->reset();
    ui->progressBarPlayerB->reset();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setGameInfoText(QString text, int size) {
    ui->labelGameInfo->setText(text);
    ui->labelGameInfo->setFont(QFont("Consolas", size));
}
