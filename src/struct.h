/* définit toutes les structures */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

#define PI 3.14159265358979323846
#ifndef NULL
#define NULL ((void *)0)
#endif


/*
Structure représenant un noeud. 
    nodeName : nom du noeud
    X : coordonnée x du noeud
    Y : coordonnée y du noeud
*/
typedef struct {
    int nodeName;
    double X;
    double Y;
} Node;


/*
Structure représentant un élément. 
    elementName : nom de l'élément
    nodes : tableau contenant les indices des noeuds de l'élément
*/
typedef struct {
    int elementName;
    int nodes[3]; //indices des noeuds
} Element;


/*
Structure représentant une condition aux limites. 
    boundaryName : nom de la CL
    nodes : tableau contenant les indices des noeuds de la CL
*/
typedef struct {
    int boundaryName;
    int nodes[2];
} Boundary; 


/*
Structure représentant un maillage contenant un ensemble de noeuds, d'éléments et de conditions aux limites. 
    nNodes : nombre de noeuds du maillage
    nElements : nombre d'éléments du maillage
    nBoundaries : nombre de CL sur le maillage
    nodes : tableau des noeuds du maillage
    elements : tableau des éléments du maillage
    boundaries : tableau des CL sur le maillage
*/
typedef struct {
    int nNodes;
    int nElements;
    int nBoundaries;
    Node *nodes;
    Element *elements;
    Boundary *boundaries;
} Mesh;

