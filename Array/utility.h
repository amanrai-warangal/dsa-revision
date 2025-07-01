#include<vector>
#include<iostream>
using namespace std;

int secondMax(vector<int> arr){
    int firstMax = -1;
    int secondMax = -1;

    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] > firstMax){
            secondMax = firstMax;
            firstMax = arr[i];
        }

        else if(arr[i] > secondMax && arr[i] != firstMax)
            secondMax = arr[i];
    }

    return secondMax;
}