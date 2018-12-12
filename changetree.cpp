#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include"treeStructure.h"
#include"buildtree.h"
int removes=0;
int count=0;
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
void interesttree(Node *node, double time,int level )
{
	int b=0,i,z=0,k=0;
	double a,c;
	//printf("%f\n",a);
	if(level==0)
	return;
	if (node->child[0]!=NULL)
	{   
	for(i=0;i<4;i++)
	{
		if(node->child[i]->child[i]!=NULL)
		z=1;
	}
	if(z==1)
	{
	for(i=0;i<4;i++)	
	interesttree(node->child[i],time,level-1);
	return;
	} 
	else
	{
	k=1;
	goto abc;
}
    }
	a=nodeValue( node, time );
	if (a>0.5)
	{
		node->flag=0;
		makeChildren(node);
		abc:
		for(i=0;i<4;i++)
		{
			c=nodeValue(node->child[i],time);
			if(c<-0.5)
			{
			b+=1;
			node->child[i]->flag=-1;
		    }
			else if(c>0.5)
			{
			node->child[i]->flag=1;
			interesttree(node->child[i],time,level-1);
			if(k!=1)
			count+=1;
		    }
		    else
		    node->child[i]->flag=0;
		    //printf("%f\n",c);
		}
		if(b==4)
		{
			removes+=4;
		   	freetree(node);
		   	
		}
	}
	return;
}
