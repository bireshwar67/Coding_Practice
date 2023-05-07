// Template for tree problems
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


Node* lca(Node *root, Node* l, Node *r) {
    //add your code here
    Node *left, *right;
    if(!root){
        return root;
    }
    
    if(root == l || root == r) 
        return root;

    left = lca(root ->left, l, r);
    right = lca(root -> right ,l,r);
    
    if(left && right)
        return root;
    else 
        return (left ? left : right);
}


int main()
{
    Node *A = new Node(3);
    Node *B = new Node(5);
    // Let us create binary tree shown in above diagram
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = A;
    root->left->left = new Node(4);
    root->left->right = B;

    Node *lcaNode = lca(root, A, B);
    cout << lcaNode -> data <<"\n";

    return 0;
}