#include <stdio.h>
//#include <conio.h>
#include <math.h>
int F(int m,int a,int b)
   {
   int A[6],B[6],i,t=1;
   for(int i=1;i<=m;i++)
     {
     A[i]=a%2;
     a=a/2;
     B[i]=b%2;
     b=b/2;
     }
   for(int i=1;i<m;i++)
     {
     if((A[i]==0&&B[i]==0&&A[i+1]==0&&B[i+1]==0)||(A[i]==1&&B[i]==1&&A[i+1]==1&&B[i+1]==1))
     t=0;
     }
   return t;
   }
main()
 {
 long T,n,m,KQ;
 scanf("%ld",&T);
 for(long i=0;i<T;i++)
   {
   KQ=0;
   long f[33][33],thay,t;
   scanf("%ld %ld",&n,&m);
   if(n<m)
     {
     thay=n;
     n=m;
     m=thay;
     }
   t=pow(2,m);
   for(long i=0;i<t;i++)
     f[1][i]=1;
   for(long i=2;i<=n;i++)
     for(long j=0;j<t;j++)
       {
       f[i][j]=0;
       for(long k=0;k<t;k++)
         if(F(m,j,k)==1)
         f[i][j]+=f[i-1][k];
       }
   for(long i=0;i<t;i++)
     KQ+=f[n][i];
   printf("%ld\n",KQ);
   }
 //getch();
 }

