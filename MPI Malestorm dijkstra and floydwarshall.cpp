#include<bits/stdc++.h>
using namespace std;
int inf=10000000;

int main()
{
    int n;cin>>n;
    vector<pair<int,int>>graph[n+5];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            string s;cin>>s;
            if(s!="x")
            {
                int c=stoi(s);
               graph[i].push_back({j,c});
              graph[j].push_back({i,c});
            }

        }
    }
    int dist[n+1];
    for(int i=1;i<=n;i++)dist[i]=inf;
    dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        int curnod=pq.top().second;
        int curdis=pq.top().first;
        pq.pop();
        if(dist[curnod]<curdis)continue;
        for(auto child:graph[curnod])
            {
                if(dist[child.first]>curdis+child.second)
                    {
                        dist[child.first]=curdis+child.second;
                        pq.push({dist[child.first],child.first});
                    }
            }

    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(ans!=inf)ans=max(ans,dist[i]);
    }
    cout<<ans<<endl;

}
