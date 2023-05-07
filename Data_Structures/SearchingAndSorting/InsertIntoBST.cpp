#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

 Node* insertIntoBST(Node* root, int val) {
        if(!root){
        root = new Node(val);
            if(root == NULL){
                return NULL;
            }
            else{
                root-> data = val;
                root->left = root->right = NULL;
            }
        }
        else{
            if(val < root-> data){
                root-> left = insertIntoBST(root->left, val);
            }
            else if(val > root-> data){
                root-> right = insertIntoBST(root->right, val);
            }
        }
    return root;
    }

void InOrder(Node* root){
    if ( root == NULL)
	return;
    InOrder(root->left);
	cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    // My given tree
    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(6);

    //Printing the given tree.
    cout<< "Present Binary Search Tree InOrder : " << endl;
    InOrder(root) ;
    cout<< endl; 

    //passing variable to the given insert function and printing
    int val = 8;
    auto temp = insertIntoBST(root, val);
    cout << "After Inserting a node The BST in In Order : \n" ;
    InOrder(temp);
    cout << endl;
    return 0;
}