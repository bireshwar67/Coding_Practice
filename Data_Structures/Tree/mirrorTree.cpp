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


Node* mirrorOfBT(Node* root){
    if(root){
        mirrorOfBT(root ->left);
        mirrorOfBT(root -> right);
        swap(root -> left, root -> right);
    }
    return root;
}
 void inOrderForMirror(Node* root){
    if ( root == NULL)
	return;
	inOrderForMirror(root->left);
    cout << root->data << " ";
	inOrderForMirror(root->right);
	
 }

//Checking if the Given tree is mirror to the Mirror tree created.
bool actuallyMirrorOrNot(Node *root1, Node *root2){
    if(root1 == NULL && root2 == NULL)  return true;
    if(root1 == NULL || root2 == NULL)  return false;
    if(root1-> data != root2->data){
        return false;
    }
    else 
    return (actuallyMirrorOrNot(root1->left, root2->right) && actuallyMirrorOrNot(root1-> right, root2->left));
} 
Node* getTree(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}
int main()
{
    // Let us create binary tree shown in above diagram
        //
//
    Node *root = getTree();
    // cout << "This is the Given Tree in In-Order : " ;
    // inOrderForMirror(root);
    // cout << endl;


    mirrorOfBT(root);
    Node *mirrorNode = mirrorOfBT(root);
    // cout << "The mirror of the BT provided in In-Order : ";
    // inOrderForMirror(mirrorOfBT(root));
    // cout<< endl;

    cout<< "Now checking if the Tree are actually mirror or NOt : " << endl ;
//    actuallyMirrorOrNot(mirrorOfBT(root), getTree);
    cout<< actuallyMirrorOrNot(mirrorOfBT(root), getTree());

    return 0;
}