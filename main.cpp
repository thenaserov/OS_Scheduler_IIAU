#include <iostream>
#include <string.h>
#include <stdio.h>

        using namespace std;
        int fcfs();
        int sjf();
        int rr();
        int srt();
        int mlfq();
        int main(int arg,char** argv){
                 int i,n,c,a,j,t_vcpu[10],t_ecpu[10];
            char name[10] [10];
            int t_vorod[10],t_service[10],t_entezar[10],t_bargasht[10];
            float AAT,AWT,sum1=0,sum2=0;
                 do{
                cout<<"\t main menu \n";
                cout<<"\t 1 - algoritm fcfs \n";
                cout<<"\t 2 - algoritm sjf \n";
                cout<<"\t 3 - algoritm srt \n";
                cout<<"\t 4 - algoritm rr \n";
                cout<<"\t 5 - algoritm mlfq \n";
                cout<<"\t 6 - khoroj \n";
                cout<<"\t  please enter number (1-6):";
                cin>>c;
            }
            while((c!=1) && (c!=2) && (c!=3) && (c!=4) && (c!=5) && (c!=6));

           switch(c){
            case 1:fcfs ();break;
            case 2:sjf(); break;
            case 3:srt(); break;
            case 4:rr(); break;
            case 5:mlfq(); break;
            default:cout<<"end";

           }
           return 0 ;}
           int fcfs(){
            int  p[10],at[10],bt[10],ct[10],tat[10],wt[10],i,j,temp=0,n;
    float awt=0,atat=0;
    printf("enter no of proccess you want:");
    scanf("%d",&n);
    printf("enter %d process:",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&p[i]);
    }
    printf("enter %d arrival time:",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&at[i]);
    }
    printf("enter %d burst time:",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&bt[i]);
    }
    // sorting at,bt, and process according to at
    for(i=0;i<n;i++)
    {
     for(j=0;j<(n-i);j++)
    {
      if(at[j]>at[j+1])
     {
        temp=p[j+1];
        p[j+1]=p[j];
        p[j]=temp;
        temp=at[j+1];
        at[j+1]=at[j];
        at[j]=temp;
        temp=bt[j+1];
        bt[j+1]=bt[j];
        bt[j]=temp;
      }
     }
    }
    /* calculating 1st ct */
    ct[0]=at[0]+bt[0];
    /* calculating 2 to n ct */
    for(i=1;i<n;i++)
    {  
      //when proess is ideal in between i and i+1
      temp=0;
     if(ct[i-1]<at[i])
     {
        temp=at[i]-ct[i-1];
     }
     ct[i]=ct[i-1]+bt[i]+temp;
    }
    /* calculating tat and wt */
    printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
    for(i=0;i<n;i++)
    {
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    atat+=tat[i];
    awt+=wt[i];
    }
    atat=atat/n;
    awt=awt/n;
    for(i=0;i<n;i++)
    {
      printf("\nP%d\t %d\t %d\t %d \t %d \t %d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\naverage turnaround time is %f",atat);

    printf("\naverage wating timme is %f",awt);
                    return 0 ; }

                   int sjf(){


      int arrival_time[10], burst_time[10], temp[10];
      int i, smallest, count = 0, time, limit;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;
      printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &limit); 
      printf("\nEnter Details of %d Processesn", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      }
      burst_time[9] = 9999;  
      for(time = 0; count != limit; time++)
      {
            smallest = 9;
            for(i = 0; i < limit; i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            if(burst_time[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
      }
      average_waiting_time = wait_time / limit; 
      average_turnaround_time = turnaround_time / limit;
      printf("\n\nAverage Waiting Time:\t%lf\n", average_waiting_time);
      printf("Average Turnaround Time:\t%lf\n", average_turnaround_time);
      return 0;



                    return 0 ; }
                    
                    int rr() {
                    
      int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10]; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit); 
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
      return 0; 
                    	
                    return 0;}

                     int srt() {
                     	int at[10],bt[10],rt[10],endTime,i,smallest;

 int remain=0,n,time,sum_wait=0,sum_turnaround=0;

 printf("Enter no of Processes : ");

 scanf("%d",&n);

 for(i=0;i<n;i++)

 {

 printf("Enter arrival time for Process P%d : ",i+1);

 scanf("%d",&at[i]);

 printf("Enter burst time for Process P%d : ",i+1);

 scanf("%d",&bt[i]);

 rt[i]=bt[i];

 }

 printf("\n\nProcess\t|Turnaround Time| Waiting Time\n\n");

 rt[9]=9999;

 for(time=0;remain!=n;time++)

 {

 smallest=9;

 for(i=0;i<n;i++)

 {

 if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)

 {

 smallest=i;

 }

 }

 rt[smallest]--;

 if(rt[smallest]==0)

 {

 remain++;

 endTime=time+1;

 printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-at[smallest],endTime-bt[smallest]-at[smallest]);

 sum_wait+=endTime-bt[smallest]-at[smallest];

 sum_turnaround+=endTime-at[smallest];

 }

 }

 printf("\n\nAverage waiting time = %f\n",sum_wait*1.0/n);

 printf("Average Turnaround time = %f",sum_turnaround*1.0/5);
                    return 0;
                    }
 
