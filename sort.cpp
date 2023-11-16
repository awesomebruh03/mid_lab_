#include<bits/stdc++.h>
#include<vector>
using namespace std;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(std::vector<int>& arr) {
    int size = arr.size();
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion_sort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(std::vector<int>& arr){
    int i,j,min,size=arr.size();
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        swap(&arr[min],&arr[i]);
    }
}
int median_of_three(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;

    // Rearrange the three elements to be in non-decreasing order
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);

    return mid;  // Return the index of the median element
}

int partition(vector<int>& arr, int low, int high) {
    int pivotIndex = median_of_three(arr, low, high);
    int pivotValue = arr[pivotIndex];

    swap(arr[pivotIndex], arr[high]);

    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivotValue) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}
void merge(std::vector<int>& arr,int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
        L[i]=arr[low+i];
    for(int j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
            arr[k++]=R[j++];
    }
    while(i<n1)
        arr[k++]=L[i++];
    while(j<n2)
        arr[k++]=R[j++];
}
void merge_sort(std::vector<int>& arr, int low, int high){
    if(low < high)
    {
        int mid = low + (high - low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void heapify(std::vector<int>& arr,int size,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<size && arr[l]>arr[largest])
        largest=l;
    if(r<size && arr[r]>arr[largest])
        largest=r;
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,size,largest);
    }
}
void heap_sort(std::vector<int>& arr){
    int size=arr.size();
    for(int i=size/2-1;i>=0;i--)
        heapify(arr,size,i);
    for(int i=size-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void counting_sort(std::vector<int>& arr, int exp) {
    int size = arr.size();
    int max = *max_element(arr.begin(), arr.end());

    std::vector<int> count(max + 1, 0);
    std::vector<int> output(size);

    for (int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radix_sort(std::vector<int>& arr) {
    int size = arr.size();
    if (size <= 1)
        return;

    int max = *max_element(arr.begin(), arr.end());

    for (int exp = 1; max / exp > 0; exp *= 10)
        counting_sort(arr, exp);
}

void print_array(std::vector<int>& arr){
    int size = arr.size();
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
    //arr.clear();
}
int main(){
    vector<int> arr;
    int choice;
    int element;
    while(true){
             cout << "Enter your choice:\n"
             << "1. Enter elements into the array\n"
             << "2. Sort using Bubble Sort\n"
             << "3. Sort using Insertion Sort\n"
             << "4. Sort using Selection Sort\n"
             << "5. Sort using Quick Sort\n"
             << "6. Sort using Merge Sort\n"
             << "7. Sort using Heap Sort\n"
             << "8. Sort using Radix Sort\n"
             << "0. Exit\n";
        cin >> choice;
        switch(choice){
            case 1:
                arr.clear();
                cout << "Enter the elements of array, type '-1' when finished" << endl;
                while(cin >> element && element != -1){
                arr.push_back(element);
                }
                break;
            case 2:
                bubble_sort(arr);
                break;
            case 3:
                insertion_sort(arr);
                break;
            case 4:
                selection_sort(arr);
                break;
            case 5:
                quick_sort(arr,0,arr.size()-1);
                break;
            case 6:
                merge_sort(arr,0,arr.size()-1);
                break;
            case 7:
                heap_sort(arr);
                break;
            case 8:
                radix_sort(arr);
                break;
            case 9:
                print_array(arr);
            case 0:
                exit(0);
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
        print_array(arr);

    }
    return 0;
}
