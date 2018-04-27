#include <iostream>
using namespace std;
int  main()
{
	int i,j;
	int v;
   cout << "\nPlease enter the number of vertices: ";
   cin >> v;

   int** graph = new int*[v];
   for( i=0;i<v;i++)
          graph[i] = new int[v];

   for(i=0;i<v;i++)
            {
              for(j=0;j<v;j++)
                      {
                        cout << "( " << i << " , " << j << " )";
                        cin >> graph[i][j];
                      }
            }
    int min=999,des,dis;
	int cover[v];
	
	for (i=0;i<v;i++)
	cover[i]=0;
	
	        i=0;
    while(cover[i]!=-1)
    {
    	for (j=0;j<v;j++)
    	{
    		if (cover[j]==-1)
    		continue;
    		else if (graph[i][j]< min && graph[i][j]!=0)
    		{
    			min=graph[i][j];
    			des=j;
    			dis=min;
			}
		}
		cout << i <<" to " <<des <<"---- " <<dis<<endl;
		cover[i]=-1;
		i=des;
		min=999;
	}
	
	return 0;
}
