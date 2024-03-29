#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QClipboard>
#include <QCloseEvent>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QList>
#include <QMainWindow>
#include <QMessageBox>
#include <QStringListModel>
#include <QTextStream>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionStart_triggered();
    void on_actionStop_triggered();
    void on_actionCopy_triggered();
    void on_actionCut_triggered();
    void on_actionPaste_triggered();
    void on_actionDelete_triggered();
    void timeout();

    void on_actionNew_triggered();

private:
    Ui::MainWindow *ui;

    QTimer m_timer;
    QString m_last;
    QStringListModel m_model;
    QStringList m_list;
    QString m_path;
    bool m_changed;

    void init();
    void checkSaved();

protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
