#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// File Management (อ้างอิงจาก ADT-File)
// ==========================================

// เมนู 1: สร้าง random.dat จำนวน 3,000,000 ค่า สุ่มจำนวนเต็มในช่วง 1 ถึง 100,000
void create_random_file(int count = 3000000)
{
    srand(time(0));
    ofstream myfile("random.dat");

    if (!myfile.is_open())
    {
        cout << "Unable to open file random.dat" << endl;
        return;
    }

    cout << "\nCreating random.dat with " << count << " numbers (range: 1 - 100,000)..." << endl;

    // ตั้ง buffer ขนาด 128 KB เพื่อให้เขียนไฟล์ขนาดใหญ่ได้อย่างรวดเร็ว
    const int BUF_SIZE = 128 * 1024;
    char buffer[BUF_SIZE];
    myfile.rdbuf()->pubsetbuf(buffer, BUF_SIZE);

    clock_t start_time = clock();

    for (int i = 0; i < count; i++)
    {
        // บน Windows ค่า RAND_MAX มีค่า 32,767 จึงผสม rand() สองรอบเพื่อให้ครอบคลุม 1 - 100,000
        int num = (((rand() << 15) | rand()) % 100000) + 1;
        myfile << num << " ";
        if ((i + 1) % 10 == 0)
        {
            myfile << "\n";
        }
    }

    myfile.close();

    clock_t end_time = clock();
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Create random.dat Success! (Time: " << duration << " seconds)\n" << endl;
}

// อ่านข้อมูลจาก random.dat เข้าอาร์เรย์
int read_random_file(int array[], int max_size)
{
    ifstream readfile("random.dat");

    if (!readfile.is_open())
    {
        cout << "Unable to open file random.dat" << endl;
        cout << "Please select menu 1 to create random.dat first!\n" << endl;
        return 0;
    }

    const int BUF_SIZE = 128 * 1024;
    char buffer[BUF_SIZE];
    readfile.rdbuf()->pubsetbuf(buffer, BUF_SIZE);

    cout << "Reading data from random.dat..." << endl;
    clock_t start_time = clock();

    int count = 0;
    while (count < max_size && readfile >> array[count])
    {
        count++;
    }

    readfile.close();

    clock_t end_time = clock();
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Loaded " << count << " numbers successfully. (Time: " << duration << " seconds)" << endl;
    return count;
}

// เขียนข้อมูลที่เรียงลำดับแล้วลงไฟล์ผลลัพธ์
bool write_output_file(const string &filename, int array[], int length)
{
    ofstream outfile(filename.c_str());

    if (!outfile.is_open())
    {
        cout << "Unable to open file " << filename << endl;
        return false;
    }

    const int BUF_SIZE = 128 * 1024;
    char buffer[BUF_SIZE];
    outfile.rdbuf()->pubsetbuf(buffer, BUF_SIZE);

    cout << "Writing sorted data to " << filename << "..." << endl;
    clock_t start_time = clock();

    for (int i = 0; i < length; i++)
    {
        outfile << array[i] << "\n";
    }

    outfile.close();

    clock_t end_time = clock();
    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Write " << filename << " Success! (Time: " << duration << " seconds)\n" << endl;
    return true;
}

// ==========================================
// Sorting Algorithms (อ้างอิงจาก ADT-16)
// ==========================================

