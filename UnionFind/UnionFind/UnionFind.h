#pragma once
#include <vector>

using namespace std;

/// <summary>
/// The user should make an hash table of <T, int>, where T 
/// is the type of the elements need to be stored using the
/// UnionFind Data Structure, and int being the ID of that element - which
/// will be stored in the UnionFind.
/// </summary>
class UnionFind
{
private:
	// The number of elements in this union find DS
	int size;

	// Tracking the sizes of each of the components
	vector<int>* sz;

	// parentOf[i] points to the parent of i, if id[i] = i then i is a root node
	vector<int>* parentOf;

	// Tracks the number of components in the union find
	int numComponents;

public:
	UnionFind(int size);

	// Find which component / set 'p' belongs to, take amortized constant time O(a*1)
	int Find(int p);

	// Return whether or not the element 'p' and
	// 'q' are in the same component / set
	bool GetIsConnected(int p, int q);

	// Return the size of the component / set that 'p' belongs to
	int GetComponentSize(int p);

	// Return the number of elements in this UnionFind / Disjoint(?) set
	int GetSize();

	// Return the number of remaining component / sets in this UnionFind
	int NumOfComponents();

	// Unify the components / sets containing elements 'p' and 'q'
	void Unify(int p, int q);
};

