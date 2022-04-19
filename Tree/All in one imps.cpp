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

	while (!q.empty())
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

int diameter(Node *cur) // MAX distance between any two leaf nodes 0(N^2) Approach
{
	if (cur == NULL)
		return 0;

	int lht = heigth(cur->left);
	int rht = height(cur->right);

	int ldiameter = diameter(cur->left);
	int rdiameter = diameter(cur->right);

	return max(lht + rht + 1, max(ldiameter, rdiameter));
}

int diameter_of_tree(Node *cur, int &dia) // O(N) T.C
{
	// base case
	if (cur == NULL)
	{
		return 0;
	}

	if (cur->left == NULL && cur->right == NULL)
	{
		return 1;
	}

	int lh = diamter_of_tree(cur->left);
	int rht = diameter_of_tree(cur->right);

	// updating our answer which is passed by reference

	diam = max(diam, lh + rht + 1);

	return max(lh + rht) + 1; // this is just hiving us height of each node
}

void get_deepest_left_leaf_node(Node *cur, int level, bool left, int &deep)
{
	// base condition
	if (cur == NULL)
		return;

	if (cur->left == NULL && cur->right == NULL && left)
	{
		if (level > deep)
		{
			deep = level;
			ans = cur;
		}
	}

	get_deepest_left_leaf_node(cur->left, level + 1, true);
	get_deepest_left_leaf_node(cur->right, level + 1, false);
}

Node *LCA(Node *cur, int n1, int n2) // T.C O(N)
{
	// base condition
	if (cur == NULL)
	{
		return NULL;
	}

	if (cur->data == n1 || cur->data == n2)
		return cur;

	Node *l = LCA(cur->left, n1, n2);
	Node *r = LCA(cur->right, n1, n2);

	if (l && r)
		return cur;

	return (l != NULL) ? l : r;
}

bool hasPath(Node *cur, vector<int> &arr, int index) //Check if there is a root to leaf path with given sequence
{
	if (cur == NULL)
		return false;

	if (cur->data != arr[index])
		return false;

	if (cur->left == NULL && cur->right == NULL)
	{
		if (cur->data == arr[index] && index == arr.size() - 1)
			return true;

		return false;
	}

	return (cur->data == arr[index] && (hasPath(cur->left, arr, index + 1) || hasPath(cur->right, arr, index + 1)));
}

int longest_univalue_path(Node *cur, int &ans) /*** HARD O(N) ***/
{
	// base case
	if (cur == NULL)
		return 0;

	int lht = longest_univalue_path(cur->left, ans);
	int rht = longest_univalue_path(cur->right, ans);

	int l = 0, r = 0;

	if (cur->left && cur->data == cur->left->data)
	{
		l += lht + 1;
	}

	if (cur->right && cur->data == cur->right->data)
	{
		r += rht + 1;
	}

	ans = max(ans, l + r);

	return max(l, r);
}

bool does_pair_exist(Node *cur, unordered_set<int> &st) // T.C O(N) S.C O(N)
{
	if (cur == NULL)
		return false;

	if (st.count(sum - cur->data) != 0)
		return true;

	st.insert(cur->data);

	if (does_pair_exist(cur->left, st))
		return true;

	return does_pair_exist(cur->right, st);
}

vector<int> longest_root_to_leaf(Node *cur) // T.C O(N) S.C O(N)
{
	if (cur == NULL)
		return {};

	vector<int> l = longest_root_to_leaf(cur->left);
	vector<int> r = longest_root_to_leaf(cur->right);

	if (l.size() > r.size())
		l.push_back(cur->data);

	else
		r.push_back(cur->data);

	return (l.size() > r.size()) ? l : r;
}

void print_root_to_every_leaf_path(Node *cur, vector<int> &arr) // T.C O(N) S.C(N)
{
	if (cur == NULL)
		return;

	arr.push_back(cur->data);

	if (cur->left == NULL && cur->right == NULL)
	{
		res.push_back(ans);
	}

	print_root_to_every_leaf_path(cur->left, arr);
	print_root_to_every_leaf_path(cur->right, arr);

	arr.pop_back();
}




