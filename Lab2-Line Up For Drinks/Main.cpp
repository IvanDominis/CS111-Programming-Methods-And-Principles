#include <iostream>
#include <math.h>
using namespace std;
int check(int i,char toh[],int n)
{
    for(i;i<n;i++)
        if( toh[i]=='E')
            return 1;
    return 0;
}
int mini(int l[],int m)
{
    int n=l[0];
    for(int i=0;i<n;i++)
        if(n<l[i])
            n=l[i];
    return n;
}
int search(int l[],int m,int n)
{
    for(int i=0;i<m;i++)
        if(n==l[i])
            return i;
}
void solve(int n,int m,int k,char toh[],int l[],int o[],int rs[])
{
    int index,min,t=k,ib;
    for(int i=0;i<n;i++)
    {   if(toh[i]=='E')
        {   if(t==k)
            {   min = mini(l,m);
                index = search(l,m,min);
                rs[i] = index+1;
                l[index]=l[index]+1;
                t--;
                ib=index; }
            else
            {   rs[i]=ib+1;
                t--;
                l[i]=l[i]+1;
                if(t-1==0)
                    t=k;} }
        else
        {   
            if(check(i,toh,n)==1)
                {
                    min = mini(l,m);
                    index = search(l,m,min);
                    rs[i]= index+1;
                    l[index]=l[index]++;
                    t--;
                }
            else
                {
                    index=search(l,m,k-1);
                    rs[i]=index+1;
                    l[index]=l[index]+1;
                }
        }
        cout<<index<<endl;
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    char toh[n];
    int l[m],o[m],rs[n];
    for(int i=0;i<n;i++)
        cin>>toh[i];
    for(int i=0;i<m;i++)
        {
        cin>>l[i];
        o[i]=k;
        }
    solve(n,m,k,toh,l,o,rs);
     for(int i=0;i<n;i++)
        cout<<rs[i]<<" "<<l[i]<<endl;
}