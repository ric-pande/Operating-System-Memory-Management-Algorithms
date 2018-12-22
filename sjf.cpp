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
       int nextburst;
       int status;
}p[10];

int minjob(int n,int ex_time)
{
    int i,min,pr;
    min=100;
    for(i=0;i<n;i++)
    {
          if(p[i].status!=1&&p[i].nextburst<min&&p[i].arr<=ex_time)
          {
                min=p[i].nextburst;
                pr=i;
          }
    }
    return pr;
}

void wait_time(int n,int min,int exe)
{
     int i;
     for(i=0;i<n;i++)
     {
          if(i!=min&&p[i].arr<=exe&&p[i].status!=1)
          {
               p[i].waitm++;
               p[i].ta++;
          }
     }
}
     
int main()
{
    int n,i,j,cnt=0,min;
    printf("\nEnter no. of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         printf("\nEnter name,arrival time and burst time of process %d:",i+1);
         scanf("%s%d%d",p[i].name,&p[i].arr,&p[i].burst);
         p[i].status=0;
         p[i].waitm=0;
         p[i].nextburst=p[i].burst;
         p[i].ta=p[i].burst;
         cnt+=p[i].burst;
    }
    
    for(i=0;i<cnt;i++)
    {
         min=minjob(n,i);
         p[min].nextburst--;
         wait_time(n,min,i);
         if(p[min].nextburst==0)
             p[min].status=1;
    }
    
    printf("\nSJF scheduling\n");
    printf("\n Name   arr_time  burst_time  wait_time   ta_time\n");
    
    for(i=0;i<n;i++)
         printf("  %s  %d    %d    %d  %d\n",p[i].name,p[i].arr,p[i].burst,p[i].waitm,p[i].ta);
    getch();return 0;
}
