
#include <QApplication>
#include <iostream>
#include <string>
#include <unistd.h>

#include "mainwindow.h"
#include "traffic_simulator.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "Starting Traffic Simulator..." << endl;
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    traffic_simulator_environment ts_env{w.geometry().width(),w.geometry().height(),1,2};
    traffic_simulator ts(&ts_env);
    w.connect_traffic_simulator(&ts);
//    ts.increment_traffic_simulator();
    while(true) {
        w.update();
        app.processEvents();
        usleep(500000);
    }
}


