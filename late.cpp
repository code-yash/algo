#include <iostream>
#include <algorithm>
using namespace std;
 
class Job {
public:
    int deadline, length;
 
    bool operator < (const Job& x) const   {
        return deadline < x.deadline;
    }
} *jobs;
 
int main()  {
    int N, i,d,l, last_finished, s, lateness, temp;
    cout<<"enter the no of jobs";
    cin>>N;
 
   // scanf("%d", &N); // Number of jobs
    jobs = new Job[N];
    for (i = 0; i < N; i++)
       { // deadline and length of each job
               cout<<"ENTER THE DEADLINE OF JOB "<<i+1<<" : ";
               cin>>d;
               cout<<"ENTER THE LENGTH OF JOB "<<i+1<<" : ";
               cin>>l;
        jobs[i].deadline=d ; jobs[i].length = l;
      }
  cout<<"ENTER THE TIME WHEN JOBS ARE AVAILBLE ";
  cin>>s;
   // scanf("%d", &s); // time at which the jobs become available
 
    // sort jobs in non-decreasing order of deadline
    sort(jobs, jobs + N);
 
    // print the optimal solution
    cout<<"Optimal schedule :\n";
    for (i = 0, last_finished = s, lateness = 0; i < N; i++)	{
    	// job i runs from last_finished to last_finished + jobs[i].length
    	temp = last_finished + jobs[i].length;
    	cout<<"Job  "<< i<<" : [ "<< last_finished <<" , "<< temp<< " ] \n";
    	last_finished = temp;
    	
    	// If last_finished > jobs[i].deadline
	// then lateness of job i = last_finished - jobs[i].deadline
	// otherwise lateness of job i = 0
	temp = max(last_finished - jobs[i].deadline, 0);
	if (lateness < temp)
		lateness = temp;
    }
    cout<<"Maximum lateness of schedule : "<< lateness<<endl;
 
    return 0;
}
