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
       int carr;
       int cburst;  //burst value changes
}p[10];

int main()
{
    int n,i,j,x=0,tot=0,quantum;
    printf("\nEnter no. of processes:");
    scanf("%d",&n);
    
    printf("Enter time quantum");
    scanf("%d",&quantum);
    
    for(i=0;i<n;i++)
    {
         printf("\nEnter name,arrival time,burst time of process %d:",i+1);
         scanf("%s%d%d",p[i].name,&p[i].arr,&p[i].burst);
         p[i].arr =p[i].carr;
         p[i].cburst =p[i].burst;
         tot  += p[i].burst;
         p[i].ta =p[i].burst;
         p[i].waitm =0;
    }
    
    while(x<tot)  //x=time
    {
         for(i=0;i<n;i++)
         {
              if(p[i].burst>=quantum && x>=p[i].arr)
              {
                   x+=quantum;
                   for(j=0;j<n;j++)
                   {
                           if(j!=i && x>=p[j].arr && p[j].burst)
                           {
                                   p[j].waitm +=quantum;
                                   p[j].ta +=quantum;
                           }
                   }
                   p[i].burst -=quantum;
              }
              
              else if(p[i].burst<quantum && p[i].burst && x>=p[i].arr)
                   {
                         x +=p[i].burst;
                         for(j=0;j<n;j++)
                         {
                           if(j!=i && x>=p[j].arr && p[j].burst)
                           {
                                   p[j].waitm += p[i].burst;
                                   p[j].ta+=p[i].burst;
                           }
                         }
                         p[i].burst = 0;
                   }
         }
    }
    
    for(i=0;i<n;i++)
         printf("  %s  %d    %d    %d  %d\n",p[i].name,p[i].arr,p[i].cburst,p[i].waitm,p[i].ta);
    getch();return 0;
}
