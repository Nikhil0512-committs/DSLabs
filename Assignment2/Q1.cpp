#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int start=0;
    int end =n-1;
    int mid= start + (end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
        mid = start+(end-start)/2;
    }
    return -1;
}

int linearSearch(int arr[], int n , int key){
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int evenArray[6]={10,20,5,8,15,17};
    int index = binarySearch(evenArr,6,17);
    cout << "17 is at index " << index << endl;

    int index2 = linearSearch(evenArr,6,8);
    cout << "8 is at index " << index2 << endl;

    return 0;
}