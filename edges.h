#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#ifndef EDGESH_
#define EDGESH_ 

pedge newEdge(int weight, pnode endPoint, pedge firstEdge);
void insertLastEdge(int weight, pnode endPoint, pedge *firstEdge);

#endif
