//MY FIRST DFS
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

vector<bool> visited; 
vector<vector<int> > graph; 

int maxi=0;
int cc=0;
void dfs(int v,int c)
{	
    
    visited[v] = true;

    for(auto it = graph[v].begin(); it != graph[v].end(); it++)
    {
		if(!visited[*it])
		{
            dfs(*it,c+1);
		}
    }
    if(c>cc)
		cc=c;
}


int main()
{
    
        int n,m,j=0;
        cin >>  m;
        n = 200;
        graph = vector<vector<int> > (n+2); //Note this n+2
        map < string , int > ma;
        for(int i = 0; i < m; i++)
        {
            string u,v,w;
            cin >> u >> w >> v;
            transform(u.begin(), u.end(), u.begin(), ::tolower);
            transform(v.begin(), v.end(), v.begin(), ::tolower);
			if(ma[v]==0)
			{
				j++;
				ma[v]=j;
			}
			if(ma[u]==0)
			{
				j++;
				ma[u]=j;
			}
			//cout<<ma[v]<<" "<<ma[u]<<endl;
            graph[ma[v]].push_back(ma[u]);
          
        }
       
        visited = vector<bool> (j+1, 0); 
        for(int u = 1; u <= j; u++)
        {
           // cout<<"u  "<<u<<" "<<visited[u]<<endl;
            if(visited[u]==true)
             {
				// cout<<"continues"<<endl;
				    continue;
			 }

            dfs(u,0);
             
			
        }
        cout<<(cc+1);

    
    return 0;
}
