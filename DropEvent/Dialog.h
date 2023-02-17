#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDragEnterEvent>
#include <QUrl>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected:
    void dragEnterEvent(QDragEnterEvent *);

    void dragLeaveEvent(QDragLeaveEvent *);

    void dropEvent(QDropEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
