/*
* @Author: sherlock
* @Date:   2017-09-17 05:28:28
* @Last Modified by:   sherlock
* @Last Modified time: 2017-09-17 05:48:36
*/

#include <iostream>
#include <list>

using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}


//Function to visit nodes in Inorder
void Inorder(BstNode *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	cout << root->data << " ";  //Print data
	Inorder(root->right);      // Visit right subtree
}


//Level order traversal
void LevelOrderTraversal(BstNode* root){
	list<BstNode**> address_queue;
	address_queue.push_back(&root);

	while(address_queue.empty() != 1){
		BstNode** temp = address_queue.front();
		address_queue.pop_front();
		cout << ((*temp)->data) << " ";
		if((*temp)->left != NULL){
			address_queue.push_back(&((*temp)->left));
		}
		if((*temp)->right != NULL){
			address_queue.push_back(&((*temp)->right));
		}
	}
}

int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	
	//Inorder Traversal
	cout << "Inorder traversal of tree : ";	
	Inorder(root);
	cout << endl;

	//Level order Traversal
	cout << "Level order traversal of tree : ";
	LevelOrderTraversal(root);
	cout << endl;
	
	//get character
	cin.get();	
}