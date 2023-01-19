#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "edges.h"

#ifndef NODESH_
#define NODESH_

extern int graphLen;

pnode newNode(int, pnode);
pnode findNode(pnode, int);
void delete_node(pnode*, int);
void insert_node(pnode*, int);
void insert_node_n_cmd(pnode *head);
int get_graph_len();

#endif