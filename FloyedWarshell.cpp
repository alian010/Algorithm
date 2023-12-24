#include<bits/stdc++.h>
#define fastread()  (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define v 4
#define INF 10000
int dist[v][v];

using namespace std;

int main()
{
    fastread();
    int G[v][v]={{0,3,INF,5},
                 {2,0,INF,8},
                 {INF,1,0,INF},
                 {INF,INF,2,0}};

        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                dist[i][j]=G[i][j];
            }
        }
        for(int k=0;k<v;k++)
        {
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                    if(dist[i][k]==INF || dist[k][j]==INF)
                        continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        for(int i=0;i<v;i++ )
        {
            if(dist[i][i])
                cout<<"ng"<<endl;
            exit(0);
        }

    for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
               cout<< dist[i][j]<<" ";
            }
            cout<<endl;
        }
}

