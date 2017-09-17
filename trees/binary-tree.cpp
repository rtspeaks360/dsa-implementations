/*
* @Author: sherlock
* @Date:   2017-09-13 12:02:12
* @Last Modified by:   sherlock
* @Last Modified time: 2017-09-16 17:46:14
*/

#include <iostream>
#include <list>

using namespace std;

// structure defining the node for binary tree
struct BTNode {
	int data;
	struct BTNode *left;
	struct BTNode *right;
};

list<BTNode**> address_queue;

//Inserting a node in Binary Tree
void Insert(int data){
	BTNode* newNode = new BTNode();
	BTNode** temp = address_queue.back();
	address_queue.pop_back();
	*temp = newNode;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	address_queue.push_front(&(newNode->left));
	address_queue.push_front(&(newNode->right));
}

//Inorder Traversal of Binary Tree
void Inorder(BTNode* root){
	if(root == NULL) return;

	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

//main function
int main(){
	// head of the binary tree 
	BTNode* head = NULL;

	// queue for keeping track of address of new node.
	address_queue.push_front(&head);

	Insert(15);	
	Insert(10);	
	Insert(20);
	Insert(25);
	Insert(8);
	Insert(12);

	cout << "Values added in your Binary Tree.\n";
	cout << "Inorder Traversal of Binary Tree : ";

	Inorder(head);

	cin.get();
    return 0;
}