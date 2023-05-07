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


bool searchInBT(Node *root, int n) {
    if(!root){
        return false;
    }
    if(n == root->data){
        return true;
    }
    else{       //implementing pre-order traversal ;
        int temp = searchInBT(root->left, n);
        if(temp !=0){
            return temp;
        }
        else{
            return (searchInBT(root->right,n));
        }
    }
    return false;
}


int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int n;
    cout <<"Enter the element to be search : ";
    cin >> n;
    cout << searchInBT(root, n);
    
    return 0;
}