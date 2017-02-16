#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "traffic_simulator.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
        void connect_traffic_simulator (traffic_simulator *ts);
        void paint_rect(int x, int y, int w, int h, QColor color);

    protected:
        void paintEvent(QPaintEvent *);

    private:
        Ui::MainWindow *ui;
        traffic_simulator *m_ts;
        QPainter *m_painter;
};

#endif // MAINWINDOW_H
