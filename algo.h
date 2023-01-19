#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include "nodes.h"
#include "queue.h"

#ifndef ALGOH_
#define ALGOH_

void dijkstra(pnode head, pnode start) ;
void relax(pnode u, pedge e);

#endif