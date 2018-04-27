#include<iostream>
using namespace std;

class node
{ public: int des;
			 int dist;
			 node *next;

			 node(int d, int dis=0, node *n=NULL)
			 { des=d;
				dist=dis;
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
			 void add(int x,int);
			 int del();
			 void display();
			 int retValue(int);
			 node *retNode(int);

};

node* list :: retNode(int i)
{ node *temp=head;
  while(temp->des!=i)
	temp=temp->next;
  return temp;
}

int list :: retValue(int i)
{ node *temp=head;

  int j=0;
  while(j!=i)
  { temp=temp->next;
	 j++;
  }
  if(temp==NULL)
	return -1;
  return temp->des;
}

void list :: add(int x,int d=0)
{ node *temp=new node(x,d);

  if(isEmpty())
	head=tail=temp;

  else
	{ tail->next=temp;
	  tail=temp;
	}
}

int list :: del()
{ if(isEmpty())
	return NULL;

  else
  { node *temp=head;
	 int n=temp->des;
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
  { cout<<endl<<temp->des<<"   "<<temp->dist;
	 temp=temp->next;
  }
}

class graph
{ int v,e;
  list *arr;

  public: graph(int ver)
			 { v=ver;
				e=0;
				arr=new list[v];
			 }
			 void addEdge(int u,int v);
			 void display_g();
			 void dijkstra(int u,int v);
};

void graph :: addEdge(int u,int v)
{ int d;
  cout<<endl<<"Enter the distance between "<<u<<" and "<<v;
  cin>>d;
  arr[u].add(v,d);
  e++;
}

void graph :: display_g()
{ for(int i=0;i<v;i++)
  { cout<<endl<<"The neighbours of "<<i<<" are: "<<endl;
	 arr[i].display();
  }
}

void graph :: dijkstra(int u,int d)
{ int dist_s[10];
  for(int i=0;i<v;i++)
	dist_s[i]=-1;

  dist_s[u]=0;

  for(int i=0;i<v;i++)
	cout<<endl<<dist_s[i];

  cout<<endl<<endl;

  list queue;
  queue.add(u);

  int m=0;

  while(!queue.isEmpty())
  { int x=queue.del();//return des wala part
	 cout<<endl<<"val: "<<x;//0 1 2

	 int n=0;
	 while(arr[x].retValue(n)!=-1)
	 { node *i= arr[x].retNode(arr[x].retValue(n));
		cout<<endl<<"retVl: "<<arr[x].retValue(n)<<"dist"<<i->dist;//0;1 dist 1;//2 dist 2//4 dist 4//1; 0 dist 1 4-1 5-3//
		if(dist_s[arr[x].retValue(n)]==-1)
		 { dist_s[arr[x].retValue(n)]=dist_s[x]+i->dist;
			queue.add(arr[x].retValue(n));//[1,0] [2,0] [4,0] [5,0] [3,0]
			}
		else if(dist_s[arr[x].retValue(n)]>dist_s[x]+i->dist)
		 dist_s[arr[x].retValue(n)]=dist_s[x]+i->dist;
		n++;
	 }
	}
	for(int i=0;i<v;i++)
	 cout<<endl<<dist_s[i];
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

  g.dijkstra(0,5);
  return 0;
}
