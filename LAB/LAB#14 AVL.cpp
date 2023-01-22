#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};
//Function to calculate height 
int height(Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}
//Function to calculate max 
int max(int a, int b){
    return (a > b)? a : b;
}

//Function to New Node
Node* newNode(int key){
    Node* node = new Node();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}
 

Node *rightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    return x;
}

Node *leftRotate(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    return y;
}

int getBalance(Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key){
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;
 
    node->height = 1 + max(height(node->left),
                        height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
 
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
 
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node *root){
    if(root != NULL)
    {
        
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}


Node * minValueNode(Node* node) { 
    Node* current = node; 
 
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

Node* deleteNode(Node* root, int key) {  
    if (root == NULL) 
        return root; 
 
    if ( key < root->data ) 
        root->left = deleteNode(root->left, key); 

    else if( key > root->data ) 
        root->right = deleteNode(root->right, key); 
  
    else
    {  
        if( (root->left == NULL) ||
            (root->right == NULL) ) 
        { 
            Node *temp = root->left ? 
                         root->left : 
                         root->right; 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else  
            *root = *temp; 
            free(temp); 
        } 
        else
        {  
            Node* temp = minValueNode(root->right); 
            root->data = temp->data; 
   
            root->right = deleteNode(root->right, 
                                     temp->data); 
        } 
    } 
  
 
    if (root == NULL) 
    return root; 
 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
 
    int balance = getBalance(root); 

    if (balance > 1 && 
        getBalance(root->left) >= 0) 
        return rightRotate(root); 
   
    if (balance > 1 && 
        getBalance(root->left) < 0) 
    { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 
 
    if (balance < -1 && 
        getBalance(root->right) <= 0) 
        return leftRotate(root); 

    if (balance < -1 && 
        getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
} 


int main(){
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 47);
    root = insert(root, 45);
    root = insert(root, 60);
    root = insert(root, 40);
    root = insert(root, 39);
    root = insert(root, 66);
    cout << "INORDER TRAVERSAL\n\n";
	inOrder(root);
	root = deleteNode(root,60);
    cout << "\n After deletion...\n";
    inOrder(root);
    root = insert(root, 100); cout << endl;
    inOrder(root);
    root = deleteNode(root,40); cout << endl;
    inOrder(root);
    root = insert(root, 77); cout << endl;
    inOrder(root);
     
    return 0;
}
