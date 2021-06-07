#include <iostream>
using namespace std;

Node *array_to_BST(int *arr, int st, int end)
{
	if (end < st)
		return NULL;

	int mid = (st + end) >> 1; // right shift by one --> divide by 2

	Node *temp = new Node(arr[mid]);

	temp->left = array_to_BST(arr, st, mid - 1);

	temp->right = array_to_BST(arr, mid + 1, end);

	return temp;
}

Node *create_tree_from_preorder_inorder(vector<int> preorder, vector<int> inorder, index, int start, int end, unordered_map<int, int> &mp)
{
	// base condition
	if (start > end)
		return NULL;

	Node *temp = new Node(preorder[index]);

	// search the value in inorder array
	int idx = mp[preorder[index]];
	O(1)
	T.C

		index += 1;

	temp->left = create_tree_from_preorder_inorder(preorder, inorder, index, start, idx - 1, mp);
	temp->right = create_tree_from_preorder_inorder(preorder, inorder, index, idx + 1, end, mp);

	return temp;
}

bool are_identical_recursive(Node *rt1, Node *rt2) ////  T.C  O(no. of nodes in smaller Tree)
{
	if (rt1 == NULL && rt2 == NULL)
		return true;

	if (rt1 == NULL || rt2 == NULL)
		return false;

	if (rt1->data != rt2->data)
		return false;

	return are_identical_recursive(rt1->left, rt2->left) && are_identical_recursive(rt1->right, rt2->right);
}

bool are_identical_iterative(Node *rt1, Node *rt2) // T.C ----> O(m + n)  m --> no of nodes in Tree1
{
	queue<Node *> q1, q2;

	q1.push(rt1);
	q2.push(rt2);

	while (!q1.empty() && !q2.empty())
	{
		Node *t1 = q1.front();
		Node *t2 = q2.front();

		q1.pop();
		q2.pop();

		if (t1->data != t2->data)
			return false;

		if (t1->left && t2->left)
		{
			q1.push(t1->left);
			q2.push(t2->left);
		}
		else if (t1->left || t2->left)
		{
			return false;
		}

		if (t1->right && t2->right)
		{
			q1.push(t1->right);
			q2.push(t2->right);
		}
		else if (t1->right || t2->right)
		{
			return false;
		}
	}

	return true;
}

void inorder(Node *rt) // T.C --> O(N)
{
	stack<Node *> st;

	Node *cur = rt;

	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}

		cur = st.top();
		st.pop();

		cout << cur->data << " ";

		cur = cur->right;
	}
}

void preorder(Node *rt) // T.C --> O(N) S.C --> O(N)
{
	stack<Node *> st;

	if (rt == NULL)
		return;

	st.push(rt);

	while (!st.empty())
	{
		Node *temp = st.top();

		st.pop();

		cout << temp->data << " ";

		if (temp->right)
			st.push(temp->right);

		if (temp->left)
			st.push(temp->left);
	}
}

// Another approach to preorder

void preorder(Node *rt) // T.C --> O(N)  S.C optimal as we are only storing the right nodes
{
	if (rt == NULL)
		return NULL;

	while (cur != NULL || !st.empty()) // Note : we are storing right nodes only in the stack
	{
		while (cur != NULL)
		{
			cout << cur->data << " ";

			if (cur->right)
				st.push(cur->right);

			cur = cur->left;
		}

		if (!st.empty()) // which means there were elements to the right of nodes
		{
			cur = st.top();
			st.pop();
		}
	}
}

int sum_of_nodes(Node *rt)
{
	if (rt == NULL)
		return 0;

	return rt->data + sum_of_nodes(rt->left) + sum_of_nodes(rt->right);
}

int count_leaf(Node *rt)
{
	if (rt == NULL)
		return 0;

	if (rt->left == NULL && rt->right)
		return 1;

	return count_leaf(rt->left) + count_leaf(rt->right);
}

void printAtGivenLevel(Node *rt, int level)
{
	if (rt == NULL)
		return;

	if (level == 1)
	{
		cout << rt->data << " ";
	}

	printAtGivenLevel(rt->left, level - 1);
	printAtGivenLevel(rt->right, level - 1);
}

void reverse_level_order_traversal(Node *rt) // ********  Using Recursion  ***********
{
	if (rt == NULL)
		return;

	int ht = calculate_height(rt);

	for (int i = ht; i >= 1; i--)
	{
		printAtGivenLevel(rt, i);
		cout << endl;
	}
}

