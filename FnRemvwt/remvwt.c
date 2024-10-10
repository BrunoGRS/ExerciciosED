#include <stdio.h>
#include <stdbool.h>

#define MAXNODES 50

struct node
{
};

struct arc
{
  bool adj;
  int weight;
};

struct graph
{
  struct node nodes[MAXNODES];
  struct arc arcs[MAXNODES][MAXNODES];
};

struct graph g;

void join(struct graph *g, int node1, int node2)
{
  g->arcs[node1][node2].adj = true;
}

void joinwt(struct graph *g, int node1, int node2, int wt)
{
  g->arcs[node1][node2].adj = true;
  g->arcs[node1][node2].weight = wt;
}

void remv(struct graph *g, int node1, int node2)
{
  g->arcs[node1][node2].adj = false;
}

void remvwt(struct graph *g, int node1, int node2, int wt)
{
  if (g->arcs[node1][node2].weight == wt)
  {
    g->arcs[node1][node2].adj = false;
    g->arcs[node1][node2].weight = 0;
    printf("Peso %d válido, tudo de acordo! \n", wt);
  }
  else
  {
    printf("Peso %d informado está inválido! \n", wt);
  }
}

bool adjacent(struct graph *g, int node1, int node2)
{
  return g->arcs[node1][node2].adj;
}

void showWt(struct graph *g, int node1, int node2)
{
  printf("o no %d é adjacente ao no %d com o peso %d \n", node1, node2, g->arcs[node1][node2].weight);
}

int main()
{
  // join(&g, 0, 1);
  // join(&g, 1, 2);
  // join(&g, 2, 3);
  // printf("O no 0 é adjacente ao no 1? %s\n", adjacent(&g, 0, 1) ? "Sim" : "Não");

  joinwt(&g, 0, 1, 20);

  remvwt(&g, 0, 1, 30);
  remvwt(&g, 0, 1, 20);

  // if (adjacent(&g, 0, 1))
  // {
  //   showWt(&g, 0, 1);
  // }
  // else
  // {
  //   printf("O no 0 não é adjacente ao no 1 com peso \n");
  // }

  return 0;
}