#include<iostream>
#include<vector>
#include <thread>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high){
    vector<int>temp;
    int left = low;
    int right = high;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }

    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
        for(int i = low; i <= high; i++){
            arr[i] = temp[i -low];
        }
    }

}


        
        void parallelMergeSort(vector<int> & arr, int low, int high){
            if(low >= high){
                return;
            }
            int mid = high + (high - low)/2;
            thread leftThread(parallelMergeSort, ref(arr), low, mid);
            thread rightThread(parallelMergeSort, ref(arr), mid+1, high);
            leftThread.join();
            rightThread.join();
        }

int main(){

    vector<int> arr = {12,2,34,5,5, 8};
    parallelMergeSort(arr, 0, arr.size()-1);
    for(int x : arr){
        cout << x << " ";
    }
return 0;
}

