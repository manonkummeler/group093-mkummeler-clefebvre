/* définir les structures */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure de noeud
typedef struct {
    int nodeName;
    double *X;
    double *Y;
} Node;

//structure d'élément
typedef struct {
    int elementName;
    int *nodes;
} Element;

//structure de condition aux limites
typedef struct {
    int boundaryName;
    int *nodes;
} Boundary; 


//structure de maillage
typedef struct {
    int nNodes;
    int nElements;
    int nBoundaries;
    Node *nodes;
    Element *elements;
    Boundary *boundaries;
} Mesh;
