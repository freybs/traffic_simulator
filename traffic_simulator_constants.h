#ifndef TRAFFIC_SIMULATOR_CONSTANTS_H
#define TRAFFIC_SIMULATOR_CONSTANTS_H

#include <QComboBox>
#include <QPainter>
#include <QApplication>
#include <iostream>
#include <string>
#include <unistd.h>

#define RATIO_ROAD_2_GRASS          0.9
#define RATIO_LINE_W_2_ROAD_W       0.05
#define RATIO_LINE_H_2_LINE_W       0.1
#define RATIO_LINE_SPACE_W_2_LINE_W 2
#define RATIO_AUTO_H_2_LANE_H       0.50
#define RATIO_AUTO_W_2_AUTO_H       2.66

#define COLOR_BLACK    Color(0,0,0)
#define COLOR_ASPHALT  Color(50,50,50)
#define COLOR_WHITE    Color(255,255,255)
#define COLOR_RED      Color(255,0,0)
#define COLOR_GREEN    Color(0,255,0)
#define COLOR_GRASS    Color(0,150,0)
#define COLOR_BLUE     Color(0,0,255)

typedef QColor Color;

#endif // TRAFFIC_SIMULATOR_CONSTANTS_H
