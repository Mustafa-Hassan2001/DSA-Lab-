#include<iostream>
using namespace std;

//lEFT & RIGHT NOTATION

struct Node{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

Node* newNode(int key){
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 
	return(node);
}

Node* insert(Node* root, int data){
	if(root == NULL){
		root = newNode(data); 
	}
	else if(data < root->key)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);
	return root;
}


int height(Node *N){		//to find the height to get Balancefactor
	if (N == NULL)
		return 0;
	return N->height;
}

int getBalance(Node *N){		//Balancefactor
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

int max(int a, int b){
	return (a > b)? a : b;
}


Node *rightRotate(Node *y){
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),height(y->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;


	return x;
}

Node *leftRotate(Node *x){
	Node *y = x->right;
	Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	return y;
}

void preOrder(Node *root){
	if(root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postorder(Node* root){
        if(root == NULL)
            return;
            
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
}

int main(){
	int num,val;
	Node *root=NULL;
	cout<<"Enter the no. of values to be insert:";
	cin>>num;
	for(int i=0;i<num;i++){
	cout<<"Enter the value: ";
		cin>>val;
		root = insert(root,val); 
	}
	cout<<"\nAfter Apply Left AVL : "<<endl;
//	rightRotate(root);
	preOrder(root);
	
	cout<<"\nAfter Apply Left AVL : "<<endl;
//	leftRotate(root);
	postorder(root);
	
	return 0;
}
