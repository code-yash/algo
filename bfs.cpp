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
			 { if(!head) //NOT OF(HEAD) I.E. IF HEAD == NUll which is 0 hence !(0) is 1 ::::0 is true and 1 is false
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
{ if(isEmpty())//checks q ka head //head==null is false hence 1 (!1 is 0) returns 1//since returns 1 so wont enter if//all this for first iteration
	return -1;

  else
  { node *temp=head;
	 int n=temp->val;
	 head=head->next;
	 delete temp;
	 if(!head)//if head==null
	  tail=NULL;
	 return n;// s for first iteration
	}
}

void list :: display()
{ node *temp=head;

  while(temp)//while temp is not null
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
			 void bfs(int);
			 void display_g();
};

void graph :: addEdge(int u, int w)
{ arr[u].add(w);//list class array arr
  arr[w].add(u);
}

void graph :: display_g()
{ for(int i=0;i<v;i++)
  { cout<<endl<<"Neighbours of "<<i<<" are: ";
	 //list *temp=&arr[i];
	 arr[i].display();
  }
}

void graph :: bfs(int s)
{ int visited[10];

  for(int i=0;i<v;i++)
	visited[i]=0;

  visited[s]=1;

  list q;
  q.add(s);

  while(!q.isEmpty())// since a has s in it hence q==null is false  i.e. 1 then (!1 is 0) then returns 1 hence //!1 i.e. 0
  { s=q.del();//iteration--->//s //1 //
	 cout<<s<<":";// 0 1 2 3 4 6 7 5

	 for(int i=0;arr[s].retValue(i)!=-1;i++)//till adjascent nodes are present
	 { if(visited[arr[s].retValue(i)]==0)
		{ visited[arr[s].retValue(i)]=1;
		  q.add(arr[s].retValue(i));//if already visited then will not be added in q
		 }
	 }
	 cout<<endl;
	}
}

int main()
{ char ch;

  cout<<endl<<"Enter the number of vertices in the graph: ";
  int t;
  cin>>t;

  graph g(t);//calling constructor making an array of nodes

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

  int num;
  cout<<endl<<"Enter the source vertext: ";
  cin>>num; 
  g.bfs(num);
  return 0;
}
