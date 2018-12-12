#ifndef changeTree_h
#define changeTree_h
extern int count;
extern int removes;
void breaktree(Node *parent);
void growtree(Node *parent);
void freetree(Node *head);
double nodeValue( Node *node, double time );
double value( double x, double y, double time );
void interesttree(Node *node, double time, int level );
#endif
