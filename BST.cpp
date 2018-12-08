#include "BST.h"

//--- Definition of constructor
template <typename ItemType>
BST<ItemType>::BST()
: myRoot(nullptr)
{}

template<class ItemType>
BST<ItemType>::~BST()
{
    destroyTree(myRoot);
}  // end destructor

template<class ItemType>
void BST<ItemType>::destroyTree(BinaryNode<ItemType> *subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete subTreePtr;
        subTreePtr = nullptr;
    }  // end if
}  // end destroyTree

//--- Definition of empty()
template <typename ItemType>
bool BST<ItemType>::isEmpty() const
{ return myRoot == nullptr; }

//--- Definition of contains()
template <typename ItemType>
bool BST<ItemType>::contains(const ItemType & anItem) const
{
	return search(anItem);
}

//--- Definition of search()
template <typename ItemType>
bool BST<ItemType>::search(const ItemType & anItem) const
{
    BinaryNode<ItemType> *locptr = myRoot;
    bool found = false;
    while (!found && locptr != nullptr)
    {
        if (anItem < locptr->getItem())       // descend left
            locptr = locptr->getLeftChildPtr();
        else if (locptr->getItem() < anItem)  // descend right
            locptr = locptr->getRightChildPtr();
        else                           // item found
            found = true;
    }
    return found;
}

//--- Definition of add()
template <typename ItemType>
bool BST<ItemType>::add(const ItemType & anItem)
{
    BinaryNode<ItemType>* locptr = myRoot;   // search pointer
    BinaryNode<ItemType>* parent = nullptr;        // pointer to parent of current node
    bool found = false;     // indicates if anItem already in BST
    while (!found && locptr != nullptr)
    {
        parent = locptr;
        if (anItem < locptr->getItem())       // descend left
            locptr = locptr->getLeftChildPtr();
        else if (locptr->getItem() < anItem)  // descend right
            locptr = locptr->getRightChildPtr();
        else                           // anItem found
            found = true;
    }
    if (!found)
    {                                 // construct node containing anItem
        locptr = new BinaryNode<ItemType>(anItem);
        if (parent == nullptr)               // empty tree
            myRoot = locptr;
        else if (anItem < parent->getItem() )  // insert to left of parent
            parent->setLeftChildPtr(locptr);
        else                           // insert to right of parent
            parent->setRightChildPtr(locptr);
    }
    return found;
}

//--- Definition of remove()
template <typename ItemType>
bool BST<ItemType>::remove(const ItemType & anItem)
{
    bool found;                      // signals if anItem is found
    BinaryNode<ItemType>* x;                            // points to node to be deleted
    BinaryNode<ItemType>* parent;                       //    "    " parent of x and xSucc
    search2(anItem, found, x, parent);
    
    if (!found)
    {
        return false;
    }
    //else
    if (x->getLeftChildPtr() != nullptr && x->getRightChildPtr() != nullptr)
    {                                // node has 2 children
        // Find x's inorder successor and its parent
        BinaryNode<ItemType> *xSucc = x->getRightChildPtr();
        parent = x;
        while (xSucc->getLeftChildPtr() != nullptr)       // descend left
        {
            parent = xSucc;
            xSucc = xSucc->getLeftChildPtr();
        }
        
        // Move contents of xSucc to x and change x
        // to point to successor, which will be removed.
        x->setItem(xSucc->getItem());
        x = xSucc;
    } // end if node has 2 children
    
    // Now proceed with case where node has 0 or 2 child
    BinaryNode<ItemType>* subtree = x->getLeftChildPtr();             // pointer to a subtree of x
    if (subtree == nullptr)
        subtree = x->getRightChildPtr();
    if (parent == nullptr)                  // root being removed
        myRoot = subtree;
    else if (parent->getLeftChildPtr() == x)       // left child of parent
        parent->setLeftChildPtr(subtree);
    else                              // right child of parent
        parent->setRightChildPtr(subtree);
    delete x;
    
    return true;
}

//--- Definition of inorder()
template <typename ItemType>
void BST<ItemType>::inorder(ostream & out) const
{
    inorderAux(out, myRoot);
}

//--- Definition of graph()
template <typename ItemType>
void BST<ItemType>::graph(ostream & out) const
{ graphAux(out, 0, myRoot); }

