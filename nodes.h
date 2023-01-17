#ifndef NODESH_
#define NODESH_

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "edges.h"

pnode newNode(int, pnode);
pnode findNode(pnode, int);
void delete_node(pnode*, int);

#endif