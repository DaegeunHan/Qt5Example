#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "TestThread.h"
#include <QDebug>


int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);
	TestThread *pThread = NULL;

	QQmlApplicationEngine engine;
	const QUrl url(QStringLiteral("qrc:/main.qml"));
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
					 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);
	engine.load(url);

	QObject* progressBar = engine.rootObjects().first()->findChild<QObject*>("progressBarObj");
	// qml update way1 : set property method
	progressBar->setProperty("value", 100);
	pThread = new TestThread();
	// qml update way2 : signal/slot method
	QObject::connect(pThread, SIGNAL(update(int)), progressBar, SIGNAL(update(int)));
	pThread->start();

	return app.exec();
}
