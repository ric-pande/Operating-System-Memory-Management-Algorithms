#include<iostream.h>
#include<conio.h>
#define max 5

struct process
{      
       char name[max];
       int arr;
       int burst;
       int waitm;
       //int start;
       //int finish;
       int ta;
       //int nextburst;
       //int status;
       int rt;  //remaining time
       int prio;
}p[10];

int minprio(int time,int n)
{
    int min=99,pr,i;`
     for(i=0;i<n;i++)
    {
        if(p[i].arr<=time && p[i].prio<min &&p[i].rt>0)
        {
              min=p[i].prio;
              pr=i;
        }
    }
    return pr;
}
          

int main()
{
    int n,i,cnt=0,min,smallest,remain,time;
    printf("\nEnter no. of processes:");
    scanf("%d",&n);
    
    remain=n;
    
    for(i=0;i<n;i++)
    {
         printf("\nEnter name,arrival time,burst time and priority of process %d:",i+1);
         scanf("%s%d%d%d",p[i].name,&p[i].arr,&p[i].burst,&p[i].prio);
         p[i].rt=p[i].burst;
         //p[i].ta=p[i].burst;
         p[i].waitm=0;
         
         
    }
    
    for(time=0;remain>0;time++)
    {
               smallest = minprio(time,n);
                 p[smallest].rt--;
                 p[smallest].ta++;
                 for(i=0;i<n;i++)
                 {
                        if(smallest!=i && p[i].rt && p[i].arr<=time)
                        {
                             p[i].waitm++;
                             p[i].ta++;
                        }
                 }
                   if(p[smallest].rt==0)
                   {
                     remain--;
                     //p[i].waitm=time+1-p[smallest].arr-p[smallest].burst;
                     //p[i].ta=time+1-p[smallest].arr;
                     printf("  %s  %d    %d    %d  %d\n",p[smallest].name,p[smallest].arr,p[smallest].burst,p[smallest].waitm,p[smallest].ta);
                   }
    }
    getch();return 0;
}