//--- Definition of search2()
template <typename ItemType>
void BST<ItemType>::search2(const ItemType & anItem, bool & found,
                            BinaryNode<ItemType>* & locptr,
                            BinaryNode<ItemType>* & parent) const
{
    locptr = myRoot;
    parent = nullptr;
    found = false;
    while (!found && locptr != nullptr)
    {
        if (anItem < locptr->getItem())       // descend left
        {
            parent = locptr;
            locptr = locptr->getLeftChildPtr();
        }
        else if (locptr->getItem() < anItem)  // descend right
        {
            parent = locptr;
            locptr = locptr->getRightChildPtr();
        }
        else                           // anItem found
            found = true;
    }
}

//--- Definition of inorderAux()
template <typename ItemType>
void BST<ItemType>::inorderAux(ostream & out,
                               BinaryNode<ItemType>* subtreeRoot) const
{
    if (subtreeRoot != nullptr)
    {
        inorderAux(out, subtreeRoot->getLeftChildPtr());    // L operation
        out << subtreeRoot->getItem() << "  ";      // V operation
        inorderAux(out, subtreeRoot->getRightChildPtr());   // R operation
    }
}

//--- Definition of graphAux()
#include <iomanip>

template <typename ItemType>
void BST<ItemType>::graphAux(ostream & out, int indent,
                             BinaryNode<ItemType>* subtreeRoot) const
{
    if (subtreeRoot != nullptr)
    {
        graphAux(out, indent + 8, subtreeRoot->getRightChildPtr());
        out << setw(indent) << " " << subtreeRoot->getItem() << endl;
        graphAux(out, indent + 8, subtreeRoot->getLeftChildPtr());
    }
}

//---CUSTOM METHODS BEGIN HERE---
template<typename T>
int BST<T>::getHeight() const
{
	return getHeightAux(myRoot);
}

template<typename T>
int BST<T>::getHeightAux(BinaryNode<T> *locptr) const
{	
	if (locptr != nullptr)
	{
		int leftDepth = getHeightAux(locptr->getLeftChildPtr());
		int rightDepth = getHeightAux(locptr->getRightChildPtr());
		return ((leftDepth > rightDepth) ? leftDepth : rightDepth) + 1;
	}
	return 0;
}

template<typename T>
int BST<T>::getNumberOfNodes() const
{
	return getNumberOfNodesAux(myRoot);
}

template<typename T>
int BST<T>::getNumberOfNodesAux(BinaryNode<T> *locptr) const
{
	if (locptr != nullptr)
	{
		int leftSize = getNumberOfNodesAux(locptr->getLeftChildPtr());
		int rightSize = getNumberOfNodesAux(locptr->getRightChildPtr());
		return leftSize + rightSize + 1;
	}
	return 0;
}

template<typename T>
int BST<T>::getNumberOfLeaves() const
{
	return getNumberOfLeavesAux(myRoot);
}

template<typename T>
int BST<T>::getNumberOfLeavesAux(BinaryNode<T> *locptr) const
{
	if (locptr != nullptr)
	{
		if (locptr->getLeftChildPtr() == nullptr && locptr->getRightChildPtr() == nullptr)
			return 1;
		return getNumberOfLeavesAux(locptr->getLeftChildPtr()) + getNumberOfLeavesAux(locptr->getRightChildPtr());
	}
	return 0;
}

//template <typename ItemType>
//void BST<ItemType>::inorderAux(ostream & out,
//                               BinaryNode<ItemType>* subtreeRoot) const
//{
//    if (subtreeRoot != nullptr)
//    {
//        inorderAux(out, subtreeRoot->getLeftChildPtr());    // L operation
//        out << subtreeRoot->getItem() << "  ";      // V operation
//        inorderAux(out, subtreeRoot->getRightChildPtr());   // R operation
//    }
//}

//ROOT -> Left -> Right
template<typename T>
void BST<T>::preorder(ostream & out) const
{
	return preorderAux(out, myRoot);
}

template<typename T>
void BST<T>::preorderAux(ostream & out, BinaryNode<T> *locptr) const
{
	if (locptr != nullptr)
	{
		out << locptr->getItem() << "  "; //Root
		preorderAux(out, locptr->getLeftChildPtr()); //Left
		preorderAux(out, locptr->getRightChildPtr()); //Right
	}
	return;
}

//Left -> Right -> ROOT
template<typename T>
void BST<T>::postorder(ostream & out) const
{
	return postorderAux(out, myRoot);
}

template<typename T>
void BST<T>::postorderAux(ostream & out, BinaryNode<T> *locptr) const
{
	if (locptr != nullptr)
	{
		postorderAux(out, locptr->getLeftChildPtr()); //Left
		postorderAux(out, locptr->getRightChildPtr()); //Right
		out << locptr->getItem() << "  "; //Root
	}
	return;
}

