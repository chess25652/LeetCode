struct node
{
	int value;
	int path; // rightmost bit [+1] indicates 1 being used; 2nd rightmost bit [+2] indicates 2 being used; etc.
			  // if ends in ...000101, that means 1 and 3 have been used to get here
	int sum; // nodes >= 100 can be leaves
	int level; // odd = first player's turn; even = second player's turn
	int wins; // 1 = first player can force win; 2 = second player can force win; 0 = Not yet known
	node *firstChild, *nextSibling, *parent;
	node(node *par) : wins(0), parent(par), firstChild(nullptr), nextSibling(nullptr) {}
};

struct stackElem
{
	node *pnode;
	stackElem *next;
	stackElem(node *p, stackElem *n) : pnode(p), next(n) {}
};

class stack
{
	stackElem *head = nullptr;
public:
	void push(node *pnode)
	{
		stackElem *p = new stackElem(pnode, head);
		head = p;
	}
	node * pop()
	{
		node *ret = head->pnode;
		stackElem *p = head;
		head = head->next;
		delete p;
		return ret;
	}
	bool isEmpty() { return head == nullptr; }
};

class priorityQueue // priority by level; highest level removed
{
	stackElem *head = nullptr;
public:
	void add(node *ptr_node)
	{
		// insert into level-decreasing order
		stackElem *add = new stackElem(ptr_node, head);
		if (head == null)
			head = add;
		else if (add->pnode->level >= head->pnode->level)
		{
			add->next = head;
			head = add;
		}
		else
		{
			stackElem *q = head, *p = head->next;
			while (p != nullptr && add->pnode->level >= p->pnode->level)
			{
				q = p;
				p = p->next;
			}
			add->next = p;
			q->next = add;
		}
	}
	node * remove()
	{
		node *ret = head->pnode;
		stackElem *p = head;
		head = head->next;
		delete p;
		return ret;
	}
	bool isEmpty() { return head == nullptr; }
};

class Solution
{
	int testbits[20]; // testbits[i-1] equals a 1-bit shifted left i-1 times. It indicates value i has been used
public:
	bool canIWin(int max, int total)
	{
		if (max * (max + 1) / 2 < total)
			return false;

		for (int i = 1; i <= 20; ++i)
			testbits[i-1] = pow(2, i-1);

		node *root = new node(null);
		root->value = root->path = root->sum = root->level = 0;
		stack s;
		s.push(root);
		priorityQueue pq;

		// Create the game tree. Each node in the stack is there because we need to form its subtree
		while (!s.isEmpty())
		{
			node *p = s.pop();

			// For each possible child value, check to see if it's not already used in the path to here.
			// If not yet used, create a node for it and add it as a child of p.
			// If that child's sum doesn't exceed 100, add it to the stack for later building
			// If it does, we know the winner of p (the child's parent). Queue p for the next stage, then we're done with p
			for (int chVal = 1; chVal <= max; ++chVal)
			{
				if (chVal != p->value && testbits[chVal-1] & p->path == 0) // that child value hasn't been used yet
				{
					// Create child node
					node *child = new node(p);
					child->value = chVal;
					child->path = p->path + testbits[chVal-1];
					child->sum = p->sum + chVal;
					child->level = p->level + 1;

					// Add as child of p
					child->nextSibling = p->firstChild;
					p->firstChild = child;

					// Add to stack if sum < 100
					if (child->sum < 100)
						s.push(child);
					else // sum >= 100. Whoever's move it is wins, so we also know p's (its parent's) winner
					{
						p->wins = (child->level % 2 == 1) ? 1 : 2;
						pq.add(p);
						break; // we can stop forming the subtree rooted at p since we already know the winner
					}
				}
			}
		}
		// Resolve the winner of nodes that we don't know yet
		while (!pq.isEmpty())

	}

};