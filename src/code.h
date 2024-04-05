/* définit toutes les fonctions */

#include "struct.h"

Point* calculate_arc(double radius, double start_angle, double end_angle, int n_points);
Mesh* createMesh();
void printMesh(Mesh *mesh);
void freeMesh(Mesh *mesh);
