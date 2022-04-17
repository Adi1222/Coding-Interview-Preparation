#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Package
{

public:
	string pckName;
	int pckId;

	Package(int id, string name)
	{
		this->pckId = id;
		this->pckName = name;
	}

};

class Graph
{
private:
	int V;

	vector<Package*>* adj;

public:
	Graph(int v);

	void addEdge(int u, Package* v);

	void topo();

	void solve(int V, vector<int> &vis, stack<int> &st);

};

Graph::Graph(int v)
{
	this->V = v;
	adj = new vector<Package*>[v];
}

void Graph::addEdge(int u, Package* v)
{
	adj[u].push_back(v);
}

void Graph::solve(int node, vector<int> &vis, stack<int> &st)
{
	vis[node] = 1;

	for (auto itr : adj[node])
	{
		if (!vis[itr->pckId])
		{
			solve(itr->pckId, vis, st);
		}
	}

	st.push(node);
}

void Graph::topo()
{
	stack<int> st;

	vector<int> vis(V, 0);

	for (int i = 0; i < V; i++)
	{
		if (vis[i] == 0)
		{
			solve(i, vis, st);
		}
	}

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}

}




int main()
{
	Graph g(3);
	Package A(0, "A");
	Package* B = new Package(1, "B");
	Package* C = new Package(2, "C");
	g.addEdge(0, B);
	g.addEdge(1, C);
	g.topo();
	return 0;
}