#include<bits/stdc++.h>
#define fastread()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define pb  push_back

using namespace std;
vector<int>visit;
stack<int>st;
void adjlist(vector<int>edjlist[],int s,int d)
{
    edjlist[s].pb(d);
    edjlist[d].pb(s);

}
void Dfs(vector<int>edjlist[],int s){
    st.push(s);
    visit[s]=1;
    while(!st.empty())
    {
        int t=st.top();
        cout<<t<<" ";
        st.pop();
        for(auto u:edjlist[t])
        {
            if(visit[u]!=1)
            {
                st.push(u);
                visit[u]=1;
            }
        }
    }
}
int main()
{
    fastread();
    vector<int>edjlist[5];
    adjlist(edjlist,0,1);
    adjlist(edjlist,1,2);
    adjlist(edjlist,3,4);
    int co=0;
    visit.resize(5,0);
    for(int i=0; i<=3 ; i++)
    {
        if(visit[i]!=1)
        {
            cout<<"cc "<<++co<<":";
            Dfs(edjlist,i);
            cout<<endl;
        }
    }

}
