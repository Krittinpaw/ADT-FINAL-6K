#include<iostream>
using namespace std;

void selection_soert(int array[]){

    int length = sizeof(array)/sizeof(array[0]);

    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            
            if (array[j] < array[min])
            {
                min = j;
            }
            

            
        }

        if (min != i)
        {
            int tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
        
        
    }
    
}

void buble_sort(int array[]){

    int length = sizeof(array)/sizeof(array[0]);

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            int next = j + 1;
            if (array[j] > array[next])
            {
                int tmp = array[j];
                array[j] = array[next];
                array[next] = tmp;
            }
            
        }
        
    }
    
}

void insertion_sort(int array[], int length){

    int p, j, tmp;
    for (p = 1 ; p < length ; p++)
    {
        for (j = p ; j > 0 ; j--)
        {
            if (array[j] < array[j - 1])
            {
                
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }else{
                
                break;
            }
        }
    }

}

void shell_sort(int array[], int length){
    for (int gap = length / 2 ; gap > 0; gap /= 2)
    {
        for (int i = gap; i < length; i++)
        {
            int tmp = array[i], j = i;
            
            while (j >= gap && array[j - gap] > tmp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = tmp;
        }
    }
}