// maximum path sum between any two nodes
int solve(Node* node)  // T.C o(n)
{
	if(root)
		return 0;
		
	int l = solve(root->right);
	int r = solve(root->left);
	
	
	int temp = max(max(l, r) + node->data, node->data);
	
	
	int temp2 = max(temp, l + r + node->data);
	
	ans = max(ans, temp2);

	return temp;
}


// diagonal sum using a queue

void solve()
{
	queue<Node*>q;
	
	int sum = 0;
	int cnt = 0;
	int temp = 0;
	
	while(cur != NULL || !q.empty())
	{
		if(cur != NULL)
		{	
			if(cur->left)
			{
				q.push(cur->left);
				cnt += 1;
			}
		}
		
		sum += cur->data;
		cur = cur->right;
		
		if(cur == NULL)
		{
			if(!q.empty())
			{
				cur = q.top();
			}
			if(temp == 0)
			{
				ans.push_back(sum);
				sum = 0;
				temp = cnt;
			}
			
			temp -= 1;
			
		}
		
	}
}

// follow up question for diameter of tree ---> print the longest leaf to leaf path
/*
	First you'll follow the same approach as of diameter of tree
	store the node addres from which the diamter passes (this is done in the diamter calculating function)
	Once we know the node's address, it becomes easy to print the max left path and max right path from that node 
*/

int diamter(..,Node** temp_node , int& lh , int& rh ,..)
{
	if() // base 
		return 0;
		
	int l = ;
	int r = ;
	
	if(ans < l + r + 1)
	{
		ans = l + r + 1;
		
		temp_node* = node;
		
		lh = l; // we also store height
		rh - r;
	}
	
	return 1 + max(l, r); // this just gives us height
}

// once you have calculated the node's address , print the left and right path (to leaf)

void printPath()
{
	if()
		return;
		
	path[idx++] = node->data;
	
	if(node->left == NULL && node->right == NULL)
	{
		if(idx == lh)
		{
			printfunc(path, idx);
		}
	}

	printPath(go_to_left);
	printPath(go_to_right);
}


/********   Print all k-sum paths in a binary tree   ********/
void solve() // T.C O(n*h)
{
	if()
		return ;
		
	ans.push_back(node->data);
	
	solve(left);
	
	solve(right);
	
	// checking whether ther's any path ending at this node
	// we need to check this before we pos the eleent from the ans vector i.e 
	// before we backtrack, otherwise ww'll lose the element
	
	int sum = 0;
	
	for(int i = ans.size(); i >- 0; i--) // at a time at mas o(h) h elements can be there in ans vector
	{
		sum += ans[i];
		if(sum == target)
			print path
	}
	
	ans.pop_back();
}


bool areIdentical()
{
	if(a == null && b == null)
		return true;
		
	if(a == null || b == null)
		return false;
		
	return ( a->data == b->data && areIdentical(a, b->left)  && areIdentical(a, b->right));
}

bool isSubtree(a, b)
{
	if(b == null)
		return treu;
		
	if(a == null)
		return false;
		
	if(areIdentical(a, b))
		return true;
		
	if(isSubstree(a->left, b) || isSubtree(a->right, b))
		return true;
}


int solve()
{
	if(node == NULL)
		return 0;
		
	int l = solve();
	int r = solve();
	
	
	int L = 0, R = 0;
	
	if(node->left && node->left->data == node->data)
	{
		L += l + 1;
	}
	
	
	if(node->right && node->right->data == node->data)
	{
		R += r + 1;
	}
	
	return max(L, R);
}


/*************    Maximum Consecutive Increasing Path Length in Binary Tree                 ******************/

int solve()
{
	if(node == NULL)
		return 0;
		
	
	int l = solve(node->left);
	int r = solve(node->right);
	
	
	int L = 0, R = 0;
	
	if(node->left && (node->left->val == (node->val + 1)))
	{
		L += l + 1;
	}
	
	
	if(node->right && (node->right->val == (node->val + 1)))
	{
		R += r + 1;
	}
	
	
	return max(L, R);
}

