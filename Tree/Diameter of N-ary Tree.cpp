#include <iostream>
using namespace std;

// T.C O(N^2)

class Node
{
	public:
	
	int key;
	vector<Node*> children;
	
	Node(int x)
	{
		key = x;
	}
	
};

int ht(Node* node)
{
	if(node == nullptr)
	{
		return 0;
	}
	
	int temp = 0;
	
	for(Node* itr : node->children)
	{
		temp = max(temp, ht(itr));
	}
	
	// or
	/*
	for(vector<Node*>::iterator itr = node->children.begin(); itr != node->children->end(); itr++)
	{
		temp = max(temp, ht(*itr)); 
	}*/
	
	return temp + 1;
}


int diameter(Node* node)
{
	if(node == nullptr)
	{
		return 0;
	}
	
	// suppose the diameter passes through the current node
	// then find the top two maximum heights among the children of the current node
	
	int max1 = 0, max2 = 0;
	for(vector<Node*>::iterator itr = node->children.begin(); itr != node->children.end(); itr++)
	{
		int height = ht(*itr);
		
		if(height > max1)
		{
			max2 = max1;
			max1 = height;
		}
		else
		{
			if(height > max2)
			{
				max2 = height;
			}
		}
	}
	
	
	int max_child_diam = 0; // find the maximum diameter among the children of the current node
	
	for(vector<Node*>::iterator itr = node->children.begin(); itr != node->children.end(); itr++)
	{
		max_child_diam = max(max_child_diam, diameter(*itr));
	}
	
	
	return max(max_child_diam, max1 + max2);
}

/*********************************  O(N) Approach *********************************/

//hint -> calulating the height in the same function


int ans = 0;



int diameter(Node* node)
{
	if(node == nullptr)
	{
		return 0;
	}
	
	int max1 = 0;
	int max2 = 0;
	
	for(vector<Node*>::iterator itr = node->children.begin(); itr != node->children.end(); itr++)
	{
		int height = diameter(*itr);
		
		if(height > max1)
		{
			max2 = max1;
			max1 = height;
		}
		else
		{
			if(height > max2)
			{
				max2 = height;
			}
		}
	}
	
	ans = max(ans, max1 + max2); // for each node assuming that the diameter passes through that node
	
	return max(max1, max2) + 1; // this return the max height of a node
}



/************************************* dp Approach **************************************/


int findHeight(int src, int par)
{
	int mx = 0;
	ht[src] = 0;
	
	bool leaf = 1;
	
	for(int child : adj[src])
	{
		if(child != par)
		{
			leaf = 0;
			mx = max(mx, findHeight(child, src));
		}
		
	}
	
	return ht[src] = (leaf == 1) ? 0 : 1 + mx; // store that in ht array
}

// another way to calculate height
void findHeight_2(int src, int par)
{
	int mx = 0;
	
	int leaf = 1;
	
	for(int child : adj[src])
	{
		if(child != par)
		{
			leaf = 0;
			findHeight_2(child, src);
			mx = max(mx, ht[child]);
		}
	}
	
	if(leaf)
	{
		ht[src] = 0;
	}
	else
	{
		ht[src] = 1 + mx;
	}
}


void solve(int src, int par)
{
	int mx = 0;
	
	vector<int>childrenHeights;
	
	for(int child : adj[src])
	{
		if(child != par)
		{
			solve(child, src);
			childrenHeights.push_back(child);
			mx = max(mx, dp[child]);
		}
	}
	
	
	int sz = childrenHeights.size();
	
	sort(childrenHeights.begin(), childrenHeights.end(), greater<int>());
	
	if(childrenHeights.size() == 0)
	{
		dp[src] = 0;
	}
	else if(childrenHeights.size() == 1)
	{
		dp[src] = 1 + childrenHeights[0];
	}
	else
	{
		dp[src] = 2 + childrenHeights[0] + childrenHeights[1];
	}
	
	dp[src] = max(dp[src], mx);
}


int main() 
{
	return 0;
}