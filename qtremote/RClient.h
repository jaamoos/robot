#ifndef
#define _R_CLIENT_H_

#include <QTcpSocket>

class RClient {
	Q_OBJECT

private:
	QTcpSocket *socket;

public:
	RClient();

private:
	void slotReadyRead();
	void slotError(QAbstractSocket::SocketError);
	void slotSendRequest();
	void slotConnected();

}

#endif