vector<int> min_root_to_leaf(Node* node)
{
	if(node == NULL)
		return {};
		
	vector<int> l = min_root_to_leaf(node->left);
	vector<int> r = min_root_to_leaf(node->right);
	
	
	if(l.size() < r.size())
	{
		l.push_back(node->data);
	}
	else
	{
		r.push_back(node->data);
	}
	
	return (l.size() < r.size()) ? l : r;
}

/***********************       Closest leaf to a given node in Binary Tree          **************************/


// T.C O(n*h)

int solve(Node* node, int target, int arr[], int level)
{
	if(node == NULL)
		return INT_MAX;
	
	
	if(node->data == target)
	{
		int temp = find_min_dist_to_leaf(node);
		
		for(int i = level - 1; i >= 0 ; i--)
		{
			temp = min(temp, level - i + find_min_dist_to_leaf(arr[i]));
		}
		
		return temp;
	}
	
	arr[level] = node;
	
	int x = solve(node->left, target, arr, level + 1);
	
	if(x != INT_MAX)
	{
		return x;
	}
	
	return solve(node->right, target, arr, level + 1);
}


int find_min_dist_to_leaf(Node* node)
{
	if(node == NULL)
		return INT_MAX;
		
	if(node->left == NULL && node->right == NULL)
	{
		return 0;
	}
	
	return 1 + min(find_min_dist_to_leaf(node->left), find_min_dist_to_leaf(node->right));
}



/*************************      Print path from root to a given node in a binary tree              *************************************/


void path(Node* node, vector<int> arr, int target)
{
	if(node == NULL)
	{
		return false;
	}
	
	arr.push_back(node->data);
	
	
	if(node->data == target)
		return true;
		
	
	if(solve(node->left, arr, target) || solve(node->right, arr, target))
		return true;
	
	
	arr.pop_back();  // important step
	
	return false;
	
}

/**** Check if there is a root to leaf path with given sequence **/

bool path(Node* node, int idx, vectorint>& seq)
{
	if(node == NULL) // base 
		return false;
	
	if(node->data != seq[idx]) 
		return false;
		
	
	if(node->left == NULL && node->right == NULL) // terminating conditon is important
	{
		if(idx == seq.size() - 1)
			return true;
		
		return false;
	}
	
	return (seq[idx] == node->data && ( path(node->left, idx + 1, seq ) || path(node->right, idx + 1, seq) ) );
	
}



/*********************    Print all nodes at distance k from a given node       **********************/


void printNodes(Node* node, int k)
{
	if(node == NULL || k < 0)
		return;
		
	if(k == 0)
	{
		cout<<node->data;
		return;
	}
	
	
	printNodes(node->left, k - 1);
	printNodes(node->right, k - 1);
	
}


int solve(Node* node, int target, int k)
{
	if(node == NULL)
		return -1;
		
	if(node->data == target)
	{
		printNodes(node, k);  printing nodes at k dist in the substree of the current node
		return 0;
	}
	
	
	int L = solve(node->left, target, k);
	
	if(L != -1)
	{
		if(L + 1 == k)
		{
			cout<<node->data<<endl;
		}
		else
		{
			printNodes(node->right, k - L - 1);
		}
		
		return 1 + L;
	}
	
	int R = solve(node->right, target, k);
	
	if(R != -1)
	{
		// do the same for right child also
		if(R + 1 == k)
		{
			cout<<node->data<<endl;
		}
		else
		{
			printNodes(node->left, k - R - 1);
		}
		
		return 1 + R;
		
	}
	
	// Not found in L as well as R
	// so return -1
	
	return -1;
	
}


void updateRandomPtrs(Node* rt, unordered_map<Node*, Node*> &mp)
{

	if(mp[rt] == NULL)
	{
		return NULL;
	}

	mp[rt]->random = mp[rt->random];

	updateRandomPtrs(rt->left, mp);
	updateRandomPtrs(rt->right, mp);

}


Node* cloneBT(Node* rt, unordered_map<Node*, Node*> &mp)
{
	if(rt == NULL)
	{
		return NULL;
	}

	mp[rt] = new Node(rt->data);

	mp[rt]->left = cloneBT(rt->left, mp);
	mp[rt]->right = cloneBT(rt->right, mp);
	
	return mp[rt];
}


int main()
{
	// your code goes here
	return 0;
}