// ฟังก์ชันสลับค่าตัวแปร
void swap_elements(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// 2) Selection Sort
void selection_sort(int array[], int length)
{
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

// 3) Bubble Sort
void bubble_sort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// 4) Insertion Sort (ตามตัวอย่าง C++ ในสไลด์หน้า 19)
void insertion_sort(int array[], int length)
{
    int p, j, tmp;
    for (p = 1; p < length; p++)
    {
        for (j = p; j > 0; j--)
        {
            if (array[j] < array[j - 1])
            {
                tmp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
            else
            {
                break;
            }
        }
    }
}

// Shell Sort (Gapped Insertion Sort ในสไลด์)
void shell_sort(int array[], int length)
{
    for (int gap = length / 2; gap > 0; gap /= 2)
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

// 5) Merge Sort (ตามสไลด์หน้า 29 - 32)
void merge(int A[], int tmparray[], int lpos, int rpos, int rightend)
{
    int i, leftend, numelements, tmppos;
    leftend = rpos - 1;
    tmppos = lpos;
    numelements = rightend - lpos + 1;

    while (lpos <= leftend && rpos <= rightend)
    {
        if (A[lpos] <= A[rpos])
        {
            tmparray[tmppos++] = A[lpos++];
        }
        else
        {
            tmparray[tmppos++] = A[rpos++];
        }
    }

    while (lpos <= leftend)
    {
        tmparray[tmppos++] = A[lpos++];
    }

    while (rpos <= rightend)
    {
        tmparray[tmppos++] = A[rpos++];
    }

    for (i = 0; i < numelements; i++, rightend--)
    {
        A[rightend] = tmparray[rightend];
    }
}

void msort(int A[], int tmparray[], int left, int right)
{
    int center;
    if (left < right)
    {
        center = left + (right - left) / 2;
        msort(A, tmparray, left, center);
        msort(A, tmparray, center + 1, right);
        merge(A, tmparray, left, center + 1, right);
    }
}

void merge_sort(int array[], int length)
{
    int *tmparray = new int[length];
    msort(array, tmparray, 0, length - 1);
    delete[] tmparray;
}

// 6) Quick Sort (ตามหลักการ Median-of-three และ Partition ในสไลด์หน้า 19 - 24)
int partition(int array[], int low, int high)
{
    int mid = low + (high - low) / 2;

    // Median-of-three pivot selection
    if (array[mid] < array[low]) swap_elements(&array[low], &array[mid]);
    if (array[high] < array[low]) swap_elements(&array[low], &array[high]);
    if (array[high] < array[mid]) swap_elements(&array[mid], &array[high]);
    swap_elements(&array[mid], &array[high]);

    int pivot = array[high];
    int i = low;
    int j = high - 1;

    while (true)
    {
        while (i <= high - 1 && array[i] < pivot) i++;
        while (j >= low && array[j] > pivot) j--;

        if (i < j)
        {
            swap_elements(&array[i], &array[j]);
            i++;
            j--;
        }
        else
        {
            break;
        }
    }
    swap_elements(&array[i], &array[high]);
    return i;
}

void quick_sort_rec(int array[], int low, int high)
{
    while (low < high)
    {
        int pi = partition(array, low, high);

        // จัดการฝั่งที่เล็กกว่าก่อนเพื่อป้องกัน Stack Overflow เมื่อข้อมูลมีขนาด 3 ล้านตัว
        if (pi - low < high - pi)
        {
            quick_sort_rec(array, low, pi - 1);
            low = pi + 1;
        }
        else
        {
            quick_sort_rec(array, pi + 1, high);
            high = pi - 1;
        }
    }
}

void quick_sort(int array[], int length)
{
    quick_sort_rec(array, 0, length - 1);
}

// 7) Heap Sort (Max-Heap)
void heapify(int array[], int length, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < length && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < length && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap_elements(&array[i], &array[largest]);
        heapify(array, length, largest);
    }
}

void heap_sort(int array[], int length)
{
    for (int i = length / 2 - 1; i >= 0; i--)
        heapify(array, length, i);

    for (int i = length - 1; i > 0; i--)
    {
        swap_elements(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

// 8) Bucket Sort
void bucket_sort(int array[], int length)
{
    if (length <= 1) return;

    int min_val = array[0];
    int max_val = array[0];
    for (int i = 1; i < length; i++)
    {
        if (array[i] < min_val) min_val = array[i];
        if (array[i] > max_val) max_val = array[i];
    }

    if (min_val == max_val) return;

    int bucket_count = 10000;
    vector<int> *buckets = new vector<int>[bucket_count];

    int avg_capacity = (length / bucket_count) + 50;
    for (int i = 0; i < bucket_count; i++)
    {
        buckets[i].reserve(avg_capacity);
    }

    for (int i = 0; i < length; i++)
    {
        int b_idx = (int)(((long long)(array[i] - min_val) * (bucket_count - 1)) / (max_val - min_val));
        buckets[b_idx].push_back(array[i]);
    }

    int idx = 0;
    for (int i = 0; i < bucket_count; i++)
    {
        if (!buckets[i].empty())
        {
            insertion_sort(buckets[i].data(), buckets[i].size());
            for (size_t j = 0; j < buckets[i].size(); j++)
            {
                array[idx++] = buckets[i][j];
            }
        }
    }

    delete[] buckets;
}

// 9) Radix Sort (LSD Radix Sort ด้วย Stable Counting Sort ตามสไลด์หน้า 26 - 33)
void count_sort_radix(int array[], int length, int exp)
{
    int *output = new int[length];
    int count[10] = {0};

    for (int i = 0; i < length; i++)
    {
        count[(array[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = length - 1; i >= 0; i--)
    {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    for (int i = 0; i < length; i++)
    {
        array[i] = output[i];
    }

    delete[] output;
}

void radix_sort(int array[], int length)
{
    if (length <= 1) return;

    int max_val = array[0];
    for (int i = 1; i < length; i++)
    {
        if (array[i] > max_val)
        {
            max_val = array[i];
        }
    }

    // digit = (n / exp) % 10 ตามสูตรทั่วไปในสไลด์หน้า 28
    for (int exp = 1; max_val / exp > 0; exp *= 10)
    {
        count_sort_radix(array, length, exp);
    }
}

// ==========================================
// Main Function & Assignment Menu
// ==========================================
int main()
{
    const int MAX_SIZE = 3000000;
    int *array = new int[MAX_SIZE];

    int choice;

    while (true)
    {
        cout << "========================================" << endl;
        cout << "  Assignment: Sorting Algorithms Menu" << endl;
        cout << "========================================" << endl;
        cout << "1) Create random file" << endl;
        cout << "2) Selection sort" << endl;
        cout << "3) Bubble sort" << endl;
        cout << "4) Insertion sort" << endl;
        cout << "5) Merge sort" << endl;
        cout << "6) Quick sort" << endl;
        cout << "7) Heap sort" << endl;
        cout << "8) Bucket sort" << endl;
        cout << "9) Radix sort" << endl;
        cout << "10) Exit" << endl;
        cout << "\nPlease choose > ";

        if (!(cin >> choice))
        {
            cin.clear();
            string discard;
            getline(cin, discard);
            cout << "Invalid input. Please enter a number 1 - 10.\n" << endl;
            continue;
        }

        if (choice == 10)
        {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        if (choice == 1)
        {
            create_random_file(MAX_SIZE);
        }
        else if (choice >= 2 && choice <= 9)
        {
            int n = read_random_file(array, MAX_SIZE);
            if (n == 0)
            {
                continue;
            }

            string out_filename = "";
            clock_t start_time = clock();

            switch (choice)
            {
                case 2:
                    cout << "Sorting with Selection sort..." << endl;
                    selection_sort(array, n);
                    out_filename = "selection.out";
                    break;
                case 3:
                    cout << "Sorting with Bubble sort..." << endl;
                    bubble_sort(array, n);
                    out_filename = "bubble.out";
                    break;
                case 4:
                    cout << "Sorting with Insertion sort..." << endl;
                    insertion_sort(array, n);
                    out_filename = "insertion.out";
                    break;
                case 5:
                    cout << "Sorting with Merge sort..." << endl;
                    merge_sort(array, n);
                    out_filename = "merge.out";
                    break;
                case 6:
                    cout << "Sorting with Quick sort..." << endl;
                    quick_sort(array, n);
                    out_filename = "quick.out";
                    break;
                case 7:
                    cout << "Sorting with Heap sort..." << endl;
                    heap_sort(array, n);
                    out_filename = "heap.out";
                    break;
                case 8:
                    cout << "Sorting with Bucket sort..." << endl;
                    bucket_sort(array, n);
                    out_filename = "bucket.out";
                    break;
                case 9:
                    cout << "Sorting with Radix sort..." << endl;
                    radix_sort(array, n);
                    out_filename = "radix.out";
                    break;
            }

            clock_t end_time = clock();
            double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            cout << "Sorted in " << duration << " seconds." << endl;

            write_output_file(out_filename, array, n);
        }
        else
        {
            cout << "Invalid choice! Please choose 1 - 10.\n" << endl;
        }
    }

    delete[] array;
    return 0;
}
