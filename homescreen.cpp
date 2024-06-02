include "homescreen.h"

HomeScreen::HomeScreen(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    homeScreenButton = new QPushButton("Go to Other Screen", this);
    layout->addWidget(homeScreenButton);

    connect(homeScreenButton, &QPushButton::clicked, this, &HomeScreen::goToHomeScreen);

    setLayout(layout);
}
