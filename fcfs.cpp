#include<iostream.h>
#include<conio.h>
#define max 5

struct process
{      
       char name[max];
       int arr;
       int burst;
       int waitm;
       int start;
       int finish;
       int ta;
};

void swap(struct process *a,struct process *b)
{
     struct process c;
     c=*a;
     *a=*b;
     *b=c;
}

int main()
{
    struct process p[10];
    int n,i,j;
    printf("\nEnter no. of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         printf("\nEnter name,arrival time and burst time of process %d:",i+1);
         scanf("%s%d%d",p[i].name,&p[i].arr,&p[i].burst);
    }
    
    for(i=0;i<n;i++)
         for(j=i+1;j<n;j++)
               if(p[i].arr>p[j].arr)  swap(&p[i],&p[j]);
               
    for(i=0;i<n;i++)
    {
       if(i==0)
               p[i].start=p[i].arr;
       else
               p[i].start=p[i-1].finish;
       
       p[i].waitm=p[i].start-p[i].arr;
       
       p[i].finish=p[i].start+p[i].burst;
       
       p[i].ta=p[i].finish-p[i].arr;
    }
    
    printf("\nFCFS scheduling\n");
    printf("\n Name   arr_time  burst_time  wait_time  start_time   finish_time   ta_time\n");
    
    for(i=0;i<n;i++)
         printf("  %s  %d    %d    %d     %d    %d       %d\n",p[i].name,p[i].arr,p[i].burst,p[i].waitm,p[i].start,p[i].finish,p[i].ta);
    getch();return 0;
}
