/* écrire les fonctions */ 

#include "struct.h"

//calcule les points d'un arc de cercle
void calculate_arc(double radius, double start_angle, double end_angle, int n_points) {
    printf("Points de l'arc de cercle:\n");
    double angle_increment = (end_angle - start_angle) / (double)(n_points - 1);
    
    for (int i = 0; i < n_points; ++i) {
        double current_angle = start_angle + i * angle_increment;
        double x = radius * cos(current_angle);
        double y = radius * sin(current_angle);
        printf("Point %d: x = %f, y = %f\n", i+1, x, y);

    }
    printf("\n\n");
}


//calculer les noeuds de notre arc avec la fonction calculate_arc 
//et ensuite les utilsier pour notre géométrie et créer un maillage


//initialisation d'un vecteur
void vector_init(Vector* vec) {
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

//libérer la mémoire allouée pour un vecteur
void vector_free(Vector* vec) {
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}



//crée un maillage
Mesh* createMesh() {
    //allouer de la mémoire pour le maillage
    Mesh *mesh = (Mesh*)malloc(sizeof(Mesh));
    if (mesh == NULL) {
        fprintf(stderr, "Erreur: Impossible d'allouer de la mémoire pour le maillage\n");
        exit(EXIT_FAILURE);
    }

    //définir le nombre de noeuds, d'éléments et de CL
    mesh->nNodes = 3;
    mesh->nElements = 1;
    mesh->nBoundaries = 3;

    //allouer de la mémoire pour les tableaux de noeuds, d'éléments et de CL
    mesh->nodes = (Node*)malloc(mesh->nNodes * sizeof(Node));
    mesh->elements = (Element*)malloc(mesh->nElements * sizeof(Element));
    mesh->boundaries = (Boundary*)malloc(mesh->nBoundaries * sizeof(Boundary));

    if (mesh->nodes == NULL || mesh->elements == NULL || mesh->boundaries == NULL) {
        fprintf(stderr, "Erreur: Impossible d'allouer de la mémoire pour les données du maillage\n");
        exit(EXIT_FAILURE);
    }

    //définit les noeuds/coordonnées
    mesh->nodes[0].nodeName = 0; mesh->nodes[0].X = 0.0; mesh->nodes[0].Y = 0.0;
    mesh->nodes[1].nodeName = 1; mesh->nodes[1].X = 1.0; mesh->nodes[1].Y = 0.0;
    mesh->nodes[2].nodeName = 2; mesh->nodes[2].X = 0.5; mesh->nodes[2].Y = 1.0;

    //définit l'élément (indices/noms des noeuds)
    mesh->elements[0].elementName = 0;
    mesh->elements[0].nodes[0] = 0; mesh->elements[0].nodes[1] = 1; mesh->elements[0].nodes[2] = 2;

    //définit les CL (indices des noeuds)
    mesh->boundaries[0].boundaryName = 0;
    mesh->boundaries[0].nodes[0] = 0; mesh->boundaries[0].nodes[1] = 1;

    mesh->boundaries[1].boundaryName = 1;
    mesh->boundaries[1].nodes[0] = 1; mesh->boundaries[1].nodes[1] = 2;

    mesh->boundaries[2].boundaryName = 2;
    mesh->boundaries[2].nodes[0] = 2; mesh->boundaries[2].nodes[1] = 0;

    return mesh;
}


//libère la mémoire allouée pour le maillage
void freeMesh(Mesh *mesh) {
    free(mesh->nodes);
    free(mesh->elements);
    free(mesh->boundaries);
    free(mesh);
}


//fonction pour afficher les informations du maillage
void printMesh(Mesh *mesh) {
    printf("Noeuds:\n");
    for (int i = 0; i < mesh->nNodes; ++i) printf("Node %d: X = %.2f, Y = %.2f\n", mesh->nodes[i].nodeName, mesh->nodes[i].X, mesh->nodes[i].Y);

    printf("\nElements:\n");
    for (int i = 0; i < mesh->nElements; ++i) printf("Element %d: Nodes = %d, %d, %d\n", mesh->elements[i].elementName, mesh->elements[i].nodes[0], mesh->elements[i].nodes[1], mesh->elements[i].nodes[2]);

    printf("\nConditions aux limites:\n");
    for (int i = 0; i < mesh->nBoundaries; ++i) printf("Boundary %d: Nodes = %d, %d\n", mesh->boundaries[i].boundaryName, mesh->boundaries[i].nodes[0], mesh->boundaries[i].nodes[1]);
}