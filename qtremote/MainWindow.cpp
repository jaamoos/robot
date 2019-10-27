#include "MainWindow.h"

MainWindow::MainWindow(QWidget *w) : QWidget(w) {

	createComponents();
	connectSignals();
}

void MainWindow::createComponents() {
	
	btnForward = new QPushButton("^");
	btnBackward = new QPushButton("V");
	btnLeft = new QPushButton("<");
	btnRight = new QPushButton(">");

	QHBoxLayout *mainPanel = new QHBoxLayout;
	QGridLayout *rightPanel = new QGridLayout;

	rightPanel->addWidget(btnForward, 0, 1);
	rightPanel->addWidget(btnLeft, 1, 0);
	rightPanel->addWidget(btnBackward, 1, 1);
	rightPanel->addWidget(btnRight, 1, 2);

	mainPanel->addLayout(rightPanel);

	setLayout(mainPanel);
}

void MainWindow::connectSignals() {
	
	connect(btnForward, SIGNAL(pressed()), this, SLOT(slotMoveForward()));
	connect(btnBackward, SIGNAL(pressed()), this, SLOT(slotMoveBackward()));
	connect(btnLeft, SIGNAL(pressed()), this, SLOT(slotTurnLeft()));
	connect(btnRight, SIGNAL(pressed()), this, SLOT(slotTurnRight()));
	
	connect(btnForward, SIGNAL(released()), this, SLOT(slotStopMovement()));
	connect(btnBackward, SIGNAL(released()), this, SLOT(slotStopMovement()));
	connect(btnLeft, SIGNAL(released()), this, SLOT(slotStopMovement()));
	connect(btnRight, SIGNAL(released()), this, SLOT(slotStopMovement()));

//	connect(btnForward, SIGNAL(released()), this, SLOT(slotForwardReleased()));
}



void MainWindow::slotMoveForward() {
	qDebug("Moving forward");
}

void MainWindow::slotMoveBackward() {
	qDebug("Moving backward");
}

void MainWindow::slotTurnLeft() {
	qDebug("Turning left");
}

void MainWindow::slotTurnRight() {
	qDebug("Turning right");
}

void MainWindow::slotStopMovement() {
	qDebug("Stop movement");
}