void reverse_level_order(Node *rt) // ***************  Without Recursion using 1 queue and 1 stack   ****************
{
	if (rt == NULL)
		return;

	queue<Node *> q;

	q.push(rt);

	stack<Node *> st;

	while (!st.empty())
	{
		Bode *temp = q.front();

		q.pop();

		if (temp->right != NULL)
		{
			q.push(temp->right);
		}

		if (temp->left != NULL)
		{
			q.push(temp->left);
		}

		st.push(temp);
	}

	while (!st.empty())
	{
		Node *x = st.top();
		cout << x->data << " ";

		st.pop();
	}
}

void postorder(Node *rt)
{
	if (rt == NULL)
	{
		return;
	}

	stack<Node *> st1;
	stack<Node *> st2;

	st1.push(rt);

	while (!st1.empty())
	{
		Node *temp = st1.top();
		st1.pop();

		st2.push(temp);

		if (temp->left != NULL)
		{
			st1.push(temp->left);
		}

		if (temp->right != NULL)
		{
			st1.push(temp->right);
		}
	}

	while (!st2.empty())
	{
		Node *temp = st2.top();
		cout << temp->data << " ";
		st2.pop();
	}
}

void create_mirror_Tree(Node *rt) // Recursive
{
	if (rt == NULL)
	{
		return;
	}

	Node *temp = rt->right;
	rt->right = rt->left;
	rt->left = temp;

	create_mirror_Tree(rt->left);
	create_mirror_Tree(rt->right);
}

void create_Mirror_Tree(Node *rt) // Iterative
{
	if (rt == NULL)
		return NULL;

	queue<Node *> q;
	q.push(rt);

	while (!q.empty())
	{
		Node *x = q.front();
		q.pop();

		Node *temp = x->right;
		x->right = x->left;
		x->left = temp;

		if (x->left)
			q.push(x->left);

		if (x->right)
			q.push(x->right);
	}
}

Node *delete_tree(Node *rt)
{
	// base case
	if (rt == NULL)
		return NULL;

	rt->left = delete_tree();
	rt->right = delete_tree();

	cout << "Deleting Node: " << rt->data << " ";

	delete (rt);

	return NULL;
}

int get_level(Node *rt, int x, int level)
{
	if (rt == NULL)
		return -1;

	int l = 0;

	if (rt->data == x)
		return level;

	l = get_level(rt->left, x, level + 1);

	if (l != 0)
	{
		return l;
	}

	l = get_level(rt->right, x, level + 1);

	return l;
}

void printLeftBoundary(Node *rt) // Iterative DO NOT PRINT THER LEAF
{
	if (rt == NULL)
		return;

	Node *cur = rt;

	while (cur->left != NULL || cur->right != NULL)
	{
		if (cur->left)
		{
			cout << cur->data << " ";
			cur = cur->left;
		}
		else
		{
			if (cur->right)
			{
				cout << cur->data << " ";
				cur = cur->right;
			}
		}
	}
}

void print_left_boundary_recursive(Node *rt) // DO NOT PRINT THE LEAF NODE
{
	if (rt == NULL)
		return;

	if (rt->left)
	{
		cout << rt->data << " ";
		print_left_boundary_recursive(rt->left);
	}
	else if (rt->right)
	{
		cout << rt->data << " ";
		print_left_boundary_recursive(rt->right);
	}
}

void print_leaves(Node *rt)
{
	if (rt == NULL)
		return;

	print_leaves(rt->left);

	if (rt != NULL && rt != NULL)
		cout << rt->data << " ";

	print_leaves(rt->right);
}

void print_right_boundary(Node *rt) // Printing in bottom up manner in recursive
{
	if (rt == NULL)
		return;

	if (rt->right)
	{
		print_right_boundary(rt->right);
		cout << rt->data << " ";
	}
	else if (rt->left)
	{
		print_right_boundary(rt->left);
		cout << rt->data << " ";
	}
}

void vertical_sum(Node *rt, int hd, ma<int, int> &mp)
{
	if (rt == NULL)
		return;

	vertical_sum(rt->left, hd - 1, mp);

	mp[hd] += rt->data;

	vertical_sum(rt->right, hd + 1, mp);
}

int main()
{
	// your code goes here
	return 0;
}