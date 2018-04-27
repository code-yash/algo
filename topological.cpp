#include<iostream>
using namespace std;

class node
{ public: int val;
			 node *next;
			 node(int v, node *n=NULL)
			 { val=v;
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
{ int v, e;
  list *arr;

  public: graph(int ver)
			 { v=ver;
				e=0;
				arr=new list[v];
			  }

			  void addEdge(int s,int d);
			  void display_g();
			  void topological();
};

void graph :: addEdge(int s,int d)
{ arr[d].add(s);
  e++;
}

void graph :: display_g()
{ for(int i=0;i<v;i++)
  { cout<<endl<<"Neighbor(s) of "<<i<<" are:";
	 arr[i].display();
  }
}

void graph :: topological()
{ int flag=1;

  if(e>(v*(v-1)) || e<(v-1))
	flag=0;

  else
  { int visited[10];
	 for(int i=0;i<v;i++)
	  visited[i]=0;

	 for(int i=0;i<v && flag==1;i++)
	 { int s=-1;

		for(int j=0;j<v && s==-1;j++)
		 { if(arr[j].isEmpty() && visited[j]!=-1) 
			 { visited[j]=-1;
				s=0;
			 }
		 }

		if(i==0 && s!=0)//cicle checking
		 flag=0;

		if(s!=0)//no circle
		{ for(int k=0;k<v && s==-1;k++)
		  { int m=0,ex=0;
			 while(arr[k].retValue(m)!=-1 && ex==0)
			  { if(visited[arr[k].retValue(m)]==-1)
				  m++;
				 else
				  ex=1;
				 if(arr[k].retValue(m)==-1)
				  { visited[k]=-1;
					 s=0;
				  }
			  }
		  }
		}

	  if(s==-1)
		flag=0;
	 }
	}
  if(flag==1)
	cout<<endl<<"Topological ordering possible";
  else
	cout<<endl<<"NOT POSSIBLE";

}

int main()
{ char ch;

  cout<<endl<<"Enter the number of vertices in the graph : ";
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

  g.topological();
  return 0;
}
