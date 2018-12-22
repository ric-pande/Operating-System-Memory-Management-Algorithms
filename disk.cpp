#include<iostream.h>
#include<conio.h>
using namespace std;

int main()
{
    int i,j=0,r,t=0,a[100],n,p,st,s,f[100],temp,dist;
    printf("Enter head pointer posn");
    scanf("%d",&a[0]);
    st=a[0];
    
    //printf("\nEnter previous head posn");
    //scanf("%d",&p);
    
    printf("enter max track limit");
    scanf("%d",&n);
    
    printf("Enter process in request order");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    
    //a[n+1]=n;
    //a[n+2]=0;
    
    for(i=n+1;i>=0;i--)
       for(j=0;j<=i;j++)
       {
           if(a[j]>a[j+1])
           {
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
           }
       }
       
    for(i=0;i<=n;i++)
    {
       if(st==a[i])  r=i;
    }
    
    dist=(n-r>r-0)?r:n-r;  //compare with valur
    if(dist==r)
    {
               for(i=r;i>0;i--)
               {
                    t+=a[i]-a[i-1];
               }
               t+=a[r+1]-a[0];
               for(i=r+1;i<n;i++)
               {
                    t += a[i+1]-a[i];
               }
    }
    else
    {
        for(i=r;i<n;i++)
          t += a[i+1]-a[i];
        t+=a[n+1]-a[r-1];
        
        for(i=r-1;i>0;i--)
          t += a[i]-a[i-1];
        
    }
    

                    
               
    
    
    /*if(s<p)
    {
       for(i=r;i>0;i--)
       {
           t+= a[i]-a[i-1];
           f[j++]=a[i];
       } 
       
       t += a[r+1]-a[0];
       f[j++]=a[0];
       
       for(i=r+1;i<n+1;i++)
       {
              t+= a[i+1]-a[i];
              f[j++]=a[i];
       }
    }
    else
    {
        for(i=r;i<n+2;i++)
        {
                t+= a[i+1]-a[i]; 
                f[j++]=a[i];
        }
        
        t += a[n+2]-a[r-1];
        
        f[j++]=a[n+2];
        
        for(i=r-1;i>1;i--)
        {
             t += a[i]-a[i-1];
             f[j++]=a[i];
        }
        
        f[j++]=a[i];
    }*/
        
    //for(i=0;i<=n;i++)
    //printf("\t%d",f[i]);
    printf("\nhead = %d ",t);
    getch();return 0;
}
