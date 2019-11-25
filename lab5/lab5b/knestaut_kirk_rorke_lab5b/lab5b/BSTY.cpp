#include "BSTY.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>

// Author: Aaron Knestaut, Dylan Kirk, Olivia Rorke

using namespace std;

BSTY::BSTY() {
    root = NULL;
}

// You write:  insert a new node with data x (a string) into the
// binary search tree
// This method should return true if a new node is inserted and
// false if the data x is already in the tree
// Remember to check whether the new node will be the root
// (meaning the root is currently NULL) and if so, set the root
// to be the new node.
// Note: Make sure you make the new node point to its parent!!!
// Note2: after you've inserted a new node, you should call the
// adjustHeights method that will update the heights of all the
// ancestors of the node that was just inserted.
bool BSTY:: insertit(string x ) {
    NodeT *tmp = new NodeT(x);
    bool done = false;
    NodeT *current = root;
    
    //Insert the first node in the tree (if the root is null)
    if(root == NULL){
        root = tmp;
        return true;
    }
    
    while(!done){
        //Ensure no duplicate data
        if(tmp->data == current->data){
            return false;
        }
        
        //If new node tmp's data is less than the root, it will check to see if current's left node is null, if it is, then it inserts tmp where the prior left node was. It will also set the parent of new parent node of tmp to be the root.
        else if(tmp->data < current->data){
            if(current->left == NULL){
                current->left = tmp;
                tmp->parent = current;
                done = true;
            }else{
                current = current->left;
            }
        }

        else if(tmp->data > current->data){
            if(current->right == NULL){
                current->right = tmp;
                tmp->parent = current;
                done = true;
            }else{
                current = current->right;
            }
        }
    }
    adjustHeights(tmp);
    return true;
}


// the adjustHeights method updates the heights of every ancestor of the node n.
// This method will be massively useful with our next lab, so make sure you have
// this working now.  It should be called whenever you change the height of a
// a particular node.  So, for instance, when a new node is inserted as a leaf,
// its height is 1.  The adjustHeights method should then check the parent to see
// if the height of the parent changes (the height of each node is the maximum of
// the height of the left child and the height of the right child, plus 1).  If
// the parent's height changes, then the grandparent's height should be checked and,
// if necessary, adjusted.  If the grandparent's height is updated, then the great-
// grandparent's height should be adjusted, etc.  The checking stops when either
// the loop has worked its way up to the root, or until the currently being checked
// ancestor is not changed.
void BSTY::adjustHeights(NodeT *n) {
    NodeT *current = n;
    NodeT *current2 = n;
    int leftHeight = 0;
    int rightHeight = 0;
    int maxHeight;

    while(current != root){
        if(current->parent->left != NULL){
            leftHeight = current->parent->left->height;
        }
        if(current->parent->right != NULL){
            rightHeight = current->parent->right->height;
        }

        maxHeight = max(leftHeight, rightHeight);

        if(current->parent->height != maxHeight + 1){
            current->parent->height = maxHeight + 1;
        }

        if(findBalance(current) == 2){
            //Case 1
            if(findBalance(current->left) == 1){
                rotateRight(current);
            } else if(findBalance(current->left) == -1){ //Case 2
                rotateLeft(current->left);
               // rotateRight(current);
            }
        } else if(findBalance(current) == -2){
            //Case 3
            if(findBalance(current->right) == -1){
                rotateLeft(current);
            } else if(findBalance(current->right) == 1){
                rotateRight(current->right);
               // rotateLeft(current);
            }
        }

        current = current->parent;
    }

    if(current == root){
        if(current->left != NULL){
            leftHeight = current->left->height;
        }
        if(current->right != NULL){
            rightHeight = current->right->height;
        }

        maxHeight = max(leftHeight, rightHeight) + 1;

        current->height = maxHeight;

        if(findBalance(current) == 2){
            //Case 1
            if(findBalance(current->left) == 1){
                rotateRight(current);
            } else if(findBalance(current->left) == -1){ //Case 2
                rotateLeft(current->left);
               // rotateRight(current);
            }
        } else if(findBalance(current) == -2){
            //Case 3
            if(findBalance(current->right) == -1){
                rotateLeft(current);
            } else if(findBalance(current->right) == 1){
                rotateRight(current->right);
              //  rotateLeft(current);
            }
        }
    }
}

