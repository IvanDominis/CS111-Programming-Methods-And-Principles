
#include <iostream>
#include <math.h>
using namespace std;
struct r
{
    int ind,app,t;
};
int find(r st[],int idl,int x)
{
    for(int i=0;i<=idl;i++)
        if(st[i].app==x && st[i].t==x)
            {
                st[i].t-=1;
                return st[i].ind;
            }
    return -1;
}
void xuat(int idl,r st[])
{
    for(int i=0;i<=idl;i++)
        cout<<st[i].ind<<" "<<st[i].app<<" "<<st[i].t<<endl;
}
int find1(r st[],int idl)
{
    for(int i=0;i<=idl;i++)
        if(st[i].app>st[i].t && st[i].t!=0)
        {
            st[i].t-=1;
            return st[i].ind;
        }
}
int check(int i,char toh[],int n)
{
    for(i;i<n;i++)
        if( toh[i]=='E')
            return 1;
    return 0;
}
int check1(int idl,r st[])
{
    for(int i=0;i<=idl;i++)
        if(st[i].app!=st[i].t || st[i].t!=0)
            return -1;
    return 0;
}
int check2(int idl,r st[],int n, char toh[],int x,int k)
{
    int d=0,d1=0,sum=0;
    for(int i=x;i<n;i++)
        if(toh[i]=='E')
            d++;
        else
            d1++;
    for(int i=0;i<=idl;i++)
        if(st[i].app!=1)
            sum+=st[i].t;
    if(d==d1 && check1(idl,st)==-1)
        return 1;
    return 0;
}
int check3(int idl,r st[])
{
    for(int i=0;i<=idl;i++)
        if(st[i].app==1)
            return 1;
    return 0;
}
void solve(int n,int m,int k,int idl,char toh[],int l[],r st[],int rs[])
{
    int s,d=n,ib;
    for(int i=0;i<n;i++)
    {
        if(toh[i]=='E')
        {
            if(check1(idl,st)==0 ||i==0)
                rs[i]=find(st,idl,k)+1;
            else
                rs[i]=find1(st,idl)+1;
        }
        else
        {
            if(check(i,toh,n)==0 || (check2(idl,st,n,toh,i,k)==1 && check3(idl,st)==1))
                rs[i]=find(st,idl,1)+1; 
            else
                rs[i]=find(st,idl,k)+1;
        }
        //xuat(idl,st);
    }
}
int main()
{
    int n,m,k,test,d=0,idl=0;
    cin>>n>>m>>k;
    char toh[n];
    int l[m],rs[n],o[n];
    r st[n];
    for(int i=0;i<n;i++)
        cin>>toh[i];
    for(int i=0;i<m;i++)
    {
        cin>>l[i];
        test=l[i];
        while(test!=k)
        {
            o[d]=i;
            d++;
            test++;
        }
    }
    st[0].ind=o[0];
    st[0].app=1;
    st[0].t=1;
    for(int i=1;i<n;i++)
    {
        if(o[i]==st[idl].ind)
            st[idl].app+=1;
        else
        {
            idl+=1;
            st[idl].ind=o[i];
            st[idl].app=1;

        }
        st[idl].t=st[idl].app;
    }
    solve(n,m,k,idl,toh,l,st,rs);
     for(int i=0;i<n;i++)
        cout<<rs[i]<<endl;
}