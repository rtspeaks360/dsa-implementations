/*
* @Author: Rishabh Thukral
* @Date:   2017-09-17 09:51:35
* @Last Modified by:   Rishabh Thukral
* @Last Modified time: 2017-09-17 10:25:25
*/

#include <iostream>

using namespace std;

struct BTNode {
	int data;
	BTNode *left;
	BTNode *right;
};

BTNode* get_new_node(int data){
	BTNode* temp = new BTNode();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int max(int a, int b){
	return a>b?a:b;
}

int height(BTNode* root){
	if(root == NULL){
		return 0;
	}
	return 1+max(height(root->left), height(root->right));
}

int diameter(BTNode* root){
	if(root == NULL){
		return 0;
	}
	int lDiameter = diameter(root->left);
	int rDiameter = diameter(root->right);
	int lHeight = height(root->left);
	int rHeight = height(root->right);

	return max(1+lHeight+rHeight, max(lDiameter, rDiameter));
}

int main(){
	//Head initialization of Binary Tree
	BTNode* root = NULL;

	//Data population into the Binary Tree
	root = get_new_node(5);
	root->left = get_new_node(2);
	root->right = get_new_node(3);
	root->left->left = get_new_node(1);
	root->left->right = get_new_node(6);
	root->left->right->left = get_new_node(43);
	root->left->right->right = get_new_node(27);
	root->right->right = get_new_node(7);
	root->right->right->right = get_new_node(24);
	root->right->right->right->left = get_new_node(21);
	root->right->right->right->right = get_new_node(17);
	root->right->right->right->left->left = get_new_node(11);
	root->right->right->right->left->right = get_new_node(12);

	cout << "Data has been populated into the tree\n";

	int diameter_tree = diameter(root);
	cout << "Diameter/Width of the tree is " << diameter_tree;
    return 0;
}