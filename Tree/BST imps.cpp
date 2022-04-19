#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**********************  BST Important's           ****************************/

// search and insertion in BST will take T.C O(h) h--> height of BST
//  The height of a skewed tree may become n and the time complexity of search and insert operation may become O(n). 

Node* findmin(Node* rt)
{}

Node* deleteNode(Node* rt, int key) // T.C O(h)
{
	if(rt == NULL)
		return NULL;
		
	if(rt->data > key)
	{
		rt->left = deleteNode(rt->left, key);
	}
	else if(rt->data < key)
	{
		rt->right = deleteNode(rt->right, key);
	}
	else
	{
		if(rt->left == NULL)
		{
			Node* temp = rt->right;
			delete(rt);
			return temp;
		}
		else if(rt->right == NULL)
		{
			Node* temp = rt->left;
			delete(rt);
			return temp;			
		}
		else
		{
			Node* temp = findmin(rt->right);
			rt->data = temp->data;
			rt->right = deleteNode(rt->right, temp->data);
		}
	}
	
	return rt;
}


Node* constructTreeFromPreorder(int pre[], int* index, int low, int high) // T.C O(N^2)
{
	
	if(low > high || *index >= pre.size())
	{
		return NULL;
	}
	
	Node* rt = new Node(pre[*index]);
	
	*index = *index + 1;
	
	if(low == high)// if only one element was remaining 
	{
		return rt;
	}
	
	// I need to find the first element whose value is greater than current index value
	
	int i = -1;
	
	for(i = index; i < pre.size(); i++)
	{
		if(pre[i] > rt->data)
		{
			break;
		}
	}
	
	if(i == -1) // greater val element does not exist
	{
		rt->left = constructTreeFromPreorder(pre, *index, index, high);
		rt->right = NULL;
		return rt;
	}
	
	rt->left = constructTreeFromPreorder(pre, *index, index, i - 1);
	rt->right = constructTreeFromPreorder(pre, *index, i, high);
	
	
	return rt;
}


Node* constructTreeFromPreorder(vector<int> pre) // T.C -->  O(N)
{
	stack<Node*>st;
	
	st.push(new Node(pre[0]));
	
	Node* root = new Node(pre[0]);
	
	for(int i = 1; i < pre.size(); i++)
	{
		int x = pre[i];
		Node* temp = NULL;
		
		while(!st.empty() && st.top() < pre[i])
		{
			temp = st.top();
			st.pop();
		}
		
		if(temp != NULL)
		{
			temp->right = new Node(pre[i]);
			st.push(new Node(pre[i]));
		}
		else
		{
			Node* t = st.top();
			t->left = new Node(pre[i]);
			st.push(t->left);
		}
	}
	
	return root;
}

int countNodes(Node* rt)
{
	if(rt == NULL)
	{
		return 0;
	}
	
	return 1 + countNodes(rt->left) + countNodes(rt->right);
}


void binaryTreeToBST(vector<int>& arr, Node* rt, int &index)
{
	if(rt == NULL)
	{
		return;
	}
	
	binaryTreeToBST(arr, rt->left, index);
	
	rt->data = arr[index];
	index += 1;
	
	binaryTreeToBST(arr, rt->right, index);
}

Node* convertBST_to_Balanced_BST(vector<int>& inorder, int low, int high)
{
	if(low > high)
	{
		return NULL;
	}
	
	int mid = (low + high) / 2;
	
	Node* rt = new Node(inorder[mid]);
	
	rt->left = convertBST_to_Balanced_BST(inorder, low, mid - 1);
	rt->right = convertBST_to_Balanced_BST(inorder, mid + 1, high);
	
	return rt;
}


Node* sortedArrayToBST(vector<int>& inrder, int low, int high)
{
	if(low > high)
	{
		return NULL;
	}
	
	int mid = (low + high) / 2;
	
	Node* rt = new Node(inorder[mid]);
	
	rt->left = sortedArrayToBST(inorder, low, mid - 1);
	rt->right = sortedArrayToBST(inorder, mid + 1, high);
	
	return rt;	
}