void BSTY::printTreeIO() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        printTreeIO(root);
    }
}

// Print the tree in order (left child, then parent, then right child).
// Use the slides, but make sure you can understand how the tree is
// traversed in order
void BSTY::printTreeIO(NodeT *n) {
    NodeT *current = n;
    if(current == NULL)
        return;
    

    printTreeIO(current->left);
    cout << "|" << current->data << ", " << current->height << "|" << endl;
    printTreeIO(current->right);
    
}


void BSTY::printTreePre() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        printTreePre(root);
    }
}

// Prints the tree using pre-order traversal (parent, then left child, then right
// child.  Use the slides, but make sure you understand how a tree is traversed in
// pre-order
void BSTY::printTreePre(NodeT *n) {
    NodeT *current = n;
    if (current == NULL)
        return;
    //print data
    cout << "|" << current->data << ", " << current->height << "|" << endl;
    printTreePre(current->left);
    printTreePre(current->right);
    
    

}

void BSTY::printTreePost() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        printTreePost(root);
        cout << endl;
    }
}

// Prints the tree using pre-order traversal (left child, then right, then parent)
// Use the slides, but make sure you understand how a tree is traversed in
// post-order
void BSTY::printTreePost(NodeT *n) {
    NodeT *current = n;
    if(current == NULL){
        return;
    }
    printTreePost(current->left);
    printTreePost(current->right);
    cout << "|" << current->data << ", " << current->height << "|" << endl;
}

void BSTY::myPrint() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        myPrint(root);
        cout << endl;
    }
}
void BSTY::myPrint(NodeT *n) {
    if (n == NULL) {
        return;
    }
    else {
        myPrint(n->left);
        cout << n->data.length()-1;
        if (mine) {
            cout <<".";
            mine = false;
        }
        myPrint(n->right);
    }
}

// the find method takes as input a string, and finds whether that string is already
// in the tree or not.  If it is in the tree, that node is returned from the tree.
// If it isn't, NULL is returned.
// NOTE: If the node can't be found, this method prints out that x can't be found.
// if it is found, the printNode method is called for the node.
NodeT *BSTY::find(string x) {
    bool done = false;
    NodeT *current = root;
    int count = 0;
    
    if(root == NULL){
        cout << "Empty Tree" << endl;
        return NULL;
    }
    
    while(!done){
        if(current == NULL){
            cout << x + " can't be found" << endl;
            return NULL;
        }
        else if(x == current->data){
            current->printNode();
            return current;
        }
        else if(x < current->data){
            current = current->left;
        }
        else if(x > current->data){
            current = current->right;
        }
        count++;
    }
    
    cout << "number of loops to find word: " << count << endl;
    return 0;
}


/*************************************************************************************/
/* Extra Credit Methods                                                              */
/* Challenging: worth 35 EC pts to go towards labs                                   */
/* NOTE: IF YOU CHOOSE NOT TO IMPLEMENT THESE METHODS, YOU ARE STILL RESPONSIBLE FOR */
/* UNDERSTANDING HOW THEY WORK!!                                                     */
/*************************************************************************************/
/* When removing a node from a binary search tree, the resulting tree MUST BE a binary
 /* search tree.
 /*
 /* When removing a node, there are 3 conditions:
 /* 1: when the node being removed has no children, in which case the node is deleted,
 /* the node's parent is set to NULL, and the node's parent's height is adjusted (if
 /* necessary) and heights on up are adjusted.
 /* 2: when the node being removed has one child, in which case the node's parent points
 /* to the node's child, and the node's child points to the node's parent, and the node
 /* is deleted (and the height of the parent on up as necessary is adjusted)
 /* 3: when the node has 2 children, in which case the left-most child of the node's
 /* right child replaces the node.
 /* A couple of notes about this one: you are replacing a node with a node that is lower
 /* down in the tree.  That means that you are, in essence, removing the node from that
 /* lower position and moving it up to the old node's location.  Thus the replacing node
 /* must be removed using 1 or 2 above (why not 3?).  The heights must be adjusted after
 /* the replacing node is removed from its old location but before it is inserted into its
 /* new location.  Equally, the replacing node's height must be adjusted to be the larger of
 /* its two children's heights before you adjust heights above that.
 /*****************************************************************************************/
