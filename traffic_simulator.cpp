#include "traffic_simulator.h"

#define RATIO_ROAD_2_GRASS          0.9
#define RATIO_LINE_W_2_ROAD_W       0.05
#define RATIO_LINE_H_2_LINE_W       0.1
#define RATIO_LINE_SPACE_W_2_LINE_W 2
#define RATIO_AUTO_H_2_LANE_H       0.50
#define RATIO_AUTO_W_2_AUTO_H       2.66

traffic_simulator::traffic_simulator(traffic_simulator_environment *init) {
    m_w = init->width;
    m_h = init->height;
    m_ul_x = 0;
    m_ul_y = 0;
    m_num_lengths = init->num_roads;
    m_num_lanes = init->num_lanes;
    m_environment = init;
    init_environment();
}

traffic_simulator::~traffic_simulator() {

}

void traffic_simulator::test_movement() {
    int num_objects_to_paint = traffic_objects_to_paint.size();
    traffic_object *object;
    for(int i = 0; i < num_objects_to_paint; ++i) {
        object = traffic_objects_to_paint.front();
        traffic_objects_to_paint.pop();
        traffic_objects_to_paint.push(object);
        if(object->get_speed() > 0) {
            object->drive();
        }
    }
}

void traffic_simulator::increment_traffic_simulator() {
    int num_objects_to_paint = traffic_objects_to_paint.size();
    traffic_object *object;
    for(int i = 0; i < num_objects_to_paint; ++i) {
        object = traffic_objects_to_paint.front();
        traffic_objects_to_paint.pop();
        traffic_objects_to_paint.push(object);
        if(object->get_speed() > 0) {
            object->drive();
        }
    }
}

void traffic_simulator::init_environment() {
    traffic_object *grass = new traffic_object(
        0,
        0,
        m_w,
        m_h,
        QColor(0,150,0),
        true,
        0
    );
    add_traffic_object(grass);

    int road_width = m_w;
    int road_height = m_h * RATIO_ROAD_2_GRASS / m_num_lengths;
    int road_paint_x = m_ul_x;
    int road_paint_y = m_ul_y + (m_h/m_num_lengths) * ((1-RATIO_ROAD_2_GRASS)/2);

    int lane_height = road_height / m_num_lanes;
    m_lane_origin_x = road_paint_x;
    m_lane_origin_y = new int[m_num_lanes];
    for(int i = 0; i < m_num_lanes; ++i)
        m_lane_origin_y[i] = road_paint_y + (i+((1-RATIO_AUTO_H_2_LANE_H)/2)) * lane_height;
    m_auto_h = lane_height * RATIO_AUTO_H_2_LANE_H;
    m_auto_w = m_auto_h * RATIO_AUTO_W_2_AUTO_H;

    int line_width = road_width * RATIO_LINE_W_2_ROAD_W;
    int line_height =  line_width * RATIO_LINE_H_2_LINE_W;
    int line_space_width = line_width * RATIO_LINE_SPACE_W_2_LINE_W;
    int num_lines = m_w/(line_width+line_space_width) + 1;

    for(int i = 0; i < m_num_lengths; ++i){
        traffic_object *road = new traffic_object(
            road_paint_x,
            road_paint_y,
            road_width,
            road_height,
            QColor(50,50,50),
            true,
            0
        );
        add_traffic_object(road);

        int line_x_begin = road_paint_x + line_space_width/2;
        for(int j = 0; j < num_lines; ++j) {
            int line_x = line_x_begin + ((line_space_width+line_width)*j);
            for(int k = 1; k < m_num_lanes; ++k) {
                int line_y = road_paint_y + (lane_height*k) - (line_height/2);
                traffic_object *line = new traffic_object(
                    line_x,
                    line_y,
                    line_width,
                    line_height,
                    QColor(255,255,255),
                    true,
                    0
                );
                add_traffic_object(line);
            }
        }
        road_paint_y += m_h/m_num_lengths;
    }
}

void traffic_simulator::add_new_auto() {
    traffic_object *new_auto = new traffic_object(
        m_lane_origin_x,
        m_lane_origin_y[0],
        m_auto_w,
        m_auto_h,
        QColor(255,0,0),
        true,
        10
    );
    add_traffic_object(new_auto);
}

void traffic_simulator::add_traffic_object(traffic_object *object) {
    traffic_objects_to_paint.push(object);
}

void traffic_simulator::set_painter(QPainter *p) {
    m_painter = p;
}

void traffic_simulator::paint_traffic_objects() {
    int num_objects_to_paint = traffic_objects_to_paint.size();
    traffic_object *object;
    for(int i = 0; i < num_objects_to_paint; ++i){
        object = traffic_objects_to_paint.front();
        paint_traffic_object(object);
        traffic_objects_to_paint.pop();
        if(object->redraw()) {
            traffic_objects_to_paint.push(object);
        } else {
            free(object);
        }
    }
}

void traffic_simulator::paint_traffic_object(traffic_object *obj) {
    QBrush brush(obj->get_color());
    m_painter->setBrush(brush);
    m_painter->drawRect(obj->get_x(),obj->get_y(),obj->get_w(),obj->get_h());
}
