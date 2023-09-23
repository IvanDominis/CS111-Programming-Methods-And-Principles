#include <iostream> 
#include <fstream> 
#include <algorithm>
#include <stdlib.h>
#include <cstring>
using namespace std;
struct salary
{
    int main,sub;
};
struct difference
{
    int diff,index,mp;
};
int checkmainpilot(difference sub[],int n,difference a,salary b[])
{
    int x,y;
    for(int i=0;i<n;i++)
    {
        if( ((a.diff>=sub[i].diff && a.index>sub[i].index) || a.index==sub[i].index-1) && sub[i].mp==-1)
        {

            if (a.index==sub[i].index-1)
            {
                x =b[a.index].main + b[sub[i].index].sub;
                y =b[sub[i].index].main + b[a.index].sub;
                if(x>=y)
                    continue;
                else
                    {
                        sub[i].mp=0;
                        return 0;}
            }
            sub[i].mp=0;
            return 0;
        }
    }
    return 1;
}
int subpilot(difference sub[],int n,difference a,salary b[])
{
    for(int i=0;i<n;i++)
    {
        if(a.diff<=sub[i].diff && a.index<sub[i].index && sub[i].mp==-1)
        {
            sub[i].mp=1;
            return 1;
        }
        else if(sub[i].mp==-1 && i==n-1)
        {
            int x =b[a.index].main + b[sub[i].index].sub;
            int y =b[sub[i].index].main + b[a.index].sub;
            if (x>=y)
                {
                    sub[i].mp=0;
                    return 0;
                }
            else
                {
                    sub[i].mp=1;
                    return 1;
                }
            break;
        }
}
}
void choose(difference sub[],salary a[],int n)
{
    for(int i=0;i<n;i++)
        if(sub[i].mp==-1)
        {
            if (checkmainpilot(sub,n,sub[i],a)==0)
                sub[i].mp=1;
            else
            {
                if(subpilot(sub,n,sub[i],a)==0)
                    sub[i].mp=1;
                else
                    sub[i].mp=0;
            }

        }
}

void sortA(difference sub[],int n)
{
    int tg,ind;
    for(int i=0;i<n-1;i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(sub[i].diff > sub[j].diff)
            {
                tg = sub[i].diff;
                ind = sub[i].index;
                sub[i].diff = sub[j].diff;
                sub[i].index= sub[j].index;
                sub[j].diff= tg;
                sub[j].index=ind;      
            }
            else if(sub[i].diff==sub[j].diff && sub[j].index<sub[i].index)
            {
                tg=sub[i].index;
                sub[i].index=sub[j].index;
                sub[j].index=tg;
            }
        }
    }
}
int main()
{
    ifstream pilot("AIRCREW.IN.txt");
    int n,trip,sum=0;
    pilot>>n;
    difference sub[n];
    salary a[n];
    for(int i=0;i<n;i++)
    {
        pilot>>a[i].main;
        pilot>>a[i].sub;
        sub[i].diff=a[i].main-a[i].sub;
        sub[i].index=i;
        sub[i].mp=-1;
    }
    sortA(sub,n);
    choose(sub,a,n);
    for(int i=0;i<n;i++)
        cout<<sub[i].diff<<" "<<sub[i].index<<" "<<sub[i].mp<<endl;
    for(int i=0;i<n;i++)
    {
        if(sub[i].mp==0)
            sum+=a[sub[i].index].sub;
        else
            sum+=a[sub[i].index].main;
    }
    ofstream output("AIRCREW.OUT.txt");
    output<<sum;
    cout<<sum;
}

