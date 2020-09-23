#include "UnionFind.h"

UnionFind::UnionFind(int size)
{
	// throw for invalid size
	if (size <= 0)
	{
		throw "Size of <= 0 is invalid!";
	} 

	this->size = this->numComponents = size;
	sz = new vector<int>(size);
	parentOf = new vector<int>(size);

	for (int i = 0; i < size; i++)
	{
		// Sets the initial size of each component to 1
		sz->at(i) = 1;

		// Sets the initial parent of each node to itself
		parentOf->at(i) = i;
	}
}

int UnionFind::Find(int p)
{
	// Finds the root of the component / set
	int root = p;

	// While the p is not the root (the parent of itself)
	// make the var "root" the parent of itself
	// -- To find the root component --
	while (root != parentOf->at(root))
	{
		root = parentOf->at(root);
	}


	// Compress the path leading back to the root.
	// Doing this operation is called "Path Compression"
	// and is what gives us amortized constant time complexity.
	while (p != root)
	{
		int next = parentOf->at(p);
		parentOf->at(p) = root;
		p = next;
	}

	return root;
}

bool UnionFind::GetIsConnected(int p, int q)
{
	return Find(p) == Find(q);
}

int UnionFind::GetComponentSize(int p)
{
	return sz->at(Find(p));
}

int UnionFind::GetSize()
{
	return size;
}

int UnionFind::NumOfComponents()
{
	return numComponents;
}

void UnionFind::Unify(int p, int q)
{
	int root1 = Find(p);
	int root2 = Find(q);

	// Return if these elements are already in the same group
	if (root1 == root2) { return; }

	// Merge two components / sets together.
	// Merge smaller components / sets into the larger one.
	if (sz->at(root1) < sz->at(root2))
	{
		sz->at(root2) += sz->at(root1);
		parentOf->at(root1) = root2;
	}
	else
	{
		sz->at(root1) += sz->at(root2);
		parentOf->at(root2) = root1;
	}

	// Since the roots found are different we know
	// that the number of components / sets has decreased by one
	numComponents--;
}

