/* écrire le code du programme */

#include "code.c"


int main() {


    double radius = 10.0;
    double start_angle = - PI / 4;
    double end_angle = PI / 4;
    int n_points = 10; //nombre de points le long de l'arc

    calculate_arc(radius, start_angle, end_angle, n_points);


    Mesh *mesh = createMesh();
    printMesh(mesh);
    freeMesh(mesh);
    
    return 0;
}