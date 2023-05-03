#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

Node *insert(Node *root, int key)
{
    if (root == nullptr)
        return newNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

void inorderTraversal(Node *root, int arr[], int &index)
{
    if (root == nullptr)
        return;
    inorderTraversal(root->left, arr, index);
    arr[index++] = root->key;
    inorderTraversal(root->right, arr, index);
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 5);

    int n = 6;
    int arr[n];
    int index = 0;

    inorderTraversal(root, arr, index);
    heapSort(arr, n);
    cout << "Sorted array is: \n";
    printArray(arr, n);
    return 0;
}