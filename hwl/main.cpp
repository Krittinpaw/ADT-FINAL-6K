#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int tmp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = tmp;
        }
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void insertionSort(int a[], int N) {
    int p, j, tmp;
    for (p = 1; p < N; p++) {
        for (j = p; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            } else {
                break;
            }
        }
    }
}

void merge(int A[], int tmparray[], int lpos, int rpos, int rightend) {
    int i, leftend, numelements, tmppos;
    leftend = rpos - 1;
    tmppos = lpos;
    numelements = rightend - lpos + 1;

    while (lpos <= leftend && rpos <= rightend) {
        if (A[lpos] <= A[rpos]) {
            tmparray[tmppos++] = A[lpos++];
        } else {
            tmparray[tmppos++] = A[rpos++];
        }
    }

    while (lpos <= leftend) {
        tmparray[tmppos++] = A[lpos++];
    }

    while (rpos <= rightend) {
        tmparray[tmppos++] = A[rpos++];
    }

    for (i = 0; i < numelements; i++, rightend--) {
        A[rightend] = tmparray[rightend];
    }
}

void msort(int A[], int tmparray[], int left, int right) {
    int center;
    if (left < right) {
        center = left + (right - left) / 2;
        msort(A, tmparray, left, center);
        msort(A, tmparray, center + 1, right);
        merge(A, tmparray, left, center + 1, right);
    }
}

void mergeSort(int A[], int n) {
    int* tmparray = new int[n];
    msort(A, tmparray, 0, n - 1);
    delete[] tmparray;
}

void quickSortHelper(int a[], int left, int right) {
    while (left < right) {
        if (right - left == 1) {
            if (a[left] > a[right]) {
                int t = a[left];
                a[left] = a[right];
                a[right] = t;
            }
            return;
        }
        int mid = left + (right - left) / 2;
        if (a[mid] < a[left]) {
            int t = a[left]; a[left] = a[mid]; a[mid] = t;
        }
        if (a[right] < a[left]) {
            int t = a[left]; a[left] = a[right]; a[right] = t;
        }
        if (a[right] < a[mid]) {
            int t = a[mid]; a[mid] = a[right]; a[right] = t;
        }
        int t = a[mid]; a[mid] = a[right]; a[right] = t;
        int pivot = a[right];

        int i = left;
        int j = right - 1;
        while (true) {
            while (i <= right - 1 && a[i] < pivot) i++;
            while (j >= left && a[j] > pivot) j--;
            if (i < j) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
                i++;
                j--;
            } else {
                break;
            }
        }
        int tmp = a[i];
        a[i] = a[right];
        a[right] = tmp;

        if (i - 1 - left < right - (i + 1)) {
            quickSortHelper(a, left, i - 1);
            left = i + 1;
        } else {
            quickSortHelper(a, i + 1, right);
            right = i - 1;
        }
    }
}

void quickSort(int a[], int n) {
    quickSortHelper(a, 0, n - 1);
}

void heapify(int a[], int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest]) {
            largest = left;
        }
        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

void bucketSort(int a[], int n) {
    if (n <= 1) return;
    int min_val = a[0];
    int max_val = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }
    if (min_val == max_val) return;

    int bucket_count = 1000;
    vector<vector<int>> buckets(bucket_count);
    long long range = (long long)max_val - min_val + 1;

    for (int i = 0; i < n; i++) {
        int b_idx = (long long)(a[i] - min_val) * bucket_count / range;
        if (b_idx >= bucket_count) b_idx = bucket_count - 1;
        buckets[b_idx].push_back(a[i]);
    }

    int idx = 0;
    for (int i = 0; i < bucket_count; i++) {
        sort(buckets[i].begin(), buckets[i].end());
        for (size_t j = 0; j < buckets[i].size(); j++) {
            a[idx++] = buckets[i][j];
        }
    }
}

void countSortForRadix(int a[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    delete[] output;
}

void radixSort(int a[], int n) {
    if (n <= 1) return;
    int max_val = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
        }
    }

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countSortForRadix(a, n, exp);
    }
}

bool readRandomFile(vector<int>& data) {
    ifstream readfile("random.dat");
    if (!readfile.is_open()) {
        cout << "Unable to open file\n";
        return false;
    }
    data.clear();
    data.reserve(3000000);
    int num;
    while (readfile >> num) {
        data.push_back(num);
    }
    readfile.close();
    return true;
}

void writeOutputFile(const char* filename, const vector<int>& data) {
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cout << "Unable to open file\n";
        return;
    }
    for (size_t i = 0; i < data.size(); i++) {
        outfile << data[i] << " ";
    }
    outfile.close();
    cout << "Write data Success\n";
}

int main() {
    int choice = 0;
    do {
        cout << "\n1) Create random file\n";
        cout << "2) Selection sort\n";
        cout << "3) Bubble sort\n";
        cout << "4) Insertion sort\n";
        cout << "5) Merge sort\n";
        cout << "6) Quick sort\n";
        cout << "7) Heap sort\n";
        cout << "8) Bucket sort\n";
        cout << "9) Radix sort\n";
        cout << "10) Exit\n\n";
        cout << "Please choose > ";
        if (!(cin >> choice)) {
            break;
        }

        if (choice == 1) {
            system("createfile.exe");
        } else if (choice >= 2 && choice <= 9) {
            vector<int> data;
            if (readRandomFile(data)) {
                if (choice == 2) {
                    selectionSort(data.data(), data.size());
                    writeOutputFile("selection.out", data);
                } else if (choice == 3) {
                    bubbleSort(data.data(), data.size());
                    writeOutputFile("bubble.out", data);
                } else if (choice == 4) {
                    insertionSort(data.data(), data.size());
                    writeOutputFile("insertion.out", data);
                } else if (choice == 5) {
                    mergeSort(data.data(), data.size());
                    writeOutputFile("merge.out", data);
                } else if (choice == 6) {
                    quickSort(data.data(), data.size());
                    writeOutputFile("quick.out", data);
                } else if (choice == 7) {
                    heapSort(data.data(), data.size());
                    writeOutputFile("heap.out", data);
                } else if (choice == 8) {
                    bucketSort(data.data(), data.size());
                    writeOutputFile("bucket.out", data);
                } else if (choice == 9) {
                    radixSort(data.data(), data.size());
                    writeOutputFile("radix.out", data);
                }
            }
        }
    } while (choice != 10);

    return 0;
}
