#ifndef EDGESH_
#define EDGESH_ 

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

pedge newEdge(int weight, pnode endPoint, pedge firstEdge);
void insertLastEdge(int weight, pnode endPoint, pedge *firstEdge);

#endif
