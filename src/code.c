/* toutes les fonctions */   

#include "code.h"

//calcule les points d'un arc de cercle et les mets dans un tableau de points
Point* calculate_arc(double radius, double start_angle, double end_angle, int n_points) {
    //printf("Points de l'arc de cercle:\n");
    double angle_increment = (end_angle - start_angle) / (double)(n_points - 1);
    
    //alloue de la mémoire pour le tableau de points
    Point *points = (Point*)malloc(n_points * sizeof(Point));
    if (points == NULL) {
        fprintf(stderr, "Erreur: Impossible d'allouer de la mémoire pour les points\n");
        exit(EXIT_FAILURE);
    }
    //calcule les coordonnées des points et les ajoute au tableau
    for (int i = 0; i < n_points; ++i) {
        double current_angle = start_angle + i * angle_increment;
        points[i].x = radius * cos(current_angle);
        points[i].y = radius * sin(current_angle);
        //printf("Point %d: x = %f, y = %f\n", i+1, points[i].x, points[i].y);

    }
    return points;
}
//calcule les noeuds de notre arc qu'on pourra ensuite utiliser pour notre géométrie et pour créer le maillage


//ajoute un point à un tableau de points
void addPoint (Point *points, int *nPoints, double x, double y) {
    points[*nPoints].x = x;
    points[*nPoints].y = y;
    (*nPoints)++;
}

//ajoute une ligne à un tableau de lignes
void addLine (Line *lines, int *nLines, Point *points, int point1, int point2) {
    lines[*nLines].start = points[point1];
    lines[*nLines].end = points[point2];
    (*nLines)++;
}



//crée un maillage
Mesh* createMesh(const char *filename) {

    //ouvre le fichier contant le maillage
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier %s\n", filename);
        exit(EXIT_FAILURE);
    }

    //alloue de la mémoire pour le maillage
    Mesh *mesh = (Mesh*)malloc(sizeof(Mesh));
    if (mesh == NULL) {
        fprintf(stderr, "Erreur: Impossible d'allouer de la mémoire pour le maillage\n");
        exit(EXIT_FAILURE);
    }

    //lit le fichier, alloue la mémoire nécéssaire et stocke les informations dans les structures
    fscanf(file, "Number of nodes %d \n", &mesh->nNodes);
    mesh->nodes = (Node*)malloc(mesh->nNodes * sizeof(Node));
    if (mesh->nodes == NULL) {
        fprintf(stderr, "Erreur: Impossible d'allouer de la mémoire pour les noeuds\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mesh->nNodes; ++i) {
        fscanf(file, "%d :  %le  %le \n", &mesh->nodes[i].nodeName, &mesh->nodes[i].X, &mesh->nodes[i].Y);
    }
    fscanf(file, "Number of boundaries %d \n", &mesh->nBoundaries);
    mesh->boundaries = (Boundary*)malloc(mesh->nBoundaries * sizeof(Boundary));
    if (mesh->boundaries == NULL) {
        fprintf(stderr, "Erreur: Impossible d'allouer de la mémoire pour les CL\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mesh->nBoundaries; ++i) {
        fscanf(file, "%d :  %d  %d \n", &mesh->boundaries[i].boundaryName, &mesh->boundaries[i].nodes[0], &mesh->boundaries[i].nodes[1]);
    }
    fscanf(file, "Number of elements %d \n", &mesh->nElements);
    mesh->elements = (Element*)malloc(mesh->nElements * sizeof(Element));
    if (mesh->elements == NULL) {
        fprintf(stderr, "Erreur: Impossible d'allouer de la mémoire pour les éléments\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < mesh->nElements; ++i) {
        fscanf(file, "%d :  %d  %d  %d \n", &mesh->elements[i].elementName, &mesh->elements[i].nodes[0], &mesh->elements[i].nodes[1], &mesh->elements[i].nodes[2]);
    }
    

    fclose(file);
    return mesh;
}


//libère la mémoire allouée pour le maillage
void freeMesh(Mesh *mesh) {
    free(mesh->nodes);
    free(mesh->boundaries);
    free(mesh->elements);
    free(mesh);
}


//fonction pour afficher les informations du maillage
void printMesh(Mesh *mesh) {
    printf("Nombre de noeuds: %d \n", mesh->nNodes);
    for (int i = 0; i < mesh->nNodes; ++i) {
        printf("Noeud %d: x = %f, y = %f\n", mesh->nodes[i].nodeName, mesh->nodes[i].X, mesh->nodes[i].Y);
    }
    printf("\n");

    printf("Nombre de CL: %d \n", mesh->nBoundaries);
    for (int i = 0; i < mesh->nBoundaries; ++i) {
        printf("CL %d: noeuds %d, %d\n", mesh->boundaries[i].boundaryName, mesh->boundaries[i].nodes[0], mesh->boundaries[i].nodes[1]);
    }
    printf("\n");

    printf("Nombre d'éléments: %d \n", mesh->nElements);
    for (int i = 0; i < mesh->nElements; ++i) {
        printf("Element %d: noeuds %d, %d, %d\n", mesh->elements[i].elementName, mesh->elements[i].nodes[0], mesh->elements[i].nodes[1], mesh->elements[i].nodes[2]);
    }
    printf("\n");
}


