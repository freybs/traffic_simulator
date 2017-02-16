#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QPainter>

#include "traffic_simulator.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::connect_traffic_simulator (traffic_simulator *ts) {
    m_ts = ts;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    m_ts->set_painter(&p);
    m_ts->paint_traffic_objects();
}
