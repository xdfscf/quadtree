#ifndef changeTree_h
#define changeTree_h
#define maxlevel 6
extern int count;
extern int removes;
extern int max;
extern int totalRemove;
extern int totalAdd;
void breaktree(Node *parent);
void growtree(Node *parent);
void freetree(Node *head);
double nodeValue( Node *node, double time );
double value( double x, double y, double time );
void change(Node *node, double time, int level );
void adapt(Node *head);
#endif
