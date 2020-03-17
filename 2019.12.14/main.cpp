#include <bits/stdc++.h>

using namespace std;

void rwFile() {
    freopen("INP.inp", "r", stdin);
    freopen("OUT.out", "w", stdout);
}

/// DSA
namespace DSA {

void recursiveInsertionSort(int arr[], int n) {
    if (n <= 1) return;
    recursiveInsertionSort(arr, n - 1);
    int last = arr[n - 1];
    int pos = n - 2;
    while (pos >= 0 && arr[pos] > last) {
        arr[pos + 1] = arr[pos];
        pos--;
    }
    arr[pos + 1] = last;
}

void insertionSort(int arr[], int start, int end){
    if (end + 1 <= 1) return;
    insertionSort(arr, start,  end - 1);
    int last = arr[end];
    int pos = end - 1;
    while (pos >= 0 && arr[pos] > last) {
        arr[pos + 1] = arr[pos];
        pos--;
    }
    arr[pos + 1] = last;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';
}

void recursiveSelectionSort(int arr[], int start, int end) {
    if (start >= end) return;
    int val = arr[start];
    int pos = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < val) {
            val = arr[i];
            pos = i;
        }
    }
    swap(arr[pos], arr[start]);
    recursiveSelectionSort(arr, start + 1, end);
}

const int MAXN = 1e5;
vector<int> adj[MAXN];
int check[MAXN];

void DFSVisit() {

}

} /// end DSA

/// Search
namespace Search {

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int check[MAXN];

void DFSVisit(int s) {
    check[s] = 1;
    for (int i : adj[s]) {
        if (check[i] == 0) {
            DFSVisit(i);
        }
    }
    cout << s << ' ';
}

void DFS(int v) {
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= v; i++) {
        if (check[i] == 0) {
            DFSVisit(i);
        }
    }
    cout << '\n';
}

void BFSVisit(int s) {
    memset(check, 0, sizeof(check));
    queue<int> Q;
    Q.push(s);
    check[s] = 1;
    while (!Q.empty()) {
        int u = Q.front();
        cout << u << ' ';
        Q.pop();
        for (int i : adj[u]) {
            if (check[i] == 0) {
                check[i] = 1;
                Q.push(i);
            }
        }
    }
}

void BFS(int v) {
memset(check, 0, sizeof(check));
    for (int i = 1; i <= v; i++) {
        if (check[i] == 0) BFSVisit(i);
    }
    cout << '\n';
}

} /// end Search

/// DGraph
namespace DGraph {

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int check[MAXN];

bool DFSVisit(int s) {
    check[s] = 1;
    for (int i : adj[s]) {
        if (check[i] == 1) return true;
        if (check[i] == 0 && DFSVisit(i)) {
            return true;
        }
    }
    check[s] = 2;
    return false;
}

bool isCyclic(int v) {
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= v; i++) {
        if (DFSVisit(i)) return true;
    }
    return false;
}

} /// end DGraph

/// DAG
namespace DAG {

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int check[MAXN];
int inDegree[MAXN];

void recursiveTopo(vector<int> res, int v) {
    bool done = false;
    for (int i = 1; i <= v; i++) {
        if (inDegree[i] == 0 && check[i] == 0) {
            res.push_back(i);
            check[i] = 1;
            for (int j : adj[i]) inDegree[j]--;
            recursiveTopo(res, v);

            check[i] = 0;
            res.erase(res.end() - 1);
            for (int j : adj[i]) inDegree[j]++;
            done = true;
        }
    }
    if (!done) {
        for (int i : res) cout << i << ' ';
        cout << '\n';
    }
}

void TopologicalOrder(int v) {
    memset(check, 0, sizeof(check));
    vector<int> res;
    recursiveTopo(res, v);
}

} /// end DAG

