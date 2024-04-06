/* définit toutes les fonctions */

#include "struct.h"

Point* calculate_arc(double radius, double start_angle, double end_angle, int n_points);

void addPoint (Point *points, int *nPoints, double x, double y)
void addLine (Line *lines, int *nLines, Point *points, int point1, int point2) 

Mesh* createMesh(const char *filename);
void printMesh(Mesh *mesh);
void freeMesh(Mesh *mesh);
