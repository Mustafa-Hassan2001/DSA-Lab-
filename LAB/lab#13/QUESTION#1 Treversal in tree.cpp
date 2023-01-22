#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* newNode(int data){
	Node *temp = new Node();
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}
Node* insert(Node* root, int data){
	if(root == NULL){
		root = newNode(data); 
	}
	else if(data < root->data)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);
	return root;
}


 
void inorder(Node* root){
        if(root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
}

void preorder(Node* root){
        if(root == NULL)
            return;
            
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
}

void postorder(Node* root){
        if(root == NULL)
            return;
            
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
}

Node* search( Node* root, int key){
    if (root == NULL || root->data == key)
       return root;
    
    if (root->data < key)
       return search(root->right, key);
  return search(root->left, key);
}


Node* deletenode(Node* root, int k) { 
        if (root == NULL) 
            return root; 
        if(root->data > k){ 
            root->left = deletenode(root->left, k); 
            return root; 
        } 
        else if(root->data < k){ 
            root->right = deletenode(root->right, k); 
            return root; 
        } 
  

        if (root->left == NULL) { 
            Node* temp = root->right;
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
}
else {
          Node* Parent = root;
          Node *succ = root->right; 
          while (succ->left != NULL) { 
              Parent = succ; 
              succ = succ->left; 
          } 

          if (Parent != root) 
              Parent->left = succ->right; 
          else
              Parent->right = succ->right; 

          root->data = succ->data; 

          delete succ;          
          return root; 
      } 
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
	cout<<endl;
	cout<<"POST-ORDER : "<<endl;
	postorder(root);
	cout<<endl;
	cout<<"PER-ORDER : "<<endl;
	preorder(root);
	cout<<endl;
	cout<<"IN-ORDER : "<<endl;
	inorder(root);
	int key;
	cout<<"\nEnter the element which you want to delete : "<<endl;
	cin>>key;
	deletenode(root, key);
	preorder(root);
}

