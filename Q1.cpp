#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {

        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    int c = A[low];
    A[low] = A[j];
    A[j] = c;
    return j;
}

void QuickSort(int A[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        QuickSort(A, low, partitionIndex - 1);
        QuickSort(A, partitionIndex + 1, high);
    }
}

int ShellSort(int a[], int n)
{

    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)
                a[j] = a[j - interval];

            a[j] = temp;
        }
    }
    return 0;
}

struct Node
{
    int key;
    struct Node *left, *right;
};
struct Node *newNode(int item)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void storeSorted(struct Node *root, int a[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, a, i);
        a[i++] = root->key;
        storeSorted(root->right, a, i);
    }
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void TreeSort(int a[], int n)
{
    struct Node *root = NULL;
    root = insert(root, a[0]);
    for (int i = 1; i < n; i++)
        root = insert(root, a[i]);
    int i = 0;
    storeSorted(root, a, i);
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    cout<<("------------Welcome to the Sorting Implementation------------\n");
    cout<<("Press Y to begin or Press N to exit: ");
    while (true)
    {
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            cout<<("\nEnter your choice for sorting: \n1: Quick Sort\n2: Heap Sort\n3: Shell Sort\n4: Tree Sort\n");
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                int a[100];
                int n;
                cout<<"Enter the number of elements to be inserted in the array: ";
                cin>>n;
                cout<<"Enter the elements in the array: ";
                for(int i=0;i<n;i++){
                    cin>>a[i];
                }
                cout<<"Before sorting array elements are :- \n";
                printArray(a, n);
                cout<<"\nPerforming Quick Sort"<<endl;
                QuickSort(a, 0, n - 1);
                cout<<"\nAfter sorting array elements are :- \n";
                printArray(a, n);
                break;
            case 2:
                int b[100];
                int m;
                cout<<"Enter the number of elements to be inserted in the array: ";
                cin>>m;
                cout<<"Enter the elements in the array: ";
                for(int i=0;i<m;i++){
                    cin>>b[i];
                }
                cout<<"Before sorting array elements are :- \n";
                printArray(b, m);
                cout<<"\nPerforming Heap Sort"<<endl;
                HeapSort(b, m);
                cout<<"\nAfter sorting array elements are :- \n";
                printArray(b, m);
                break;

            case 3:
                int c[100];
                int o;
                cout<<"Enter the number of elements to be inserted in the array: ";
                cin>>o;
                cout<<"Enter the elements in the array: ";
                for(int i=0;i<o;i++){
                    cin>>c[i];
                }
                cout<<"Before sorting array elements are :- \n";
                printArray(c, o);
                cout<<"\nPerforming Shell Sort"<<endl;
                ShellSort(c, o);
                cout<<"\nAfter sorting array elements are :- \n";
                printArray(c, o);
                break;

            case 4:
                int d[100];
                int p;
                cout<<"Enter the number of elements to be inserted in the array: ";
                cin>>p;
                cout<<"Enter the elements in the array: ";
                for(int i=0;i<p;i++){
                    cin>>d[i];
                }
                cout<<"Before sorting array elements are :- \n";
                printArray(d, p);
                cout<<"\nPerforming Tree Sort"<<endl;
                TreeSort(d, p);
                cout<<"\nAfter sorting array elements are :- \n";
                printArray(d, p);
                break;

            default:
                cout<<"Invalid Input!!!"<<endl;
                break;
            }
            cout<<"Do you wish to continue? Press Y for yes or N for no: ";
        }
        else{
            cout<<"Exiting...."<<endl;
            break;
        }
    }
    return 0;
}