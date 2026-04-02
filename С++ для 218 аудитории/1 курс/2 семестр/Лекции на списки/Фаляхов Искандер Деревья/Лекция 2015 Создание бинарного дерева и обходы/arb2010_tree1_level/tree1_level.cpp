//arb1.txt   1 3 10 20 14 17 2 4 5 50 40 11 13 12
// 1 -level 1
// 2 -level 3
// 3 -level 2 10  
// 4 -level  4 20
// 5 -level  5 14 50
// 6-level  11 17 40
// 7-level 13
// 8-level 12

//arb2015_tree_level
#include<iostream>
#include<fstream>
using namespace std;
////////////////////////
struct treeNode
{
 treeNode* left;
 treeNode* right;
 int   data;
};
///////////////////////
struct queueNode
{
  queueNode* next;
  treeNode*  node; 
};
//////////////////////
ifstream f("arb.txt");
////////////////////////////////////////// 
void create_tree(ifstream &f,treeNode* &tree_top)
 {
    treeNode *p,*m;
    bool b;
    tree_top=NULL;
    int x;
          while(f>>x)
		  {
		 
		      if(tree_top==NULL)
			  {
	  	           m=new treeNode;
       	           m->data=x;
   		           m->left=NULL;
		           m->right=NULL;
                   tree_top=m;		  
			  }
              else		  
			  {
			        m=tree_top;
					b=true;
					while(b)
					{
				        if (x>=m->data)
						{
						     if(m->right)
								m=m->right;
							 else
							 {  
								 p=new treeNode;
								 p->data=x;
								 p->left=NULL;
                                 p->right=NULL;
								 m->right=p;
								 b=false;
							 }
					
						}
						else
						{ 
							 if(m->left)
								 m=m->left;
							 else
							 {
							 p=new treeNode;
								 p->data=x;
								 p->left=NULL;
                                 p->right=NULL;
								 m->left=p;
								 b=false;
							 }
												
						}               
					}
			  }    
		  } 
 }

/////////////////////////
void push_queue(queueNode* &q_top,queueNode *&q_end,treeNode* t)
{
       queueNode* p;
       if(q_top)
	   {
           p=new queueNode;
		   p->node=t;
		   p->next=NULL;
		   q_end->next=p;
		   q_end=p;
	   }
       else
	   {
	    p=new queueNode;
		   p->node=t;
		   p->next=NULL;
		   q_top=p;
		   q_end=p;
		}
}
//////////////////////////////////////////////////////////////
void pop_queue(queueNode* &q_top,treeNode* &t)
//get node of tree from queue 
{
    queueNode *p;
      t=q_top->node;
	  p=q_top->next;
	  delete q_top;
	  q_top=p;
	
}
/////////////////////////////////////////////////////////////
void levels_tree(treeNode *tree_top)
{
    queueNode *q_top,*q_end;
	int i,n,k,k1;
	// k1 - number of nodes tree in n- level
	treeNode *p;
	p=tree_top;

	if(p)
	{
	  q_top=NULL;
	  q_end=NULL;
	  n=1;
// n - number  level of tree
	push_queue(q_top,q_end,p);
	k=1;
	do
		{
	          cout<<n<<" - level";
			  k1=0;
               for(i=1;i<=k;i++)
			   {
			        pop_queue(q_top,p);
             	    cout<<" "<<p->data;
				
			        if(p->left)
					{
			          push_queue(q_top,q_end,p->left);
					  k1++;
					}

                    if(p->right)
					{
			          push_queue(q_top,q_end,p->right);
					  k1++;
					}
			   }
                cout<<endl;
                n++;
				k=k1;
		}
	    while(k!=0);
	}
                        
}
////////////////////////////
void main()
{
treeNode* tree_top;
create_tree(f,tree_top);
levels_tree(tree_top);
}
/////////////////////////////