/// Sort
namespace Sort {

void printArray(int arr[], int n) {
    for (int i =0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';
}

void insertionSort(int arr[], int n) {
    if (n <= 1) return;
    int pos = 1;
    while (pos < n) {
        int tmp = arr[pos];
        int walker = pos - 1;
        while (tmp < arr[walker]) {
            arr[walker + 1] = arr[walker];
            walker--;
        }
        arr[walker + 1] = tmp;
        pos++;
    }
}

void selectionSort(int arr[], int n) {
    if (n <= 1) return;
    int start = 0;
    while (start < n - 1) {
        int tmp = arr[start];
        int pos = start;
        for (int i = start + 1; i < n; i++) {
            if (arr[i] < tmp) {
                pos = i;
                tmp = arr[i];
            }
        }
        swap(arr[pos], arr[start]);
        start++;
    }
}

void Merge(int arr[], int l, int r) {
    int tmp[r - l + 1];
    int pos = 0;
    int mid = (l + r) / 2;
    int i = l, j = mid + 1;
    while (pos <= r - l && i <= mid && j <= r) {
        if (arr[j] < arr[i]) {
            tmp[pos] = arr[j];
            j++;
        }
        else {
            tmp[pos] = arr[i];
            i++;
        }
        pos++;
    }
    while (i <= mid) {
        tmp[pos++] = arr[i++];
    }
    while (j <= r) {
        tmp[pos++] = arr[j++];
    }
    for (int x = 0; x <= r - l; x++) {
        arr[l + x] = tmp[x];
    }
}

void recursiveMergeSort(int arr[], int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    recursiveMergeSort(arr, l, mid);
    recursiveMergeSort(arr, mid + 1, r);
    Merge(arr, l, r);
}

void mergeSort(int arr[], int n) {
    recursiveMergeSort(arr, 0, n - 1);
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int pos = n - 1;
        int start = 0;
        while (pos > start) {
            if (arr[pos] < arr[pos - 1]) {
                swap(arr[pos], arr[pos - 1]);
            }
            pos--;
        }
        start++;
    }
}

void bubbleSort2(int a[], int n) {
    bool swapped;
    do {
        swapped = false;
        for(int i = 1; i < n; ++i){
            if (a[i-1] > a[i]){
                swap(a[i], a[i - 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int pos = l;
    for (int j = l; j < r; j++) {
        if (arr[j] < pivot) {
            swap(arr[pos++], arr[j]);
        }
    }
    swap(arr[pos], arr[r]);
    return pos;
}

void recursiveQuickSort(int arr[], int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    recursiveQuickSort(arr, l, p - 1);
    recursiveQuickSort(arr, p + 1, r);
}

void quickSort(int arr[], int n) {
    recursiveQuickSort(arr, 0, n - 1);
}

void heapDown(int arr[], int i, int n) {
    if (i * 2 > n) return;
    int pos = i * 2;
    if (pos + 1 <= n) {
        if (arr[pos] < arr[pos + 1]) pos++;
    }
    if (arr[i] < arr[pos]) {
        swap(arr[i], arr[pos]);
        heapDown(arr, pos, n);
    }
}

void heapSort(int arr[], int n) {
    int pos = (n - 1) / 2;
    while (pos >= 0) {
        heapDown(arr, pos, n - 1);
        pos--;
    }
    pos = n - 1;
    while (pos > 0) {
        swap(arr[0], arr[pos--]);
        heapDown(arr, 0, pos);
    }
}

} /// end Sort

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    rwFile();
    //int n; cin >> n;
    //int arr[n];
    //for (int i = 0; i < n; i++) cin >> arr[i];
    //DSA::recursiveInsertionSort(arr, n);
    //DSA::insertionSort(arr, 0, n - 1);
    //DSA::recursiveSelectionSort(arr, 0, n - 1);
    //DSA::printArray(arr, n);
    /*
    int v, e; cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int u, v; cin >> u >> v;
        Search::adj[u].push_back(v);
        Search::adj[v].push_back(u);
    }
    Search::DFS(v);
    Search::BFS(v);
    */
    /*
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int u, v; cin >> u >> v;
        DGraph::adj[u].push_back(v);
    }
    cout << DGraph::isCyclic(v);
    */
    /*
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int u, v; cin >> u >> v;
        DAG::adj[u].push_back(v);
        DAG::inDegree[v]++;
    }
    DAG::TopologicalOrder(v);
    */
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    //Sort::insertionSort(arr, n);
    //Sort::selectionSort(arr, n);
    //Sort::mergeSort(arr, n);
    //Sort::bubbleSort2(arr, n);
    //Sort::quickSort(arr, n);
    Sort::heapSort(arr, n);
    Sort::printArray(arr, n);
}




