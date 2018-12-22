#include<iostream.h>
#include<conio.h>
using namespace std;

int main()
{
    int i,j,cnt,np,nr,max[10][10],alloc[10][10],need[10][10],pr[10],avail[10],k=0,num=0,order[10];
    printf("\nEnter no. of processes:");
    scanf("%d",&np);
    printf("\nEnter no. of resources:");
    scanf("%d",&nr);
    
    printf("\nEnter max demand matrix:");
    for(i=0;i<np;i++)
    for(j=0;j<nr;j++)
    scanf("%d",&max[i][j]);
    
    printf("\nEnter allocated matrix:");
    for(i=0;i<np;i++)
    for(j=0;j<nr;j++)
    scanf("%d",&alloc[i][j]);
    
    for(i=0;i<np;i++)
    for(j=0;j<nr;j++)
    {if(max[i][j]<alloc[i][j]){printf("\nIncorrect matrix");getch();return 0;}}
    
    printf("\nEnter resources available:");
    for(i=0;i<nr;i++)
    scanf("%d",&avail[i]);
    
    for(i=0;i<np;i++)
    for(j=0;j<nr;j++)
    need[i][j]=max[i][j]-alloc[i][j];
    
    for(i=0;i<np;i++)
      pr[i]=0;
    
    while(num<np)
    {
                 for(i=0;i<np;i++)
                 {
                                  cnt=0;
                                  if(pr[i]==0)
                                  {
                                              for(j=0;j<nr;j++)
                                              {
                                                               if(need[i][j]<=avail[j])
                                                                   cnt++;
                                              }
                                  }
                                  if(cnt==nr) break;
                 }
                 
        if(cnt==nr)
        {
            num++;       
            pr[i]=1;
            order[k++]=i;
            for(j=0;j<nr;j++)
                avail[j] += alloc[i][j];   //imp
        }
     }
     
     for(i=0;i<k;i++)
     printf("\t%d",order[i]);
     getch();return 0;
}
