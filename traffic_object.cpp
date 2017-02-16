#include "traffic_object.h"

traffic_object::traffic_object(int x, int y, int w, int h, QColor color, bool redraw, int speed) {
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
    m_speed = speed;
    m_color = color;
    m_redraw = redraw;
}

traffic_object::~traffic_object() {

}

int traffic_object::get_x() {
    return m_x;
}

int traffic_object::get_y() {
    return m_y;
}

int traffic_object::get_w() {
    return m_w;
}

int traffic_object::get_h() {
    return m_h;
}

QColor traffic_object::get_color() {
    return m_color;
}

bool traffic_object::redraw() {
    return m_redraw;
}

int traffic_object::get_speed() {
    return m_speed;
}

void traffic_object::drive() {
    m_x += m_speed;
}
