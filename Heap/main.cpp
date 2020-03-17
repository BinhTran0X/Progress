#include <iostream>
#include <math.h>
using namespace std;

//question1
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

int main()
{
	int size;
	cout << "Input the number of elements in array: "; cin >> size;
	int *maxHeap = new int[size];
	for (int i = 0; i < size; i++)
	{
		maxHeap[i] = i;
	}
	cout << "The heaptree before build: " << endl;
	printArr(maxHeap, size);
	printHeapTree(maxHeap, size);
	cout << "The heaptree after build: " << endl;
	buildHeap(maxHeap, size);
	printArr(maxHeap, size);
	printHeapTree(maxHeap, size);

	system("pause");
	return 0;
}