/* remove(): takes as input a string, uses the find method to find the node in the tree that
 /* holds that string, and then calls replace1, replace2, or replace3 depending on what type
 /* of replacing should be done.  It adjusts the heights, deletes teh node, and returns
 /* true if the removal was successful.
 */
bool BSTY::remove(string s) {
    NodeT *current = find(s);
    
    if(current == NULL){
        return false;
    }
    
    if(current->left == NULL && current->right == NULL){
        remove1(current);
    }
    else if((current->left == NULL && current->right != NULL) || (current->left != NULL && current->right == NULL)){
        remove2(current);
    }
    else if(current->left != NULL && current->right != NULL){
        remove3(current);
    }
    
    return 0;
    
}



/* remove1(): called when the node to be removed has no children. Takes as input the
 /* node to be removed, and sets the parent of the node to point to NULL.
 /* helpful hint: if (n->parent->left == n) is true, then n is its parent's left child.
 /* Make sure you check to whether n is the root or not.
 */
void BSTY::remove1(NodeT *n) {
    delete n;
    
    if(n != root){
        if(n->parent->left == n){
            n->parent->left = NULL;
        }else if(n->parent->right == n){
            n->parent->right = NULL;
        }
        n->parent->height = n->parent->height - 1;
        adjustHeights(n->parent);
    } else {
        root = NULL;
    }
}




/* remove2(): called when the node to be removed has 1 child only.  Takes as input
 /* the node to be removed and bypasses it by making the parent point to the node's
 /* one child, and makes the node's one child point to the node's parent.
 /* This one needs a bunch of checking - you need to see if the node is the parent's
 /* left or right child, and you need to see if the node's child is its left or its
 /* right child.
 /* Also, make sure you check that if the node to be removed is the root, then the
 /* one child becomes the root.
 */
void BSTY::remove2(NodeT *n) {
    delete n;
    
    bool parentSide = false; //False = left side of parent, true = right side of parent
    bool childSide = false; //False = child on left, true = child on right
    
    if(n != root){
        if(n->parent->left == n){
            parentSide = false;
        } else {
            parentSide = true; //Right = true
        }
    }
    
    if(n->left != NULL){
        childSide = false;
    } else {
        childSide = true;
    }
    
    if(n == root){
        if(childSide){
            root = n->right;
        } else {
            root = n->left;
        }
        root->parent = NULL;
    } else {
        if(parentSide){
            if(childSide){
                n->parent->right = n->right;
                n->right->parent = n->parent;
            } else {
                n->parent->right = n->left;
                n->left->parent = n->parent;
            }
        } else {
            if(childSide){
                n->parent->left = n->right;
                n->right->parent = n->parent;
            } else {
                n->parent->left = n->left;
                n->left->parent = n->parent;
            }
        }
        n->parent->height = n->parent->height - 1;
        adjustHeights(n->parent);
    }
}

/* remove3(): called when the node to be removed has 2 children.  Takes as input the
 /* node to be removed.  The node to replace the node to be removed should be the
 /* left-most descendent of the node's right child.  That way the binary search tree
 /* properties are guaranteed to be maintained.
 /* When replacing the node to be removed with the replacing node, the replacing node
 /* is, in essence, being removed from its place in the tree, and thus replace1 or
 /* replace2 methods should be used.
 /* The new node's parent must be set to the removed node's parent, the removed node's
 /* parent must point to the new node, the new node's left child must point to the
 /* removed node's left child (and the child must point to the new node as a parent),
 /* and the same for teh right child.
 /* Remember to take into account that the node being removed might be the root.
 */
