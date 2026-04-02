//arb2014_create_tree_push

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
struct stackNode
{
  stackNode* next;
  treeNode*  node; 
};
//////////////////////
void push_tree(treeNode* &tree_top, int x)
{
    treeNode *p,*m;
    bool b;
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
			 if(m->left) m=m->left;
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
/////////////////////////////////////////////////
void push_stack(stackNode* &stack_top,treeNode* t)
{
           stackNode* p;
           p=new stackNode;
		   p->node=t;
		   p->next=stack_top;
		   stack_top=p;
 }
//////////////////////////////////////////////////////////////
void create_tree(ifstream &f,treeNode* &tree_top)
 {
    tree_top=NULL;
    int x;
          while(f>>x)
		
		  {
			  push_tree(tree_top,x);
		  }
}
/////////////////////////
void pop_stack(stackNode* &stack_top,treeNode* &t)
//get node of tree from stack 
{
    stackNode *p;
    if (stack_top!=NULL)
	{
	  t=stack_top->node;
	  p=stack_top->next;
	  delete stack_top;
	  stack_top=p;
	}
}
//////////////////////////////
void print_node(int x)
{
   cout<<" "<<x;
}
////////////////////////////
void inorder_tree(treeNode* tree_top)
//simmetric 
{
        stackNode* stack_top;
        treeNode* tree_p;
        tree_p=tree_top;
	    stack_top=NULL;
	do 
	{ 
		while(tree_p)
		{
			while(tree_p->left)
			{
			push_stack(stack_top,tree_p);
			tree_p=tree_p->left;
			}
        	print_node(tree_p->data);
	    	tree_p=tree_p->right;
		}
		
		if (stack_top)
		{
		  pop_stack(stack_top,tree_p);
	      print_node(tree_p->data);
          tree_p=tree_p->right;
		}
	}while(stack_top || tree_p);	
	cout<<endl;
	}
//////////////////////////////////////
void main()
{
	int x;
ifstream f("arb.txt");
treeNode* tree_top;
create_tree(f,tree_top);
inorder_tree(tree_top);
f.close();
cout<<"enter x=";
cin>>x;
push_tree(tree_top,x);
cout<<"order sequence= "<<endl;
inorder_tree(tree_top);
}
///////////