#define N 10 
 
struct process
{
    char name;
    int AT,BT,WT,TAT,RT,CT;
}Q1[10],Q2[10],Q3[10];/*Three queues*/

int n;
void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            {
                if(Q1[i].AT>Q1[j].AT)
                    {
                          temp=Q1[i];
                          Q1[i]=Q1[j];
                          Q1[j]=temp;
                    }
            }
    }
}
                     int mlfq() {
        int i,j,k=0,r=0,time=0,tq1=5,tq2=8,flag=0;
     char c;
     printf("Enter no of processes:");
     scanf("%d",&n);
     for(i=0,c='A';i<n;i++,c++)
     {
         Q1[i].name=c;
         printf("\nEnter the arrival time and burst time of process %c: ",Q1[i].name);
         scanf("%d%d",&Q1[i].AT,&Q1[i].BT);
         Q1[i].RT=Q1[i].BT;/*save burst time in remaining time for each process*/

    }
sortByArrival();
time=Q1[0].AT;
printf("Process in first queue following RR with qt=5");
printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
for(i=0;i<n;i++)
{

  if(Q1[i].RT<=tq1)
  {

       time+=Q1[i].RT;/*from arrival time of first process to completion of this process*/
       Q1[i].RT=0;
       Q1[i].WT=time-Q1[i].AT-Q1[i].BT;/*amount of time process has been waiting in the first queue*/
       Q1[i].TAT=time-Q1[i].AT;/*amount of time to execute the process*/
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q1[i].name,Q1[i].BT,Q1[i].WT,Q1[i].TAT);

  }
  else/*process moves to queue 2 with qt=8*/
  {
      Q2[k].WT=time;
      time+=tq1;
      Q1[i].RT-=tq1;
      Q2[k].BT=Q1[i].RT;
      Q2[k].RT=Q2[k].BT;
      Q2[k].name=Q1[i].name;
      k=k+1;
      flag=1;
   }
}
if(flag==1)
 {printf("\nProcess in second queue following RR with qt=8");
  printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
}for(i=0;i<k;i++)
   {
    if(Q2[i].RT<=tq2)
     {
       time+=Q2[i].RT;/*from arrival time of first process +BT of this process*/
       Q2[i].RT=0;
       Q2[i].WT=time-tq1-Q2[i].BT;/*amount of time process has been waiting in the ready queue*/
       Q2[i].TAT=time-Q2[i].AT;/*amount of time to execute the process*/
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q2[i].name,Q2[i].BT,Q2[i].WT,Q2[i].TAT);

    }
    else/*process moves to queue 3 with FCFS*/
    {
      Q3[r].AT=time;
      time+=tq2;
      Q2[i].RT-=tq2;
      Q3[r].BT=Q2[i].RT;
      Q3[r].RT=Q3[r].BT;
      Q3[r].name=Q2[i].name;
      r=r+1;
      flag=2;
    }
  }

{if(flag==2)
printf("\nProcess in third queue following FCFS ");
}
for(i=0;i<r;i++)
{
    if(i==0)
            Q3[i].CT=Q3[i].BT+time-tq1-tq2;
        else
            Q3[i].CT=Q3[i-1].CT+Q3[i].BT;

}

for(i=0;i<r;i++)
    {
        Q3[i].TAT=Q3[i].CT;
        Q3[i].WT=Q3[i].TAT-Q3[i].BT;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t",Q3[i].name,Q3[i].BT,Q3[i].WT,Q3[i].TAT);
    }
      return 0; 
}
