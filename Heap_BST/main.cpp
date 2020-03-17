#include <iostream>
#include <math.h>
using namespace std;

//create binary search tree for question 2
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node() : data(0), left(NULL), right(NULL) {}
	Node(int d) : data(d), left(NULL), right(NULL) {}
};
class BSTree
{
private:
    Node * head;
	int size;
public:
	BSTree() { head = NULL; size = 0; }
	~BSTree() {}
	Node *& gethead() { return head; }
	int getsize() { return size; }
	void insert(int data)
	{
		insertNode(head, data);
		size++;
	}
	void remove(int data)
	{
		deleteNode(head, data);
		size--;
	}
	bool deleteNode(Node* &p, int d);
	bool insertNode(Node* &p, int d);
	void printLNR()
	{
		printLNR(head);
		cout << endl;
	}
	void printLNR(Node* p);
};
bool BSTree::insertNode(Node* &p, int d)
{
	if (p == NULL) {
		p = new Node(d);
		return true;
	}
	else if (d < p->data) return insertNode(p->left, d);
	else return insertNode(p->right, d);
}
bool BSTree::deleteNode(Node* &p, int d)
{
	if (p == NULL) return false;
	if (p->data == d) {
		if (p->left == NULL) {
			if (p->right == NULL) { delete p, p = NULL; }
			else { Node * pPre = p; p = p->right; delete pPre; }
		}
		else {
			if (p->right == NULL) {
				Node * pPre = p; p = p->left; delete pPre;
			}
			else {
				Node * pPre = p; pPre = pPre->right;
				while (pPre->left != NULL) { pPre = pPre->left; }
				p->data = pPre->data;
				return deleteNode(p->right, pPre->data);
				return true;
			}
		}
	}
	else if (p->data > d) return deleteNode(p->left, d);
	else return deleteNode(p->right, d);
}
void BSTree::printLNR(Node * p)
{
	if (p == NULL) return;
	if (p->left != NULL) {
		cout << "(";
		printLNR(p->left);
		cout << ")";
	}
	cout << p->data;
	if (p->right != NULL) {
		cout << "(";
		printLNR(p->right);
		cout << ")";
	}
}

//some function for print heap to tree
void print_(int size)
{
	for (int i = 1; i <= size; i++) cout << "---";
}
void printspace(int size)
{
	for (int i = 1; i <= size; i++) cout << "   ";
}
int getHeight(int size)
{
	return (int)log2(size) + 1;
}
void printArr(int * pD, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << pD[i] << " ";
	}
	cout << endl;
}

//heapup and heapdown for maxheap (buildmaxheap)
//Copy tu question 1
void HeapUp(int * pD, int N, int i)
{
	//TODO
	if (pD[i] > pD[i / 2]) {
        swap(pD[i], pD[i / 2]);
        HeapUp(pD, N, i / 2);
	}
}
void HeapDown(int * pD, int N, int i)
{
	//TODO
	if (i * 2 > N) return;
	int pos = i * 2;
	if (pos + 1 <= N) {
        if (pD[pos + 1] > pD[pos]) pos++;
	}
	if (pD[pos] > pD[i]) {
        swap(pD[pos], pD[i]);
        HeapDown(pD, N, pos);
	}
}
void buildHeap(int * pD, int size)
{
	//TODO
	for (int i = 0; i < size; i++) {
        HeapUp(pD, size, i);
	}
}
void printHeapTree(int * list, int size)
{
	//TODO
	buildHeap(list, size);
	for (int i = 0; i < size; i++) {
        cout << list[i] << "  ";
        if (pow(2, (int)log2(i + 2)) == i + 2) cout << '\n';
	}
}

//question 2
void BSTtomheap(Node * root, int * arr, int & idx) //co the thay doi protocol
{
	//TODO Vi du, co the tu thay doi theo tuy y ban than
	if (root == NULL) return;
	BSTtomheap(root->left, arr, idx);
	BSTtomheap(root->right, arr, idx);
	arr[idx++] = root->data;
}

int *&conBSTtoHeap(BSTree* &p)
{
	//TODO
	int *mHeap = new int[p->getsize()];
	int len = 0;
	BSTtomheap(p->gethead(), mHeap, len);
	return mHeap;
}
int main()
{
	BSTree * bst = new BSTree();
	bst->insert(473);
	bst->insert(309);
	bst->insert(286);
	bst->insert(598);
	bst->insert(438);
	bst->insert(663);
	bst->insert(948);
	bst->insert(424);
	cout << endl;
	cout << endl;
	cout << "BSTree (left node right): ";
	bst->printLNR();
	int * Maxheap = conBSTtoHeap(bst);
	int Maxsize = bst->getsize();
	cout << "Maxheap converted from BST: " << endl;
	printHeapTree(Maxheap, Maxsize);

	system("pause");
	return 0;
}
