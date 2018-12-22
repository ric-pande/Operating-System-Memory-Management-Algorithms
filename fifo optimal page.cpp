#include<iostream.h>
#include<conio.h>

int n,str[30],fr[10],size;
                                                                        //size is size of fr //str is input sequence
void fifo()
{
     int i=0,x,j,k=0,m=0,count=0,num,flag;
     while(i<n)
     {        
               flag=0;
               num=str[i];
               
               for(j=0;j<size;j++)
               {
                    if(num==fr[j])
                    {
                        i++;
                        flag=1;
                        break;
                    }
               }
               
               if(flag==0)     //page fault
               {
                    if(k<size)
                    {
                        fr[k++]=str[i++];
                        count++;
                    }
                    
                    else
                    {//k=size
                        if(m<size)
                        {
                             fr[m++]=str[i++];
                             count++;
                        }
                        
                        else
                            m=0;
                    }
               }
               printf("\n");
               for(x=0;x<size;x++)
                    printf("%d\t",fr[x]);
     }
     printf("\n Page faults: %d",count);
}
                       
void optimal()
{
     int cnt[10],flag,num,i,f,j,count=0,x,y,c,m,max,current,k=0;
     
     
     for(i=0;i<n;i++)
     {
         flag=0;
         num=str[i];
         
         for(j=0;j<size;j++)
         {
             if(num==fr[j])
             {
                 flag=1;
                 break;
             }
         }
         
         if(flag==0)     //page fault
         {
              if(k<size)
              {
                   fr[k++]=str[i];
                   count++;
              }
                    
              else
              {//k=size
              for(f=0;f<size;f++)
                         cnt[f]=999; //imp
                   count++;
                   for(m=0;m<size;m++)
                   {
                         
                         current=fr[m];
                         for(c=i+1;c<n;c++)
                         {
                              if(current==str[c])
                              {     cnt[m]=c;break;}
                         }
                   }
                   
                   max=0;
                   
                   for(m=0;m<size;m++)
                   {
                         if(cnt[m]>max)
                         {
                              max=cnt[m];
                              x=m;
                         }
                   }
                   
                   fr[x]=num;
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
    
    while(1)
    {
            printf("\n 1. fifo 2. optimal 3. exit");
            scanf("%d",&ch);
            switch(ch)
            {
                     case 1: fifo();break;
                     case 2: optimal();break;
                     default: getch();return 0;
            }
    }
}
