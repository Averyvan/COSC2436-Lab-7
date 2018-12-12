

#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
    // Testing Constructor and empty()
    BST<int> intBST;            // test the class constructor
    cout << "Constructing empty BST\n";
    cout << "BST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n";


    
    // Testing inorder
    cout << "\nInorder Traversal of BST: \n";
    intBST.inorder(cout);
    
    // Testing insert
    cout << "\nNow insert a bunch of integers into the BST."
    "\nTry items not in the BST and some that are in it:\n";
    int number;
    for (;;)
    {
        cout << "\nItem to insert (-999 to stop): ";
        cin >> number;
        if (number == -999) break;
        intBST.add(number);
        
        intBST.graph(cout);
	    
	    cout << "\nBST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n";
	    cout << "\nInorder Traversal of BST: \n";
	    intBST.inorder(cout);
	    cout << "Preorder Traversal of BST: \n";
	    intBST.preorder(cout);
	    cout << "\nPostorder Traversal of BST: \n";
	    intBST.postorder(cout);
	    cout<<endl;
	    
    	cout<<"Tree height: "<<intBST.getHeight()<<endl;
    	cout<<"Tree size: "<<intBST.getNumberOfNodes()<<endl;
    	cout<<"Tree leaves: "<<intBST.getNumberOfLeaves()<<endl;

    }
    cout << "\n";
    intBST.graph(cout);
    
    cout << "\nBST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n";
    cout << "\nInorder Traversal of BST: \n";
    intBST.inorder(cout);
    cout << "Preorder Traversal of BST: \n";
    intBST.preorder(cout);
    cout << "\nPostorder Traversal of BST: \n";
    intBST.postorder(cout);
    
    cout << endl;

    
    // Testing search()
    cout << "\n\nNow testing the contains() operation."
    "\nTry both items in the BST and some not in it:\n";
    for (;;)
    {
        cout << "Item to find (-999 to stop): ";
        cin >> number;
        if (number == -999) break;
        cout << (intBST.contains(number) ? "Found" : "Not found") << endl;
    }
    
    // Testing remove()
    cout << "\nNow testing the remove() operation."
    "\nTry both items in the BST and some not in it:\n";
    for (;;)
    {
        cout << "\nItem to remove (-999 to stop): ";
        cin >> number;
        if (number == -999) break;
        intBST.remove(number);
        intBST.graph(cout);
		cout<<"Tree height: "<<intBST.getHeight()<<endl;
    	cout<<"Tree size: "<<intBST.getNumberOfNodes()<<endl;
    	cout<<"Tree leaves: "<<intBST.getNumberOfLeaves()<<endl;

    }
    cout << "\nInorder Traversal of BST: \n";
    intBST.inorder(cout);
    cout << "Preorder Traversal of BST: \n";
    intBST.preorder(cout);
    cout << "\nPostorder Traversal of BST: \n";
    cout << endl;
    

    
}

/* Sample output:
Item to insert (-999 to stop): 50
        70
 60
                        50
                40
                        30
        20
                10

BST is not empty
Preorder Traversal of BST:
60  20  10  40  30  50  70
Inorder Traversal of BST:
10  20  30  40  50  60  70
Postorder Traversal of BST:
10  30  50  40  20  70  60
Tree height: 4
Tree size: 7
Tree leaves: 4



