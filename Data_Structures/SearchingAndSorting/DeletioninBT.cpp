//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
struct Node* deletionBT(struct Node* root, int key);
void inn(Node *node)
{
    if(node==NULL)
        return;
    
    inn(node->left);
    cout<<node->data<<" ";
    inn(node->right);
}

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k;
        scanf("%d ",&k);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		root=deletionBT(root,k);
		inn(root);
		cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
Structre of the node of the tree is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// you are required to complete this functionN

struct Node* searchInBinaryTree(struct Node* root, int key){
    if(!root)
      return NULL;
      
     if(root->data==key)
        return root;
        
      struct Node* inLeft = searchInBinaryTree(root->left,key);
      if(inLeft)
        return inLeft;
      struct Node* inRight = searchInBinaryTree(root->right,key);
      return inRight;
      
}

struct retNode{
    Node* node;
    Node* parent;
    int depth;
};

 struct retNode* getmeBottomRight(struct Node* root, int depth, struct Node* parent){
         retNode* rootNode = new retNode;
         rootNode->node = root;
         rootNode->parent = parent;
         rootNode->depth = depth;
     if(root->right == NULL && root->left==NULL){
         return rootNode;
     }
     retNode* rNode = rootNode;
     retNode* lNode = rootNode;
     if(root->right){
     rNode = getmeBottomRight(root->right,depth+1,root);
     }
     if(root->left)
          lNode = getmeBottomRight(root->left,depth+1,root);
          
    if(rNode->depth>=lNode->depth){
        return rNode;
    }
    return lNode;
     
 }
struct Node* deletionBT(struct Node* root, int key)
{
    struct retNode* rNode = getmeBottomRight(root,0,NULL);
    if(rNode->parent == NULL)
    return NULL;
    struct Node* node = searchInBinaryTree(root,key);
    node->data = rNode->node->data;
    //cout<<"data "<<rNode->parent->data<<endl;
    if(rNode->parent->left==rNode->node){
        rNode->parent->left = NULL;
           // cout<<"data 5 "<<rNode->parent->data<<endl;

    }
    if(rNode->parent->right==rNode->node){
        rNode->parent->right = NULL;
            //cout<<"data 7"<<rNode->parent->data<<endl;

    }
    return root;
    
}
