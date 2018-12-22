#include<iostream.h>
#include<conio.h>

int n,str[30],fr[10],size;

void lru()
{
     int cnt[10],flag,num,i,f,j,count=0,x,y,c,m,min,current,k=0,value=0;
     
     for(i=0;i<size;i++) cnt[i]=-1;
     
     for(i=0;i<n;i++)
     {
         flag=0;
         num=str[i];
         
         for(j=0;j<size;j++)
         {
             if(num==fr[j])
             {
                 flag=1;cnt[j]=++value;
                 break;
             }
         }
         
         if(flag==0)     //page fault
         {
              if(k<size)
              {
                   cnt[k]=++value;
                   fr[k++]=str[i];
                   count++;
              }
                    
              else
              {//k=size
               min=999;
                   count++;
                   for(m=0;m<size;m++)
                   {
                         
                         current=fr[m];
                         if(cnt[m]<min)
                         {
                              min=cnt[m];
                              x=m;
                         }
                         
                   }
                   
                   fr[x]=num;
                   cnt[x]=++value;   //imp
              }
         }
         printf("\n");
         for(y=0;y<size;y++)
              printf("%d\t",fr[y]);
     }
     printf("\n Page faults: %d",count);
}

int main()
{
    int ch,i;
    printf("Enter total no. of pages");
    scanf("%d",&n);
    
    printf("Enter sequence");
    for(i=0;i<n;i++)
        scanf("%d",&str[i]);
    printf("Enter size of page frame");
    scanf("%d",&size);
    
    for(i=0;i<size;i++) fr[i]=-1;
    
    lru(); 
    getch();return 0;
     
}
