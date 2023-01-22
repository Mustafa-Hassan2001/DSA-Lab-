#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int val){
	Node *temp = new Node();
	temp->data = val;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

Node* insert(Node* root, int val){
	if(root == NULL){
		root = newNode(val); 
	}
	else if(val < root->data)
		root->left = insert(root->left,val);
	else
		root->right = insert(root->right,val);
	return root;	
}
void display(Node* root){
//	if(root==NULL){
//		cout<<"Tree is Empty"<<endl;
//	}
	
	if(root!=NULL){
		display(root->left);
		cout<<root->data<<"  ";
		display(root->right);
	}
}

bool search(Node* root,int item){
	if(root==NULL)
		return false;
	if(item == root->data){
			return true;
	}
	else if(item < root->data){
		search(root->left,item);		
	}
	else if(item > root->data){
		search(root->right,item);
	}
	else
	return false;
}

int main(){
	int n,item;
	Node *root = NULL;
	
	cout<<"Enter the  no of elements: ";
	cin>>n;
	
	cout<<"Enter the datas to insert: ";
	for(int i=0;i<n;i++){
		cin>>item;
		root = insert(root,item); 
	}
	
	cout<<"Tree Is Created : ";
	display(root);
	
	cout<<"\nEnter the  item to find (Enter -1 to exit searching)\n";
	do{
		cin>>item;
		if(search(root,item))
			cout<<"Found..\n";
		else
			cout<<"Not Found!\n";
	}
	while(item!=0);
	
	return 0;
}
