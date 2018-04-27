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
			 void bipartite(int);
			 void display_g();
};

void graph :: addEdge(int u, int w)
{ arr[u].add(w);
  arr[w].add(u);
}

void graph :: display_g()
{ for(int i=0;i<v;i++)
  { cout<<endl<<"Neighbours of "<<i<<" are: ";
	 //list *temp=&arr[i];
	 arr[i].display();
  }
}

void graph :: bipartite(int x)
{ int visited[10];
  for(int i=0;i<v;i++)
	visited[i]=0;

  visited[x]=1;

  list queue;

  queue.add(x);
  int flag=1;
  while(!queue.isEmpty() && flag==1)
  { x=queue.del();
	 int m=0;
	 while(arr[x].retValue(m)!=-1)
	 { if(visited[arr[x].retValue(m)]==0)
		 { if(visited[x]==1)
			 visited[arr[x].retValue(m)]=2;
			else
			 visited[arr[x].retValue(m)]=1;

			queue.add(arr[x].retValue(m));
		  }

		 else if(visited[arr[x].retValue(m)]==1 && visited[x]==2)
		 {}
		 else if(visited[arr[x].retValue(m)]==2 && visited[x]==1)
		 {}
		 else
		 { flag=0;
			break;
		 }
		m++;
	 }
  }

 if(flag==1)
  cout<<endl<<"The graph is a bipartite graph";
 else
  cout<<endl<<"The graph is not bipartite";
}

int main()
{ char ch;

  cout<<endl<<"Enter the number of vertices in the graph: ";
  int t;
  cin>>t;

  graph g(t);

  do
  { int u,v;
	 cout<<endl<<"Add a new edge\n Enter start point: ";
	 cin>>u;
	 cout<<endl<<"Enter end point: ";
	 cin>>v;
	 g.addEdge(u,v);

	 cout<<endl<<"Enter another edge?: ";
	 cin>>ch;
  } while(ch=='y' || ch=='Y');

  g.display_g();
  cout<<endl;

  g.bipartite((int)1);
  return 0;
}
