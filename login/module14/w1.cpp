#include<iostream>
#include<vector>
using namespace std;

int A[16];
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

void printheap(){

    for (int i = 1; i <= heap_size; i++)
    {
        cout << A[i] << " ";
    }
    
}

void buid_heap(){

    for (int i = heap_size/2; i >= 1; i--)
    {
        heapify(i);
    }

    printheap();
    
}

void insertarray(){

    int num;

    cout << "input : ";

    for (int i = 1; i <= heap_size; i++)
    {
        cin >> num;
        A[i] = num;
    }
    
}



int main(){

    

    insertarray();

    cout << "Heap : ";

    buid_heap();

    
    
    
}