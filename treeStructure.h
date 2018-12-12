#ifndef treeStructure_h
#define treeStructure_h
typedef struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
  int flag;
}Node;
#endif
