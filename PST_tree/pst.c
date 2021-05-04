#include <stdio.h>
#include <stdlib.h>
typedef int Data;
typedef struct _Node {
	Data data;
	struct _Node* left;
	struct _Node* right;
}Node;

Node* MakeNode(void);
Data GetData(Node* node);
void SetData(Node* node, Data data);

Node* GetLeftSubTree(Node* node);
Node* GetRightSubTree(Node* node);

void MakeLeftSubTree(Node* parent, Node* child);
void MakeRightSubTree(Node* parent, Node* child);

void	BSTMakeAndInit(Node** pNode);
Data	BSTGetData(Node* node);
void	BSTInsert(Node** pNode, Data data);
Node*	BSTSearch(Node* node, Data key);


void ShowCharData(Data data) {
	printf("[%c]\n", data);
}

void ShowIntData(Data data) {
	printf("[%d]\n", data);
}

void Inorder(Node* node, void (* action)(Data data)){
	if (node == NULL)
		return;
	
	Inorder(node->left,action);
	action(node->data);
	Inorder(node->right,action);
}

void Preorder(Node* node, void (* action)(Data data)) {
	if (node == NULL)
		return;
	
	action(node->data);
	Preorder(node->left, action);
	Preorder(node->right, action);
}

void Postorder(Node* node, void(*action)(Data data)) {
	if (node == NULL)
		return;
	Postorder(node->left, action);
	Postorder(node->right, action);
	action(node->data);
}

Node* MakeNode(void) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}

Data GetData(Node* node) {
	return node->data;
}

void SetData(Node* node, Data data) {
	node->data = data;
}

Node* GetLeftSubTree(Node* node) {
	return node->left;
}

Node* GetRightSubTree(Node* node) {
	return node->right;
}

void MakeLeftSubTree(Node* parent, Node* child) {
	parent->left = child;
}

void MakeRightSubTree(Node* parent, Node* child) {
	parent->right = child;
}

void BSTMakeAndInit(Node** pNode) {
	*pNode = NULL;
}

void BSTInsert(Node** pNode, Data data) {
	Node* parent_node = NULL;
	Node* current_node = *pNode;
	Node* new_node = NULL;

	while (current_node != NULL) {
		if (data == GetData(current_node))
			return;

		parent_node = current_node;
		if (GetData(current_node) > data)
			current_node = GetLeftSubTree(current_node);
		else
			current_node = GetRightSubTree(current_node);
	}

	new_node = MakeNode();
	SetData(new_node, data);

	if (parent_node != NULL) {
		if (GetData(parent_node) > data)
			MakeLeftSubTree(parent_node, new_node);
		else
			MakeRightSubTree(parent_node, new_node);
	}
	else
	{
		*pNode = new_node;
	}
}

Node* BSTSearch(Node* node, Data key) {
	Node* current_node = node;
	Data current_data;

	while (current_node != NULL) {
		current_data = GetData(current_node);
		if (key == current_data)
			return current_node;
		else if (GetData(current_node) > key) {
			current_node = GetLeftSubTree(current_node);
		}
		else {
			current_node = GetRightSubTree(current_node);
		}
	}

	return NULL;
}

int main() {
	Node* root;
	Node* sNode;

	BSTMakeAndInit(&root);

	BSTInsert(&root, 9);
	BSTInsert(&root, 1);
	BSTInsert(&root, 6);
	BSTInsert(&root, 2);
	BSTInsert(&root, 8);
	BSTInsert(&root, 3);
	BSTInsert(&root, 5);
	BSTInsert(&root, 4);
	BSTInsert(&root, 7);

	sNode = BSTSearch(root, 1);
	if (sNode == NULL)
		printf("없어\n");
	else
		printf("있어: %d\n", sNode->data);

	sNode = BSTSearch(root, 11);
	if (sNode == NULL)
		printf("없어\n");
	else
		printf("있어: %d\n", sNode->data);

	sNode = BSTSearch(root, 4);
	if (sNode == NULL)
		printf("없어\n");
	else
		printf("있어: %d\n", sNode->data);
	Inorder(root, ShowIntData);
	Preorder(root, ShowIntData);
	Postorder(root, ShowIntData);
}