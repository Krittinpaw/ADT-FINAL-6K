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

void print_heap(){

    for (int i = 1; i <= heap_size; i++)
    {
        cout << A[i] << " ";
    }

    cout << "\n";
    
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

void input_array(){

    int num;

    cout << "input Array : ";
    
    for (int i = 1; i <= heap_size; i++)
    {
        cin >> num;
        A[i] = num;
    }
    
}

void heap_sort(){

    int original_size = heap_size;
    int step = 1;
    for (int i = original_size; i >= 1; i--)
    {
        int tmp = A[i];
        A[i] = A[1];
        A[1] = tmp;

        cout << "#" << step << " : ";

        for (int j = 1; j <= original_size; j++)
        {

            cout << A[j] << " ";
        }
        heap_size--;
        heapify(1);
        step++;
        
    }
    
}



int main(){

    input_array();
    cout << "Heap : ";
    print_heap();

    buid_heap();
    print_heap();

    cout << "Heap sort" << endl;

   heap_sort();
   return 0;
    

}