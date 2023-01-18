#include <stdio.h>
#include <stdlib.h>
#include "edges.h"

#ifndef NODESH_
#define NODESH_

pnode newNode(int, pnode);
pnode findNode(pnode, int);
void delete_node(pnode*, int);
void insert_node(pnode*, int);
void insert_node_n_cmd(pnode *head);

#endif