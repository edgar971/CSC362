//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree


#include <iostream>

using namespace std;

//Definition of the node
template <class elemType>
struct binaryTreeNode
{
	elemType info;
	binaryTreeNode<elemType> *llink;
	binaryTreeNode<elemType> *rlink;
};

//Definition of the class
template <class elemType>
class BinaryTreeType
{
public:
	const BinaryTreeType<elemType>& operator=
		(const BinaryTreeType<elemType>&);
	//Overload the assignment operator.
	bool isEmpty() const;
	//Returns true if the binary tree is empty;
	//otherwise, returns false.
	void inorderTraversal() const;
	//Function to do an inorder traversal of the binary tree.
	void preorderTraversal() const;
	//Function to do a preorder traversal of the binary tree.
	void postorderTraversal() const;
	//Function to do a postorder traversal of the binary tree.

	int treeHeight() const;
	//Returns the height of the binary tree.
	void destroyTree();
	//Deallocates the memory space occupied by the binary tree.
	//Postcondition: root_ = NULL;

	int treeNodeCount() const;
	int treeLeavesCount() const;

	BinaryTreeType(const BinaryTreeType<elemType>& otherTree);
	//copy constructor

	BinaryTreeType();
	//default constructor

	~BinaryTreeType();
	//destructor

protected:
	binaryTreeNode<elemType>  *root_;

private:
	void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot,
		binaryTreeNode<elemType>* otherTreeRoot);
	//Makes a copy of the binary tree to which 
	//otherTreeRoot points. The pointer copiedTreeRoot  
	//points to the root_ of the copied binary tree.

	void destroy(binaryTreeNode<elemType>* &p);
	//Function to destroy the binary tree to which p points. 
	//Postcondition: p = NULL

	void inorder(binaryTreeNode<elemType> *p) const;
	//Function to do an inorder traversal of the binary
	//tree to which p points.  
	void preorder(binaryTreeNode<elemType> *p) const;
	//Function to do a preorder traversal of the binary
	//tree to which p points.  
	void postorder(binaryTreeNode<elemType> *p) const;
	//Function to do a postorder traversal of the binary
	//tree to which p points.  

	int height(binaryTreeNode<elemType> *p) const;
	//Function to return the height of the binary tree
	//to which p points. 
	int max(int x, int y) const;
	//Returns the larger of x and y.
	int nodeCount(binaryTreeNode<elemType> *p) const;
	//Function to return the number of nodes in the binary 
	//tree to which p points 
	int leavesCount(binaryTreeNode<elemType> *p) const;
	//Function to return the number of leaves in the binary 
	//tree to which p points 
};

//Definition of member functions

template <class elemType>
BinaryTreeType<elemType>::BinaryTreeType()
{
	root_ = NULL;
}

template <class elemType>
bool BinaryTreeType<elemType>::isEmpty() const
{
	return (root_ == NULL);
}

template <class elemType>
void BinaryTreeType<elemType>::inorderTraversal() const
{
	inorder(root_);
}

template <class elemType>
void BinaryTreeType<elemType>::preorderTraversal() const
{
	preorder(root_);
}

template <class elemType>
void BinaryTreeType<elemType>::postorderTraversal() const
{
	postorder(root_);
}

template <class elemType>
int BinaryTreeType<elemType>::treeHeight() const
{
	return height(root_);
}


template <class elemType>
void  BinaryTreeType<elemType>::copyTree
(binaryTreeNode<elemType>* &copiedTreeRoot,
binaryTreeNode<elemType>* otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new binaryTreeNode<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
} //end copyTree

template <class elemType>
void BinaryTreeType<elemType>::inorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		inorder(p->llink);
		cout << p->info << " ";
		inorder(p->rlink);
	}
}

template <class elemType>
void BinaryTreeType<elemType>::preorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class elemType>
void BinaryTreeType<elemType>::postorder(binaryTreeNode<elemType> *p) const
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		cout << p->info << " ";
	}
}

//Overload the assignment operator
template <class elemType>
const BinaryTreeType<elemType>& BinaryTreeType<elemType>::
operator=(const BinaryTreeType<elemType>& otherTree)
{
	if (this != &otherTree) //avoid self-copy
	{
		if (root_ != NULL)  //if the binary tree is not empty, 
			//destroy the binary tree
			destroy(root_);

		if (otherTree.root_ == NULL) //otherTree is empty
			root_ = NULL;
		else
			copyTree(root_, otherTree.root_);
	}//end else

	return *this;
}

template <class elemType>
void  BinaryTreeType<elemType>::destroy(binaryTreeNode<elemType>* &p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void  BinaryTreeType<elemType>::destroyTree()
{
	destroy(root_);
}

//copy constructor
template <class elemType>
BinaryTreeType<elemType>::BinaryTreeType
(const BinaryTreeType<elemType>& otherTree)
{
	if (otherTree.root_ == NULL) //otherTree is empty
		root_ = NULL;
	else
		copyTree(root_, otherTree.root_);
}

template <class elemType>
BinaryTreeType<elemType>::~BinaryTreeType()
{
	destroy(root_);
}

template <class elemType>
int BinaryTreeType<elemType>::height(binaryTreeNode<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int BinaryTreeType<elemType>::max(int x, int y) const
{
	if (x >= y)
		return x;
	else
		return y;
}

template <class elemType>
int BinaryTreeType<elemType>::nodeCount(binaryTreeNode<elemType> *p) const
{
	
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template <class elemType>
int BinaryTreeType<elemType>::leavesCount(binaryTreeNode<elemType> *p) const
{
	if (p == NULL)
		return 0;
	else if (p->llink == NULL && p->rlink == NULL){
		cout << p->info << " ";
		return 1;
	}
	else
		return leavesCount(p->llink) + leavesCount(p->rlink);
}

template <class elemType>
int BinaryTreeType<elemType>::treeNodeCount() const {
	
	return nodeCount(root_);
}

template <class elemType>
int BinaryTreeType<elemType>::treeLeavesCount() const {
	return leavesCount(root_);
}


#endif