#include"Sort.h"
#include"utility.h"

void insert(int *arr,int index,int val){
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i=index;i<len-1;i++)
        arr[i+1] = arr[i];
    
        arr[index] = val;
}

void remove(int *arr,int index){
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i=index;i<len;i++)
        arr[i] = arr[i+1];
}


int main(){
    // int n;
    // cout << "Length of Array : ";
    // cin >> n;

    // vector<int> arr(n);
    // cout << "Enter Array Elements : ";
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }

    // SortClass s;
    
    // s.quickSort(arr);

    // for(auto x : arr)
    //     cout << x << " ";

    // cout << endl;

    // cout << secondMax(arr) << endl;
    
    int nums[10] = {0};
    insert(nums,6,60);
    insert(nums,9,160);
    remove(nums,6);
    remove(nums,9);
    for(int i=0;i<10;i++)
        cout << nums[i] << " ";

}