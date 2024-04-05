/* définir les structures */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define PI 3.14159265358979323846
#ifndef NULL
#define NULL ((void *)0)
#endif



//structure de noeud
typedef struct {
    int nodeName;
    double X;
    double Y;
} Node;


//structure d'élément
typedef struct {
    int elementName;
    int nodes[3]; //indices des noeuds
} Element;


//structure de condition aux limites
typedef struct {
    int boundaryName;
    int nodes[2];
} Boundary; 


//structure de maillage (ensemble de noeuds, éléments et CL/boundaries)
typedef struct {
    int nNodes;
    int nElements;
    int nBoundaries;
    Node *nodes;
    Element *elements;
    Boundary *boundaries;
} Mesh;



//structure d'un vecteur de pointeurs
typedef struct {
    void** data; //tableau de pointeurs
    size_t size; //taille du vecteur
    size_t capacity; //capacité/taille max
} Vector;

