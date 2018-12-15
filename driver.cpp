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
	    
//	    cout << "\nBST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n";
//	    cout << "Inorder Traversal of BST: \n";
//	    intBST.inorder(cout);
//	    cout << "\nPreorder Traversal of BST: \n";
//	    intBST.preorder(cout);
//	    cout << "\nPostorder Traversal of BST: \n";
//	    intBST.postorder(cout);
	    cout<<endl;
	    
    	cout<<"Tree height: "<<intBST.getHeight()<<endl;
    	cout<<"Tree size: "<<intBST.getNumberOfNodes()<<endl;
    	cout<<"Tree leaves: "<<intBST.getNumberOfLeaves()<<endl;

    }
    cout << "\n";
    intBST.graph(cout);
    
    cout << "\nBST " << (intBST.isEmpty() ? "is" : "is not") << " empty\n";
    cout << "Inorder Traversal of BST: \n";
    intBST.inorder(cout);
    cout << "\nPreorder Traversal of BST: \n";
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
    cout << "\nPreorder Traversal of BST: \n";
    intBST.preorder(cout);
    cout << "\nPostorder Traversal of BST: \n";
    intBST.postorder(cout);
    cout << endl;
    

    
}

/* BONUS: It goes to the right subtree from the root, then takes the leftmost leaf it can find
                                1000
                        950
                                900
                850
                                825
                        800
                                775
        750
                                725
                        700
                                675
                650
                                625
                        600
                                525
 500
                                425
                        400
                                375
                350
                                325
                        300
                                275
        250
                                225
                        200
                                175
                150
                                100
                        50
                                0

Tree height: 5
Tree size: 31
Tree leaves: 16

Item to insert (-999 to stop): -999

                                1000
                        950
                                900
                850
                                825
                        800
                                775
        750
                                725
                        700
                                675
                650
                                625
                        600
                                525
 500
                                425
                        400
                                375
                350
                                325
                        300
                                275
        250
                                225
                        200
                                175
                150
                                100
                        50
                                0

BST is not empty
Inorder Traversal of BST:
0  50  100  150  175  200  225  250  275  300  325  350  375  400  425  500  525  600  625  650  675  700  725  750  775  800  825  850  900  950  1000
Preorder Traversal of BST:
500  250  150  50  0  100  200  175  225  350  300  275  325  400  375  425  750  650  600  525  625  700  675  725  850  800  775  825  950  900  1000
Postorder Traversal of BST:
0  100  50  175  225  200  150  275  325  300  375  425  400  350  250  525  625  600  675  725  700  650  775  825  800  900  1000  950  850  750  500


Now testing the contains() operation.
Try both items in the BST and some not in it:
Item to find (-999 to stop): -999

Now testing the remove() operation.
Try both items in the BST and some not in it:

Item to remove (-999 to stop): 500
                                1000
                        950
                                900
                850
                                825
                        800
                                775
        750
                                725
                        700
                                675
                650
                                625
                        600
 525
                                425
                        400
                                375
                350
                                325
                        300
                                275
        250
                                225
                        200
                                175
                150
                                100
                        50
                                0
Tree height: 5
Tree size: 30
Tree leaves: 15
*/

/* Sample output:
Constructing empty BST
BST is empty

Inorder Traversal of BST:

Now insert a bunch of integers into the BST.
Try items not in the BST and some that are in it:

Item to insert (-999 to stop): 60

Tree height: 1
Tree size: 1
Tree leaves: 1

Item to insert (-999 to stop): 20

Tree height: 2
Tree size: 2
Tree leaves: 1

Item to insert (-999 to stop): 70

Tree height: 2
Tree size: 3
Tree leaves: 2

Item to insert (-999 to stop): 40

Tree height: 3
Tree size: 4
Tree leaves: 2

Item to insert (-999 to stop): 10

Tree height: 3
Tree size: 5
Tree leaves: 3

Item to insert (-999 to stop): 50

Tree height: 4
Tree size: 6
Tree leaves: 3

Item to insert (-999 to stop): 30

Tree height: 4
Tree size: 7
Tree leaves: 4

Item to insert (-999 to stop): 30

ERROR: Item already in tree.

Tree height: 4
Tree size: 7
Tree leaves: 4

Item to insert (-999 to stop): -999

        70
 60
                        50
                40
                        30
        20
                10

BST is not empty
Inorder Traversal of BST:
10  20  30  40  50  60  70
Preorder Traversal of BST:
60  20  10  40  30  50  70
Postorder Traversal of BST:
10  30  50  40  20  70  60


Now testing the contains() operation.
Try both items in the BST and some not in it:
Item to find (-999 to stop): 30
Found
Item to find (-999 to stop): 45
Not found
Item to find (-999 to stop): -999

Now testing the remove() operation.
Try both items in the BST and some not in it:

Item to remove (-999 to stop): 40 
//HAS TWO CHILDREN: Promotes the node to the right, the higher of the two, closest to the root.
        70
 60
                50
                        30
        20
                10
Tree height: 4
Tree size: 6
Tree leaves: 3

Item to remove (-999 to stop): 20
//HAS TWO CHILDREN: Goes to the right subtree of the deleted node,
//then goes left within that subtree until it reaches a leaf node, which it promotes
        70
 60
                50
        30
                10
Tree height: 3
Tree size: 5
Tree leaves: 3

Item to remove (-999 to stop): 60
//Removes root: Promotes 70, the node on the right with no children.
 70
                50
        30
                10
Tree height: 3
Tree size: 4
Tree leaves: 2

Item to remove (-999 to stop): 45

ERROR: Item not found.

 70
                50
        30
                10
Tree height: 3
Tree size: 4
Tree leaves: 2

Item to remove (-999 to stop): -999

Inorder Traversal of BST:
10  30  50  70
Preorder Traversal of BST:
70  30  10  50
Postorder Traversal of BST:
10  50  40  20  70  60

--------------------------------
Process exited after 37.68 seconds with return value 0
Press any key to continue . . .
*/
