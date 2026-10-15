#include<iostream>
#include<vector>
using namespace std;

int A[100];

int heap_length = 10;

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

void print_heap(){

    for (int i = 1; i <= heap_length; i++)
    {
        cout << A[i] << " ";
    }
    
}


void biud_heap(){

    for (int i = heap_length/2; i >= 1; i--)
    {
        heapify(i);
    }
    
}

void readinput(){

    cout << "input : ";

    for (int i = 1; i <= heap_length; i++)
    {
        cin >> A[i];
    }
    
}



int main(){

    readinput();

    biud_heap();

    cout << "output : ";
    for (int i = 1; i <= heap_length; i++)
    {
        cout << A[i] << " ";
    }
    

}


