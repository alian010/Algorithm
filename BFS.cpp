#include<bits/stdc++.h>
#define fastread()      (ios_base:: sync_with_stdio(false),cin.tie(NULL));

using namespace std;
void edjlist(vector<int> adjlist[],int s,int d){
    adjlist[s].push_back(d);
    adjlist[d].push_back(s);
}
void bfs(vector<int>adjlist[],vector<bool>visit,int s){
    stack<int>q;
    q.push(s);
    visit[s]=true;
    while(!q.empty())
    {
        int f=q.top();
        cout<<f<<" ";
        q.pop();
        for(auto i:adjlist[f])
        {
            if(!visit[i])
            {
                q.push(i);
                visit[i]=true;
            }
        }
    }

}
int main()
{
    fastread()
    int v=7;
    vector<bool>visit(v,false);

    vector<int>adjlist[v];
    edjlist(adjlist,0,4);
    edjlist(adjlist,0,3);
    edjlist(adjlist,0,1);
    edjlist(adjlist,1,2);
    edjlist(adjlist,1,3);
    edjlist(adjlist,2,5);
    edjlist(adjlist,2,6);
    edjlist(adjlist,4,5);
    edjlist(adjlist,5,6);
    cout<<"Bfs"<<endl;
    bfs(adjlist,visit,0);

}
