#include<bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> color;

bool bipartiteCheck(vector<int> adjList[], int s)
{
    queue<int> q;
    q.push(s);
    color[s] = 0;

    while(!q.empty())
    {
        int f = q.front();
        q.pop();

        for(auto u: adjList[f])
        {
            if(color[u]==-1)
            {
                q.push(u);
                color[u] = 1-color[f];
            }
            else if(color[f] == color[u])
            {
                return false;
            }
        }
    }
    return true;
}

int main() {
   int v,e,s,d;
   cin>>v>>e;
   vector<int> adjList[v];
   color.resize(v,-1);
   for(int i=0;i<e;i++)
   {
       cin>>s>>d;
       adjList[s].push_back(d);
       adjList[d].push_back(s);
   }

   //print
   for(int i=0;i<v;i++)
   {
       cout<<i<<":";
       for(auto u:adjList[i])
       {
           cout<<u<<" ";
       }

       cout<<endl;
   }

   //
   bool isBip = bipartiteCheck(adjList,0);
   if(isBip==true) cout<<"Bipartite";
   else cout<<"Not bipartite";

    return 0;
}
