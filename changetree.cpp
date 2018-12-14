#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include"treeStructure.h"
#include"buildtree.h"
#define maxlevel 6
int removes;
int count;
int max;
int totalRemove;
int totalAdd;
double value( double x, double y, double time );
void breaktree(Node *parent)
{
	int i;
	if(parent->child[0]==NULL)
	{
	free(parent);
	for(i=0;i<4;i++)
	parent->child[i]=NULL;
	return;
    }
	else
	{
		
		for(i=0;i<4;i++)
		breaktree(parent->child[i]);
		free(parent);
		for(i=0;i<4;i++)
		parent->child[i]=NULL; 
	}
	return;
	
}

void growtree(Node *parent)
{
	int i;
	if(parent->child[0]==NULL)
	{
	makeChildren(parent);
	return;
    }
	else
	{
		
		for(i=0;i<4;i++)
		growtree(parent->child[i]);
	}
	return;
	
}

void freetree(Node *head)
{
	int i;
	for(i=0;i<4;i++)
	{
	free(head->child[i]);
	head->child[i]=NULL;
}

}

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];
  
  double h = pow(2.0,-level);
//printf("%f,%f,%f\n",x,y,h);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}


/*void findtree(Node *parent,double time,int level) 
{
	int i;
	for(i=0;i<4;i++)
	{
		if (parent->child[i]->child[i]!=NULL)
		findtree(parent->child[i]);
		return;
    }
    interesttree(parent,time,level)
    return;
}*/
void change(Node *node, double time )
{
	int b=0,i,z=0,k=0;
	double a,c;
	//printf("%f\n",a);
	
	
    a=nodeValue( node, time );
	if (node->child[0]==NULL&&a>0.5)
	{
		node->flag=1;
		makeChildren(node);
		count+=4;
		if(node->child[0]->level==maxlevel)
		max=1;
		return;
	}
	
	if (node->child[0]!=NULL)
	{   
	for(i=0;i<4;i++)
	{
		if(node->child[i]->child[0]==NULL&&nodeValue(node->child[i],time)<-0.5)
		z+=1;
	}
	if(z==4)
	{
	removes+=4;
	freetree(node);
	return;
	}
	for(i=0;i<4;i++)
	change(node->child[i],time);
	return;
}
}
void adapt(Node *head)
{
  int i=0;
  Node *node;
  do 
  {
  removes=0;
  count=0;
  change(head,0.0);
  totalRemove+=removes;
  totalAdd+=count; 
  printf("remove %i children\n",removes);
  printf("add %i children\n",count);
  }while(removes!=0||count!=0&&max==0);
}