bool node_to_root_path(Node* cur, int key)
{
	if(cur == NULL)
		return false;
		
	if(cur->data == key)
	{
		ans.push_back(cur);
		return true;
	}
	
	bool l = node_to_root_path(cur->left, key);
	
	if(l == true)
	{
		ans.push_back(cur);
		return true;	
	}
	
	
	bool r = node_to_root_path(cur->right, key);
	if(r == true)
	{
		ans.push_back(cur);
		return true;
	}
	
	return false;
}

Node* getParent(Node* rt, int key) // Recursive
{
	if(rt == NULL)
	{
		return NULL;
	}
	
	if(rt->data == key)
		return NULL;
		
	if( (rt->left && rt->left->data == key) || (rt->right && rt->right->data == key) )
		return rt;
	
	
	if(rt->data > key)
	{
		Node* temp = NULL;
		temp = getParent(rt->left, key);
		
		if(temp != NULL)
		{
			return temp;
		}
	}
	else
	{
		Node* temp = NULL;
		temp = getParent(rt->right, key);
		
		if(temp != NULL)
		{
			return temp;
		}
	}
	
	return NULL;
}

Node* get_parent_node(Node* rt, int key) // T.C O(logN)
{
	if(rt == NULL)
		return NULL;
		
	Node* par = NULL;
	
	while(rt != NULL)
	{
		if(rt->data > key)
		{
			par = rt;
			rt = rt->left;
		}
		else if(rt->data < key)
		{
			par = rt;
			rt = rt->right;
		}
		else
		{
			break;
		}	
	}
	
	return par;
}


Node* get_sibling_node(Node* rt, int key) //  T.C O(logN)
{
	if(rt == NULL)
		return NULL;

	Node* par = NULL;
	
	while(rt != NULL)
	{
		if(rt->data > key)
		{
			par = rt;
			rt = rt->left;
		}
		else if(rt->data < key)
		{
			par = rt;
			rt = rt->right;
		}
		else
		{
			break;
		}	
	}
	
	if(rt == NULL)
		return NULL;
	
	if(par == NULL)
	{
		return NULL;
	}
	
	if(par->left == key)
	{
		return par->right;
	}
	
	return par->left;
} 

Node* get_inorder_parent(Node* rt)
{
	if(rt == NULL)
		return NULL;
	
	
	Node* inorderPar = NULL;
	
	while(rt != NULL)
	{
		if(rt->data > key)
		{
			inorderPar = rt;
			rt = rt->left;
		}
		else if(rt->data < key)
		{
			rt = rt->right;
		}
		else
		{
			break;
		}
	}
	
	return rt == NULL ? NULL : inorderPar;
}

int get_diff_even_odd_level(Node* rt)
{
	if(rt == NULL)
		return 0;
	 
	return rt->data - get_diff_even_odd_level(rt->left) - get_diff_even_odd_level(rt->right);
}



Node* inorderPredecessor(Node* rt, Node* pre, int key)
{
	if(rt == NULL)
	{
		return rt;
	}

	if(rt->data == key)
	{
		if(rt->left != NULL)
		{
			return findMax(rt->left);
		}
	}
	else if(rt->data > key) // go to left
	{
		return inorderPredecessor(rt->left, pre, key);

	}
	else
	{
		pre = rt;
		return inorderPredecessor(rt->right, pre, key);
	}

	return pre;
}

Node* inorderSuccessor(Node* rt, Node* succ, int key)
{
	if(rt==NULL)
	{
		return rt;
	}

	if(rt->data == key)
	{
		if(rt->right)
		{
			return findMin(rt->right);
		}
	}
	else if(rt->data > key)
	{
		succ = rt;
		return inorderSuccessor(rt->left, succ, key);
	}
	else{
		return inorderSuccessor(rt->right, succ, key);
	}

	return succ;
}

int main() 
{
	return 0;
}