void BSTY::remove3(NodeT *n) {
    NodeT *replace = findMin(n);
    
    n->data = replace->data;
    
    if(replace->right != NULL){
        remove2(replace);
    } else {
        remove1(replace);
    }
}

/* findMin(): takes as input a node, and finds the left-most descendant of its
 /* right child.  The left-most descendent is returned.
 */
NodeT *BSTY::findMin(NodeT *n) {
    NodeT *rightChild = n->right;
    
    while(rightChild->left != NULL){
        rightChild = rightChild->left;
    }
    
    return rightChild;
}

void BSTY::myPrintEC() {
    if (root == NULL ) {
        cout << "Empty Tree" << endl;
    }
    else {
        myPrintEC(root);
        cout << endl;
    }
}
void BSTY::myPrintEC(NodeT *n) {
    if (n == NULL) {
        return;
    }
    else {
        myPrintEC(n->left);
        cout << alpha[n->data.length()-2];
        myPrintEC(n->right);
    }
}


/************************************************************************/

/*
 * rotates to fix unbalanced trees
 * parameters:
 * 		NodeT n - a tree
 * returns:
 * 		NodeT - the root of the rotated tree
 *
 */
NodeT * BSTY::rotateRight(NodeT *n){
    NodeT *leftChild = n->left;
    NodeT *newChild = leftChild->right;

    //Update passed root to have right child's, left child
    n->left = newChild;
    if(newChild != NULL){
    n->left->parent = n;
    }

    //Update rightChild to be parent of passed node
    leftChild->right = n;

    if(n->parent == NULL){
        root = leftChild;
        leftChild->parent = n->parent;
    } else {
        leftChild->parent = n->parent;
        if(leftChild->parent->left == n){
            leftChild->parent->left = leftChild;
        }else{
            leftChild->parent->right = leftChild;
        }
    }
    n->parent = leftChild;

    int leftHeight = 0;
    int rightHeight = 0;

    if(n->left != NULL){
        leftHeight = n->left->height;
    }
    if(n->right != NULL){
        rightHeight = n->right->height;
    }

    n->height = max(leftHeight, rightHeight) + 1;

    adjustHeights(n);
    return n;
}

/*
 * rotates to fix unbalanced trees
 * parameters:
 * 		NodeT n - a tree
 * returns:
 * 		NodeT - the root of a rotated tree
 */
NodeT * BSTY::rotateLeft(NodeT *n){
    NodeT *rightChild = n->right;
    NodeT *newChild = rightChild->left;

    //Update passed root to have right child's, left child
    n->right = newChild;
    if(newChild != NULL){
    n->right->parent = n;
    }

    //Update rightChild to be parent of passed node
    rightChild->left = n;

    if(n->parent == NULL){
        root = rightChild;
        rightChild->parent = n->parent;
    } else {
        rightChild->parent = n->parent;
        if(rightChild->parent->right == n){
            rightChild->parent->right = rightChild;
        } else{
            rightChild->parent->left = rightChild;
        }
    }

    n->parent = rightChild;

    int leftHeight = 0;
    int rightHeight = 0;

    if(n->left != NULL){
        leftHeight = n->left->height;
    }
    if(n->right != NULL){
        rightHeight = n->right->height;
    }

    n->height = max(leftHeight, rightHeight) + 1;

    adjustHeights(n);
    return n;
}

/*
 * finds the balance of a node
 * parameters:
 * 		NodeT n - a tree
 * returns:
 * 		int - the tree's balance
 */
int BSTY::findBalance(NodeT *n){
    int leftHeight;
    int rightHeight;

    if(n->left == NULL){
        leftHeight = 0;
    } else {
        leftHeight = n->left->height;
    }

    if(n->right == NULL){
        rightHeight = 0;
    } else {
        rightHeight = n->right->height;
    }

	return leftHeight - rightHeight;
}



