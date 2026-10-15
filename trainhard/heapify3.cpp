#include<iostream>
#include<vector>
using namespace std;

int A[100];
int heap_length = 0;



int left(int i){
    return i * 2;
}

int right(int i){
    return i * 2 + 1;
}

int parent(int i){
    return i/2;
}

void heapify(int i){

    int large;
    int l = left(i);
    int r = right(i);

    if (r <= heap_length && A[r] > A[i])
    {
        large = r;
    }else{
        large = i;
    }

    if (l <= heap_length && A[l] > A[large])
    {
        large = l;
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

    for (int i = heap_length/2; i >= 1; i--)
    {
        heapify(i);
    }
    
}

void readinput(){


    cout << "Input Array : ";
    
    heap_length = 10; 


    for (int i = 1; i <= heap_length; i++)
    {
        cin >> A[i];
    }

    
    buid_heap();

    
}

void print_heap(){

    for (int i = 1; i <= heap_length; i++)
    {
        cout << A[i] << " ";
    }
    
}

void insertQ(){

    cout << "input : ";
    int val;


    cin >> val;
    heap_length++;

    int i = heap_length;
    while (i > 1 && A[parent(i)] < val)
    {
        A[i] = A[parent(i)];
        i = parent(i);
    }

    A[i] = val;

    cout << "Heap : ";
    print_heap();
    cout << endl;
    
    
}

void service(){

    
    if (heap_length <= 0) {
        cout << "Heap is empty!\n";
        return;
    }

    cout << "Service : " << A[1] << endl;
    


    A[1] = A[heap_length];
    heap_length--;
    heapify(1);
    print_heap();
    cout << endl;
    
}

int main(){
    int choice;
    do {
        cout << "===========================\n";
        cout << "          MENU             \n";
        cout << "===========================\n";
        cout << "1. Input Array\n";
        cout << "2. Print Heap\n";
        cout << "3. Insert Queue\n";
        cout << "4. Service\n";
        cout << "5. Exit\n";
        cout << "Please choose > ";
        cin >> choice;

        switch(choice){
            case 1:
                readinput();
                break;
            case 2:
                cout << "Heap : ";
                print_heap();
                break;
            case 3:
                insertQ();
                break;
            case 4:
                service();
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}