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

Node* insertInBinaryTree(Node* root, int key){
    //Check if nothing is present in the tree then insert the key element into the tree;
    if(root == NULL){
        root = new Node(key);
        return root;
    }
    queue <Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp-> left != NULL){
            q.push(temp-> left);
        }
        else{
            temp-> left = new Node(key);
            return root;
        }
        if(temp-> right != NULL){
            q.push(temp-> right);
        }
        else{
            temp-> right = new Node(key);
            return root;
        }

    }
    return root;
}

void preOrder(Node* root){
    if ( root == NULL)
	return;
    cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main()
{
    // My given tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    //Printing the given tree.
    cout<< "Present Tree pre InOrder : " << endl;
    preOrder(root) ;
    cout<< endl; 

    //passing variable to the given insert function and printing
    int key = 8;
    auto temp = insertInBinaryTree(root, key);
    cout << "After Inserting a node The tree in Pre Order : \n" ;
    preOrder(temp);
    cout << endl;
    return 0;
}