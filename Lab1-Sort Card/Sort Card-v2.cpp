#include <iostream> 
#include <fstream> 
#include<algorithm>
using namespace std;
struct index{
    int c,r;
};
int changetopoint(string card)
{
    int check=0 , point = 0;
    if (card[0]>='1' and card[0]<='9')
        {check = atoi(card.c_str())-1;
        point = 4*(check-1);}
    else
    {
        if (card[0]== 'T')   point = 32;
        else if (card[0]== 'J') point = 36;
        else if (card[0]== 'Q') point = 40;
        else if (card[0]== 'K') point = 44;
        else point = 48;
    }
    if (card[1]  == 'N') point+=1;
    else if (card[1]== 'R') point+=2;
    else if (card[1]== 'B') point+=3;
    else point+=4;
    return point;
}
void Del(int a[], int &n, int pos){
    if(n <= 0){
        return;
    }
    if(pos < 0)
        pos = 0;
    else if(pos >= n)
        pos = n-1;
    for(int i = pos; i < n - 1; i++)
        a[i] = a[i+1];
    --n;
}
void motchieu(int eva[][100],int ev[100],int num)
{
    int nev=0;
    for(int i=0;i<num;i++)
    {
        for (int j=1;j<=eva[i][0];j++)
            {
                ev[nev]=eva[i][j];
                nev+=1;
            }
    }
}
index search(int x,int a[][100],int num)
{
    index t;
    for(int i=0;i<num;i++)
        for(int j=1;j<=a[i][0];j++)
            if(x==a[i][j])
            {
                t.c=i;
                t.r=j;
            }
    return t;
}
int searchNear(int x,int e[100],int &n)
{
    int near=-1,pos;
    for(int i=0;i<n;i++)
        if (e[i]>x)
        {   near=e[i]; pos=i;
            break;}
    for(int i=0;i<n;i++)
        if(e[i]>x && e[i]<near)
        {
            near=e[i];
            pos=i;
        }
    if(near!=-1)
        Del(e,n,pos);
    return near;
}
void Evapoint(int num,int adam[][100], int eva[][100],int s[])
{
    int m=0;
    for(int i=0;i<num;i++)
    {
        int k = adam[i][0],point=0;
        for (int j=1;j<=k;j++)
            if (eva[i][j]>adam[i][j])
                point+=1;
        s[m++]=point;
    }
}
int main()
{
    ifstream card("CARD.txt");
    string str;
    int n = 0, t[100];
    while(card>> str){ 
        if (str.size()==2)
           t[n]= changetopoint(str);
        else
            t[n]= atoi(str.c_str());
        n++;
        }
    int num=t[0],adam[num][100], eva[num][100],m=1,x,si=0;
    for(int i=0;i<num;i++)
        {
            int j=0;
            adam[i][j]=t[m];
            eva[i][j]=t[m];
            si+=t[m];
            x= i+1;
            m+=1;
            j+=1;
            while(x>0)
            {
                adam[i][j]=t[m];
                eva[i][j]=t[m+i+1];
                x-=1;
                m+=1;
                j+=1;
            }
            m+=i+1;
        }
    int ev[100],rs[num],d;
    motchieu(eva,ev,num);
    for(int i=0;i<num;i++)
    {
        for(int j=1;j<adam[i][0];j++)
        {
            d=searchNear(adam[i][j],ev,si);
            if (d==eva[i][j])
                continue;
            else
            {
                index t=search(d,eva,num);
                swap(eva[i][j],eva[t.c][t.r]);
            }
        }
    }
    Evapoint(num,adam,eva,rs);
    ofstream output("OUTPUT.txt");
    for (int i = 0; i < num; i++){
        output <<rs[i]<< endl;
        cout<<rs[i]<<endl;}
    return 0;
}