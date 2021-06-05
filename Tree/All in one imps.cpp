#include <iostream>
using namespace std;


Node* array_to_BST(int *arr, int st, int end)
{
	if(end < st)
		return NULL;
	
	int mid = (st + end) >> 1; // right shift by one --> divide by 2
	
	Node* temp = new Node(arr[mid]);
	
	temp->left = array_to_BST(arr, st, mid - 1);
	
	temp->right = array_to_BST(arr,  mid + 1, end);
	
	return temp;
	
}
 
 
Node* create_tree_from_preorder_inorder(vector<int> preorder, vector<int> inorder, index, int start, int end, unordered_map<int,int>& mp)
{
	// base condition
	if(start > end)
		return NULL;
		
	Node* temp = new Node(preorder[index]);
	
	// search the value in inorder array
	int idx = mp[preorder[index]]; O(1) T.C
	
	index += 1;
	
	temp->left = create_tree_from_preorder_inorder(preorder, inorder, index, start, idx - 1, mp);
	temp->right = create_tree_from_preorder_inorder(preorder, inorder, index, idx + 1, end, mp);
	
	return temp;
	
}

bool are_identical_recursive(Node* rt1, Node* rt2)    ////  T.C  O(no. of nodes in smaller Tree)
{
	if(rt1 == NULL && rt2 == NULL)
		return true;
		
	if(rt1 == NULL || rt2 == NULL)
		return false;
	
	if(rt1->data != rt2->data)
		return false;
	
	
	return are_identical_recursive(rt1->left, rt2->left) && are_identical_recursive(rt1->right, rt2->right);
}


bool are_identical_iterative(Node* rt1, Node* rt2)  // T.C ----> O(m + n)  m --> no of nodes in Tree1 
{
	queue<Node*> q1, q2;
	
	q1.push(rt1);
	q2.push(rt2);
	
	while(!q1.empty() && !q2.empty())
	{
		Node* t1 = q1.front();
		Node* t2 = q2.front();
		
		q1.pop();
		q2.pop();
		
		if(t1->data != t2->data)
			return false;
			
		if(t1->left && t2->left)
		{
			q1.push(t1->left);
			q2.push(t2->left);
		}
		else if(t1->left || t2->left)
		{
			return false;
		}
		
		if(t1->right && t2->right)
		{
			q1.push(t1->right);
			q2.push(t2->right);			
		}
		else if(t1->right || t2->right)
		{
			return false;
		}
	}
	
	return true;
}

void inorder(Node* rt) // T.C --> O(N)
{
	stack<Node*>st;
	
	Node* cur = rt;
	
	while(cur != NULL || !st.empty())
	{
		while(cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}
		
		cur = st.top();
		st.pop();
		
		cout<<cur->data<<" ";
		
		cur = cur->right;
		
	}
}

void preorder(Node* rt) // T.C --> O(N) S.C --> O(N)
{
	stack<Node*>st;
	
	if(rt == NULL)
		return;
		
	st.push(rt);
	
	while(!st.empty())
	{
		Node* temp = st.top();
		
		st.pop();
		
		cout<<temp->data<<" ";
		
		if(temp->right)
			st.push(temp->right);
			
		if(temp->left)
			st.push(temp->left);
	}
}


// Another approach to preorder

void preorder(Node* rt) // T.C --> O(N)  S.C optimal as we are only storing the right nodes 
{
	if(rt == NULL)
		return NULL;
	
	while(cur != NULL || !st.empty() ) // Note : we are storing right nodes only in the stack
	{
		while(cur != NULL)
		{
			cout<<cur->data<<" ";
			
			if(cur->right)
				st.push(cur->right);
				
			cur = cur->left;
		}
		
		if(!st.empty()) // which means there were elements to the right of nodes 
		{
			cur = st.top();
			st.pop();
		}
		
	}
}



int main() 
{
	// your code goes here
	return 0;
}