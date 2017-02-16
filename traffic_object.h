#ifndef TRAFFIC_OBJECT_H
#define TRAFFIC_OBJECT_H

#include <QColor>

class traffic_object
{
    public:
        traffic_object(int x, int y, int w, int h, QColor color, bool redraw, int speed);
        ~traffic_object();
        int get_x();
        int get_y();
        int get_w();
        int get_h();
        QColor get_color();
        bool redraw();
        int get_speed();
        void drive();

    protected:

    private:
        int m_x;
        int m_y;
        int m_w;
        int m_h;
        QColor m_color;
        bool m_redraw;
        int m_speed;
};

#endif // TRAFFIC_OBJECT_H
