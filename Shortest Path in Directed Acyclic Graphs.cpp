#include <algorithm>
#include <iostream>
#include <vector>
#include<unordered_map>
#include<bits/stdc++.h>
#include<list>
#include<stack>
#include<limits.h>

using namespace std;
class graph{
	public:
	unordered_map<int,list<pair<int,int>>>adj;
	void addEdge(int u, int v,int weight)
	{
		pair<int,int>p=make_pair(v,weight);
		adj[u].push_back(p);
	}
	
	void printAdj()	
	{
		for(auto i:adj)
		{
			cout<<i.first<<"->";
			for(auto j:i.second)
			{
				cout<<"("<<j.first<<","<<j.second<<"),";
			}
			cout<<endl;
		}
	}
	void dfs(int node,unordered_map<int,bool>&vis,stack<int>&s)
	{
		vis[node]=true;
		
		for(auto nbr:adj[node])
		{
			if(!vis[nbr.first])
			{
				//vis[nbr.first]=true;
				dfs(nbr.first,vis,s);
			}
		}
		s.push(node);
	}
	void getshortestpath(int src,vector<int>&dist,stack<int>&s)
	{
		dist[src]=0;
		while(!s.empty())
		{
			int temp=s.top();
			s.pop();
		
			if(dist[temp]!=INT_MAX)
			{
				for(auto i:adj[temp])
				{
					if(dist[temp]+i.second <dist[i.first])
					{
						dist[i.first]=dist[temp]+i.second;
					}
				}
			}
		}
	}
};
int main() {
	// Your code goes here;
	graph g;
	g.addEdge(0,1,5);
	g.addEdge(0,2,3);
	g.addEdge(1,2,2);
	g.addEdge(1,3,6);
	g.addEdge(2,3,7);
	g.addEdge(2,4,4);
	g.addEdge(2,5,2);
	g.addEdge(3,4,-1);
	g.addEdge(4,5,-2);
	
	g.printAdj();
	
	int n=6;
	unordered_map<int,bool>vis;
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			g.dfs(i,vis,s);
		}
	}
	
	int src=1;
	vector<int>dist(n);
	for(int i=0;i<n;i++)
	{
		dist[i]=INT_MAX;
	}
	//dist[src]=0;
	g.getshortestpath(src,dist,s);
	cout<<"answer is: "<<endl;
	
	for(int i=0;i<dist.size();i++)
	{
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	return 0;
}