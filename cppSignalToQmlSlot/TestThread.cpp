#include "TestThread.h"

TestThread::TestThread()
{

}

void TestThread::run()
{
	QThread::msleep(2000);

	for (int i = 0; i <= 100; ++i)
	{
		QThread::msleep(100);
		emit update(i);
	}
}
