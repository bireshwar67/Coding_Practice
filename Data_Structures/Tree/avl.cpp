#include<bits/stdc++.h>
using namespace std;
/***
 * @written by : rahul.dhiman365@gmail.com
 */
class Node{
    public:
        int data;
        int height;//height of the node
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            height = 0;
            left = right = NULL;
        }
};

int Height(Node *root){
    if(!root)
        return 0;
    return root->height;
}

/*Insertion of node in the left subtree of the left child of x*/
Node *rotateleft(Node *x){
    Node *w = x->left;
    x->left = w->right;
    w->right = x;
    x->height = max(Height(x->left),Height(x->right)) + 1;
    w->height = max(Height(w->left),x->height) + 1;
    return w;
}

/*Insertion of node in the right substree of the right child of x*/
Node *rotateright(Node *x)
{
    Node *w  = x->right;
    x->right = w->left;
    w->left = x; 
    x->height = max(Height(x->left),Height(x->right)) + 1;
    w->height = max(x->height,Height(w->right)) + 1;
    return w;
}
/*Insertion of node in the right subtree of the left child of z*/
Node *doublerotateleft(Node *z){
    z->left = rotateright(z->left);
    return rotateleft(z);
}

/*Insertion of node in the left substree of the right child of z*/
Node *doublerotateright(Node *z){
    z->right = rotateleft(z->right);
    return rotateright(z);
}

Node *insert(Node *root,int data){
    if(!root){
        root = new Node(data);
    }
    else if(root->data > data){
        root->left = insert(root->left,data);
        if(Height(root->left) - Height(root->right) == 2){
            if(root->left->data >= data)
            {
                root = rotateleft(root);
            }
            else{
                root = doublerotateleft(root);
            }
        }
    }
    else if(root->data < data){
        root->right = insert(root->right,data);
        if(Height(root->right) - Height(root->left) == 2){
            if(root->right->data <= data){
                root = rotateright(root);
            }
            else{
                root = doublerotateright(root);
            }
        }
    }
    root->height = max(Height(root->left),Height(root->right)) + 1;
    return root;
}

bool inorder(Node *root, int &x){
    if(!root) return true;
        
    if(!inorder(root->left, x)) {
        return false;
    }
    if(x > root->data)
       { return false;}
    x = root->data;
    //cout<<root->data<<" ";
    return inorder(root->right, x);
}

int main(){
    Node *root = NULL;
    int x = -1;
    vector<int> arr({850, 859, 912, 50, 218, 545, 815, 22, 903});
    for(int i = 0;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
    if(inorder(root, x)){
        cout << "Valid BST " << endl;
    }
    cout<<"\n";
    return 0;
}