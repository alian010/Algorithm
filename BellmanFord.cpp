#include<bits/stdc++.h>
#define fastread()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;
vector<int>dist;
int main()
{
    fastread();
    int v,e,s,d,wt;
    cin>>v>>e;
    vector<tuple<int,int,int> >edjlist;
    for(int i=0;i<e;i++)
    {
        cin>>s>>d>>wt;
        edjlist.push_back(make_tuple(s,d,wt));

    }
    for(auto i:edjlist)
    {
        cout<<get<0>(i)<<" "<<get<1>(i)<<" "<<get<2>(i)<<endl;
    }
    dist.resize(v,10000);
    dist[0]=0;
    for(int i=0 ;i<v;i++)
    {
        for(auto u:edjlist)
        {
            int sc=get<0>(u);
            int des= get<1>(u);
            int wt =  get<2>(u);
            int new_sum = dist[sc]+wt;
            if(new_sum<dist[des])
                dist[des]=new_sum;
        }
    }

    for(auto z:edjlist)
    {
        int sc=get<0>(z);
        int des= get<1>(z);
        int wt =get<2>(z);
        int new_sum =dist[sc]+wt;
        if (new_sum<dist[des])
        {
            cout<<"negative weight exist";
            exit(0);
        }
    }
    cout<<"final distance from source"<<endl;
    for(auto i:dist)
    {
        cout<<i<<" ";
    }
}

