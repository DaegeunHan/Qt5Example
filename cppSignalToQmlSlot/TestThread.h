#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QThread>

class TestThread : public QThread
{
	Q_OBJECT

signals:
	void update(int);

public:
	TestThread();

protected:
	virtual void run();
};

#endif // TESTTHREAD_H
