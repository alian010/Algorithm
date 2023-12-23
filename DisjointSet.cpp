#include<bits/stdc++.h>
#define fastread()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
vector<int>parent;
vector<pair<int,int> >edjlist;
int findOperation(int u)
{
    if(parent[u]!=-1)
    {
        return findOperation(parent[u]);
    }
    return u;
}
void unionOperation(int u,int v)
{
    parent[u]=v;
}
bool findCycleUnderected(vector<pair<int,int> >edjlist)
{
    int fromE,toE;
    bool isCycle=false;
    for(auto i:edjlist)
    {
        fromE=i.first;
        toE = i.second;
        int x= findOperation(fromE);
        int y=findOperation(toE);

    if (x==y)
    {
        isCycle =true;
        break;
    }
    else
    {
        unionOperation(x,y);
    }
}return isCycle;
}
int main()
{
    fastread();
    int v,e,s,d;
    cin>>v>>e;

    for(int i=0; i<e; i++)
    {
        cout<<"s and d"<<endl;
        cin>>s>>d;
        edjlist.push_back(make_pair(s,d));
    }
    parent.resize(v,-1);
    bool isCycle = findCycleUnderected(edjlist);
    if (isCycle)
        cout<<"eds"<<endl;
    else
        cout<<"not"<<endl;
    }

