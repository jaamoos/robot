#ifndef _MAIN_WINDOW_H_ 
#define _MAIN_WINDOW_H_

#include <QtWidgets>
// #include <QPushButton>

class MainWindow : public QWidget {
	Q_OBJECT

private:
	QPushButton *btnForward;
	QPushButton *btnBackward;
	QPushButton *btnLeft;
	QPushButton *btnRight;

	QTcpSocket *socket;

	void createComponents();
	void connectSignals();

protected:
	void keyPressEvent(QKeyEvent *event);

public:
	MainWindow(QWidget *parent = 0);

public slots:
	void slotMoveForward();
	void slotMoveBackward();
	void slotTurnLeft();
	void slotTurnRight();
	void slotStopMovement();

	void slotReady
};

#endif
