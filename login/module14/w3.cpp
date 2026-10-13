#include<iostream>
#include<vector>
using namespace std;

int A[100];
int heap_size = 10;

int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}

int parent(int i){
    return i/2;
}

void heapify(int i){

    int large;
    int l = left(i);
    int r = right(i);

    if (l <= heap_size && A[l] > A[i])
    {
        large = l;
    }else{
        large = i;
    }

    if (r <= heap_size && A[r] > A[large])
    {
        large = r;
    }

    if (large != i)
    {
        int tmp = A[i];
        A[i] = A[large];
        A[large] = tmp;
        heapify(large);
    }
    
}

void buid_heap(){

    for (int i = heap_size/2; i >= 1; i--)
    {
        heapify(i);
    }
    
}

void print_heap(){

    for (int i = 1; i <= heap_size; i++)
    {
        cout << A[i] << " ";
    }
    
}

void insertQ(){

    int val;

    cout << "Input : ";

    cin >> val;
    heap_size++;

    int i = heap_size;
    while (i > 1 && A[parent(i)] < val)
    {
        A[i] = A[parent(i)];
        i = parent(i);
    }

    A[i] = val;

    cout << "Heap : "; 
    print_heap();
    
}

void service(){

    if (heap_size < 1)
    {
        cout << "Heap is empty!\n";
        return;
    }

    int max_value = A[1];
    cout << "Service : " << max_value << "\n";

    A[1] = A[heap_size];
    heap_size--;
    heapify(1);

    cout << "Heap : "; 
    print_heap();
}

int main(){
    int choice;
    
    do {
        cout << "=========================\n";
        cout << "          MENU           \n";
        cout << "=========================\n";
        cout << "1. Input Array\n";
        cout << "2. Print Heap\n";
        cout << "3. Insert Queue\n";
        cout << "4. Service\n";
        cout << "5. Exit\n";
        cout << "Please choose > ";
        cin >> choice;

        if (choice == 1) {
            cout << "Input Array : ";
            heap_size = 10;
            for (int i = 1; i <= heap_size; i++) {
                cin >> A[i];
            }
            buid_heap(); 
        } 
        else if (choice == 2) {
            cout << "Heap : ";
            print_heap();
        } 
        else if (choice == 3) {
            insertQ();
        } 
        else if (choice == 4) {
            service();
        }
        
    } while (choice != 5);

    return 0;
}