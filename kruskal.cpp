#include<bits/stdc++.h>
#define fastread()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
vector<tuple<int,int,int> >edjlist,mst;
vector<int>parent;
bool sortByWeight(tuple<int,int,int> a, tuple<int,int,int> b)
{
    return (get<2>(a) < get<2>(b));
}
int findop(int sc)
{
    if(parent[sc]==-1)
        return sc;
    else
        return findop(parent[sc]);
}
void unionop(int u,int v)
{
    parent[u]=v;
}
void kruskal(int v,int e)
{
    int i=0,j=0;
    while(i<v-1 && j<e)
    {
        tuple<int,int,int> x = edjlist[j];
        int sc = get<0>(x);
        int des = get<1>(x);
        int wt = get<2>(x);
        int srsc= findop(sc);
        int srdes = findop(des);
        if (srsc == srdes)
        {
            j++;
            continue;
        }
        unionop(srsc,srdes);
        mst.push_back(x);
    }
}
int main()
{
    fastread();
    int v,e;
    cin>>v>>e;
    parent.resize(v,-1);
    for(int i=0; i<e; i++)
    {
        int sc,des,wt;
        cin>>sc>>des>>wt;
        edjlist.push_back(make_tuple(sc,des,wt));
    }
    sort(edjlist.begin(),edjlist.end(),sortByWeight);
    kruskal(v,e);
    for(auto u:mst)
    {
        cout<<get<0>(u)<<" "<<get<1>(u)<<" "<<get<2>(u)<<" "<<endl;
    }
}
