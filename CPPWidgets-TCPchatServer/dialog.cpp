#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnStart_clicked()
{
    quint32 port = static_cast<quint16>(ui->sbPort->value());
    server.setMessage(ui->txtMessage->text() + "\r\n");
    if (!server.listen(QHostAddress::Any, port)) {
        QMessageBox::critical(this, "Error", server.errorString());
        return;
    }

    ui->lblStatus->setText("Listening...");
    enableButtons();
}

void Dialog::on_btnStop_clicked()
{
    server.close();
    ui->lblStatus->setText("Closed");
    enableButtons();
}

void Dialog::next()
{
    int i = ui->stackedWidget->currentIndex();
    i++;
    if (i >= ui->stackedWidget->count()) {
        i = ui->stackedWidget->count() - 1;
    }

    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();
}

void Dialog::back()
{
    int i = ui->stackedWidget->currentIndex();
    i--;
    if (i < 0) {
        i = ui->stackedWidget->currentIndex();
    }

    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();
}

void Dialog::changed()
{
    ui->lblStatus->setText(QString("There are %0 clients connected").arg(server.count()));
}

void Dialog::init()
{
    btnNext = new QPushButton("Next", this);
    btnBack = new QPushButton("Back", this);

    ui->buttonBox->addButton(btnBack, QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnNext, QDialogButtonBox::ButtonRole::ActionRole);

    connect(btnBack, &QPushButton::clicked, this, &Dialog::back);
    connect(btnNext, &QPushButton::clicked, this, &Dialog::next);
    connect(&server, &Server::changed, this, &Dialog::changed);

    enableButtons();
}

void Dialog::enableButtons()
{
    ui->btnStart->setEnabled(!server.isListening());
    ui->btnStop->setEnabled(server.isListening());

    if (ui->stackedWidget->count() <= 1) {
        btnBack->setEnabled(false);
        btnNext->setEnabled(false);
        return;
    }

    if (ui->stackedWidget->currentIndex() == 0) {
        btnBack->setEnabled(false);
        btnNext->setEnabled(true);
        return;
    }

    if (ui->stackedWidget->count() >= ui->stackedWidget->count() - 1) {
        btnBack->setEnabled(true);
        btnNext->setEnabled(false);
        return;
    }
}
