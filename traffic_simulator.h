#ifndef TRAFFIC_SIMULATOR_H
#define TRAFFIC_SIMULATOR_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <queue>
#include <stdbool.h>

#include "traffic_object.h"

typedef struct traffic_simulator_environment {
    int width;
    int height;
    int num_roads;
    int num_lanes;
} traffic_simulator_environment;

class traffic_simulator {
    public:
        traffic_simulator(traffic_simulator_environment *init);
        ~traffic_simulator();
        void increment_traffic_simulator();
        void test_movement();
        void paint_traffic_objects();
        void set_painter(QPainter *p);

    protected:

    private:
        void init_environment();
        void add_traffic_object(traffic_object *object);
        void paint_traffic_object(traffic_object *object);

        std::queue<traffic_object*> traffic_objects_to_paint;
        traffic_simulator_environment *m_environment;
        QPainter *m_painter;
        bool m_redraw_environment;
        // Environment Dimensions
        int m_ul_x, m_ul_y, m_w, m_h;
        // Road Dimensions
        int m_num_lengths, m_num_lanes, m_lane_origin_x, *m_lane_origin_y;
        // Automobile Dimensions
        int m_auto_w, m_auto_h;
};

#endif // TRAFFIC_SIMULATOR_H
