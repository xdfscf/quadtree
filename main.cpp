#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include"treeStructure.h"
#include"buildTree.h"
#include"writeTree.h"
#include"changetree.h"

int main( int argc, char **argv ) {
totalRemove=0;
totalAdd=0;
max=0;
removes=0;
count=0;
  Node *head;
  int i; 

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  makeChildren( head );
  //makeChildren( head->child[1] );
  /*makeChildren( head->child[2] );
  makeChildren( head->child[0] );
  makeChildren( head->child[3] );
  Node *current=head->child[0];
  makeChildren(current->child[0]);*/
  growtree(head);
  growtree(head);
  /*growtree(head);*/ 
  // print the tree for Gnuplot
  adapt(head);
  printf("totalremove %i \n",totalRemove);
  printf("totaladd %i\n",totalAdd);
  writeTree( head );
  breaktree(head);
  //freetree(head);
  return 0;
}

