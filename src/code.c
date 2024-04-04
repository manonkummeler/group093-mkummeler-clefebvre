/* écrire les fonctions */ 

#include "struct.h"

void calculate_arc(double radius, double start_angle, double end_angle, int n_points) {
    double angle_increment = (end_angle - start_angle) / (double)(n_points - 1);
    
    for (int i = 0; i < n_points; ++i) {
        double current_angle = start_angle + i * angle_increment;
        double x = radius * cos(current_angle);
        double y = radius * sin(current_angle);
        printf("Point %d: x = %f, y = %f\n", i+1, x, y);

    }
}