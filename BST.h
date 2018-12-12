
/* BST.h contains the declaration of class template BST.
 Basic operations:
 Constructor: Constructs an empty BST
 isEmpty:       Checks if a BST is empty
 contains:      Search a BST for an item
 add:         Adds a value into a BST
 remove:      Removes a value from a BST
 inorder:     Inorder traversal of a BST -- output the item values
 graph:       Output a grapical representation of a BST
 Private utility helper operations:
 search2:     Used by delete
 inorderAux:  Used by inorder
 graphAux:    Used by graph
 Other operations described in the exercises:
 destructor
 copy constructor
 assignment operator
 preorder, postorder, and level-by-level traversals
 level finder
 Note: Execution terminates if memory isn't available for a new BST node.
 ---------------------------------------------------------------------------*/

#include <iostream>
#include "BinaryNode.h"
#include <vector>

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template<class ItemType>
class BST
{
public:
    /***** Function Members *****/
    BST();
    /*------------------------------------------------------------------------
     Construct a BST object.
     
     Precondition:  None.
     Postcondition: An empty BST has been constructed.
     -----------------------------------------------------------------------*/
    
    ~BST();
    
    bool isEmpty() const;
    /*------------------------------------------------------------------------
     Check if BST is empty.
     
     Precondition:  None.
     Postcondition: Returns true if BST is empty and false otherwise.
     -----------------------------------------------------------------------*/
    
    bool contains(const ItemType & item) const;
    /*------------------------------------------------------------------------
     Search the BST for item.
     
     Precondition:  None.
     Postcondition: Returns true if item found, and false otherwise.
     -----------------------------------------------------------------------*/
    
    bool add(const ItemType & item);
    /*------------------------------------------------------------------------
     Add item into BST.
     
     Precondition:  None.
     Postcondition: BST has been modified with item inserted at proper
     position to maintain BST property.
     Returns true if item was successfull inserted.
     Returns false if item was already in the binary search tree
     ------------------------------------------------------------------------*/
    
    bool remove(const ItemType & item);
    /*------------------------------------------------------------------------
     Remove item from BST.
     
     Precondition:  None.
     Postcondition: BST has been modified with item removed (if present);
     BST property is maintained.
     Returns true if item was successfully removed.
     Otherwise, returns false.
     Note: remove uses auxiliary function search2() to locate the node
     containing item and its parent.
     ------------------------------------------------------------------------*/
    
    void inorder(ostream & out) const;
    /*------------------------------------------------------------------------
     Inorder traversal of BST.
     
     Precondition:  ostream out is open.
     Postcondition: BST has been inorder traversed and values in nodes
     have been output to out.
     Note: inorder uses private auxiliary function inorderAux().
     ------------------------------------------------------------------------*/
    
    void graph(ostream & out) const;
    /*------------------------------------------------------------------------
     Graphic output of BST.
     
     Precondition:  ostream out is open.
     Postcondition: Graphical representation of BST has been output to out.
     Note: graph() uses private auxiliary function graphAux().
     ------------------------------------------------------------------------*/
     
    //Custom functions start here
    
	int getHeight() const;
	//Calls getHeightAux to get height of BST
	//Post: returns height as int
	
	int getNumberOfNodes() const;
	//Calls getNumberOfNodesAux to get total number of nodes in BST
	//Post: returns total number of nodes as int
	
	int getNumberOfLeaves() const;
	//Calls getNumberOfLeavesAux to get total number of leaves (nodes without children) in BST
	//Post: returns number of leaves as omt
	
	//ROOT -> Left -> Right
	void preorder(ostream & out) const;
	//Calls preorderAux for accurate traversal
	//Pre: ostream out is open
	//Post: BST has been preorder traversed and node values output to out
	
	//Left -> Right -> ROOT
	void postorder(ostream & out) const;
	//Calls postorderAux for accurate traversal
	//Pre: ostream out is open
	//Post: BST has been postorder traversed and node values output to out
	
private:
    
    void destroyTree(BinaryNode<ItemType> *subTreePtr);
    
    
    bool search(const ItemType & item) const;
    /*------------------------------------------------------------------------
     Search the BST for item.
     
     Precondition:  None.
     Postcondition: Returns true if item found, and false otherwise.
     -----------------------------------------------------------------------*/
    
    /***** Private Function Members *****/
    void search2(const ItemType & item, bool & found,
                 BinaryNode<ItemType>* & locptr, BinaryNode<ItemType>* & parent) const;
    /*------------------------------------------------------------------------
     Locate a node containing item and its parent.
     
     Precondition:  None.
     Postcondition: locptr points to node containing item or is null if
     not found, and parent points to its parent.#include <iostream>
     ------------------------------------------------------------------------*/
    
    void inorderAux(ostream & out,
                    BinaryNode<ItemType>* subtreePtr) const;
    /*------------------------------------------------------------------------
     Inorder traversal auxiliary function.
     
     Precondition:  ostream out is open; subtreePtr points to a subtree
     of this BST.
     Postcondition: Subtree with root pointed to by subtreePtr has been
     output to out.
     ------------------------------------------------------------------------*/
    
    void graphAux(ostream & out, int indent,
                  BinaryNode<ItemType>* subtreeRoot) const;
    /*------------------------------------------------------------------------
     Graph auxiliary function.
     
     Precondition:  ostream out is open; subtreePtr points to a subtree
     of this BST.
     Postcondition: Graphical representation of subtree with root pointed
     to by subtreePtr has been output to out, indented indent spaces.
     ------------------------------------------------------------------------*/
    
    //Start of custom functions
	int getHeightAux(BinaryNode<ItemType> *locptr) const;
	/*------------------------------------------------------------------------
	 Traverse BST to find height. Custom Function
	 
	 Pre: locptr is pointing at a node in a BST
	 Post: Returns 1 + (greater of height down the left side or right side)
	 ------------------------------------------------------------------------*/
	
	int getNumberOfNodesAux(BinaryNode<ItemType> *locptr) const;
	//Pre: locptr is pointing at a node in a BST
	//Post: Returns 1 + nodes on left side + nodes on right side
	
	int getNumberOfLeavesAux(BinaryNode<ItemType> *locptr) const;
	//Pre: locptr is pointing at a node in a BST
	//Post: Returns leaves on left side + leaves on right side
	
	void preorderAux(ostream & out, BinaryNode<ItemType> *locptr) const;
	//Pre: ostream out is open, locptr points to a node in a BST
	//Post: subtree with root pointed to by locptr has been output to out
	
	void postorderAux(ostream & out, BinaryNode<ItemType> *locptr) const;
	//Pre: ostream out is open, locptr points to a node in a BST
	//Post: subtree with root pointed to by locptr has been output to out
	
    /***** Data Members *****/
    BinaryNode<ItemType>* myRoot;
    
}; // end of class template declaration

#include "BST.cpp"
#endif
