#include "Dialog.h"
#include "ui_Dialog.h"
#include <QDragEnterEvent>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // to enable drag & drop event
    setAcceptDrops(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::dragEnterEvent(QDragEnterEvent *e)
{
    ui->label_state->setText("drag enter...");
    e->accept();
}

void Dialog::dragLeaveEvent(QDragLeaveEvent *)
{
    ui->label_state->setText("drag leave...");
}

void Dialog::dropEvent(QDropEvent *e)
{
    ui->label_state->setText("dropped..!");

    if (!e->mimeData()->hasUrls())
        return;

    QList<QUrl> urls = e->mimeData()->urls();
    foreach (QUrl url, urls)
    {
        ui->plainTextEdit->appendPlainText(url.toLocalFile());
    }
}

void Dialog::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
}
