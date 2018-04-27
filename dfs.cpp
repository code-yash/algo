#include<iostream>
using namespace std;

class node
{ public: int val;
			 node *next;

			 node(int v,node *n=NULL)
			 { val=v;
				next=n;
			 }
};

class list
{ node *top;
  public: list()
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

int list :: retvals(int j)
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


void list :: adds(int x)
{ node *temp=new node(x,top);
 // int flag=0;
 // if(top!=NULL)
 //	flag=1;
  top=temp;
 // cout<<endl<<"added: "<<x<<endl;
 // cout<<endl<<top->val;
 // if(flag==1)
 //	cout<<endl<<"hhh: "<<top->next->val;

}

int list :: dels()
{ if(!top)
	return -1;
  node *temp=top;
  int t=temp->val;
  top=top->next;
  delete temp;
  return t;
}

void list :: display()
{ node *temp=top;

  while(temp)
  { cout<<endl<<temp->val;
	 temp=temp->next;
  }
}

class listq
{ node *head, *tail;
  public: listq()
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

int listq :: retValue(int i)
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

void listq :: add(int x)
{ node *temp=new node(x);

  if(isEmpty())
	head=tail=temp;

  else
	{ tail->next=temp;
	  tail=temp;
	}
}

int listq :: del()
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

void listq :: display()
{ node *temp=head;

  while(temp)
  { cout<<endl<<temp->val;
	 temp=temp->next;
  }
}


class graph
{ int v;
  listq *arr;

  public: graph(int ver)
			 { v=ver;
				arr=new listq[v];
			  }

			 void addEdge(int,int);
			 void display_g();
			 void dfs(int s);
};

void graph :: addEdge(int u,int v)
{ arr[u].add(v);
  arr[v].add(u);
}

void graph :: display_g()
{ for(int i=0;i<v;i++)
  { cout<<endl<<"The neighbours of "<<i<<" are: ";
	 arr[i].display();
	 cout<<endl;
  }
}

void graph :: dfs(int s)
{ //cout<<endl<<endl<<s;

  int visited[10];

  for(int i=0;i<v;i++)
	visited[i]=0;

  list stack;
  stack.adds(s);
  visited[s]=1;

  while(!stack.isEmpty())
  { s=stack.dels();
	 cout<<endl<<s;

	 int i=0;
	 
	 while(arr[s].retValue(i)!=-1)
	 {
		if(visited[arr[s].retValue(i)]==0)
	  { visited[arr[s].retValue(i)]=1;
		 stack.adds(arr[s].retValue(i));

		}
		i++;
	 }
  }
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
  g.dfs(0);

  return 0;
}
