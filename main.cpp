#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include"treeStructure.h"
#include"buildTree.h"
#include"writeTree.h"
#include"changetree.h"

int main( int argc, char **argv ) {

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
  //breaktree(head);
  removes=1;
  
  for (;removes!=0;)
  {
  removes=0;
  count=0;
  interesttree(head,0.0,6);
  printf("%i\n",removes);
  printf("%i\n",count);
  }
  
  writeTree( head );

  return 0;
}

