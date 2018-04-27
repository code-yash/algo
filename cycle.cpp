#include<iostream>
using namespace std;

class node
{ public: int val;
			 node *next;

			 node(int i, node *n=NULL)
			 { val=i;
				next=n;
			 }
};

class lists
{ node *top;
  public: lists()
			 { top=NULL;
			  }

			 int isEmpty()
			 { if(top==NULL)
				 return 1;
				return 0;
			 }

			 void adds(int);
			 int dels();
			 void display();
			 int retvals(int);
};

int lists :: retvals(int j)
{ int i=0;
  node *temp=top;
  while(i!=j)
  { temp=temp->next;
	 i++;
  }
  if(temp)
	return temp->val;
  return -1;
}


void lists :: adds(int x)
{ node *temp=new node(x,top);

  top=temp;
}

int lists :: dels()
{ if(!top)
	return -1;
  node *temp=top;
  int t=temp->val;
  top=top->next;
  delete temp;
  return t;
}

void lists :: display()
{ node *temp=top;

  while(temp)
  { cout<<endl<<temp->val;
	 temp=temp->next;
  }
}



class list
{ node *head, *tail;
  public: list()
			 { head=tail=NULL;
			  }
			 int isEmpty()
			 { if(!head)
				 return 1;
				return 0;
			 }
			 void add(int x);
			 int del();
			 void display();
			 int retValue(int);
};

int list :: retValue(int i)
{ node *temp=head;

  int j=0;
  while(j!=i)
  { temp=temp->next;
	 j++;
  }
  if(temp==NULL)
	return -1;
  return temp->val;
}

void list :: add(int x)
{ node *temp=new node(x);

  if(isEmpty())
	head=tail=temp;


  else
	{ tail->next=temp;
	  tail=temp;
	}
}

int list :: del()
{ if(isEmpty())
	return -1;

  else
  { node *temp=head;
	 int n=temp->val;
	 head=head->next;
	 delete temp;
	 if(!head)
	  tail=NULL;
	 return n;
	}
}

void list :: display()
{ node *temp=head;

  while(temp)
  { cout<<endl<<temp->val;
	 temp=temp->next;
  }
}

class graph
{ int v;
  list *arr;

  public: graph(int ver)
			 { v=ver;
				arr=new list[v];
			 }

			 void addEdge(int,int);
			 void detect_cycle();
			 void display_g();
			 void showcycle(int,int[],int);
			 int allvisited(int[]);
};

void graph :: addEdge(int u, int w)
{ arr[u].add(w);
  //arr[w].add(u);
}

void graph :: display_g()
{ for(int i=0;i<v;i++)
  { cout<<endl<<"Neighbours of "<<i<<" are: ";
	 //list *temp=&arr[i];
	 arr[i].display();
  }
}

int graph :: allvisited(int vis[])
{ int flag=0;
  for(int i=0;i<v;i++)
	if(vis[i]==-1)
	{ flag=1;
	  break;
	}
  return flag;
}

void graph :: showcycle(int x, int parent[],int y)
{
  cout<<endl<<"cycle is: "<<x<<y;
  int i=y;

  while(parent[i]!=x && parent[i]!=-2)
	{ cout<<parent[i];
	  i=parent[i];
	 }
}

void graph :: detect_cycle()
{ int visited[10],parent[10];

  for(int i=0;i<v;i++)
  { parent[i]=-1;             //-1=INITIAL,-2=NILL
	 visited[i]=-1;
  }

  int x=1,flag=0;            //input value of x

  lists stack;
  stack.adds(x);

  parent[x]=-2;
  visited[x]=1;

  while(allvisited(visited)!=0 || !stack.isEmpty())          //<SEE
  {
	 x=stack.dels();
	 //cout<<endl<<"val:"<<x<<endl;
	 if(x==-1)
	  for(int i=0;i<v;i++)
		if(visited[i]==-1)
		 { x=i;
			parent[x]=-2;
			visited[x]=1;
			break;
		 }

	 int m=0;
	 while(arr[x].retValue(m)!=-1 && flag==0)
	 { if(parent[arr[x].retValue(m)]==-1)
		 { parent[arr[x].retValue(m)]=x;
			visited[arr[x].retValue(m)]=1;
			stack.adds(arr[x].retValue(m));
		  }
		else if(parent[arr[x].retValue(m)]==x)// || parent[arr[x].retValue(m)]==-2)
		{}
		else
		{ flag=1;
		  cout<<endl<<x<<" "<<parent[x]<<endl;
 /* for(int k=0;k<v;k++)
	cout<<parent[k];
*/

		  showcycle(x,parent,parent[x]);
		}
		m++;
	 }
	}
   for(int k=0;k<v;k++)
	cout<<parent[k];

}

int main()
{ char ch;

  int num;
  cout<<endl<<"Enter the number of vertices you want to add to the graph: ";
  cin>>num;

  graph g(num);

  do
  { int u,x;
	 cout<<endl<<"Enter starting point: ";
	 cin>>u;
	 cout<<endl<<"Enter finish point: ";
	 cin>>x;

	 g.addEdge(u,x);
	 cin>>ch;
  } while(ch=='y' || ch=='Y');

  g.display_g();
  g.detect_cycle();

  return 0;
}

//input: 10
//			13
//			32
//			21
