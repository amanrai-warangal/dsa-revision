#include <iostream>
#include <vector>

using namespace std;

class SortClass
{
public:
    void bubbleSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (arr[j - 1] > arr[j])
                    swap(arr[j], arr[j - 1]);
            }
        }
    }

    void insertionSort(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            int key = arr[i];
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void selectionSort(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            int index = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[index])
                    index = j;
            }
            swap(arr[index], arr[i]);
        }
    }

    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int i = low, j = mid + 1;

        while (i <= mid && j <= high)
        {
            if (arr[i] < arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid)
        {
            temp.push_back(arr[i++]);
        }

        while (j <= high)
            temp.push_back(arr[j++]);

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void mergeSort(vector<int> &arr)
    {
        mergeSort(arr, 0, arr.size() - 1);
    }

    int partition(vector<int> &arr, int low, int high)
    {
        int pivot = arr[low];
        int i = low;

        for (int j = low + 1; j <= high; ++j)
        {
            if (arr[j] < pivot)
            {
                ++i;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[low], arr[i]);
        return i;
    }

    void quickSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;

        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }

    void quickSort(vector<int> &arr)
    {
        quickSort(arr, 0, arr.size() - 1);
    }
};