#include<iostream>
using namespace std;

int Searching(int arr[], int n){
    int key =0;
    int start =0;
    int end = n-1;
    int mid = start + (end-start)/2;
    for(int i=0;i<n;i++){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
           end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}

int main(){
    int arr[6]={1,2,3,4,5};
    
    int index = Searching(arr,6);

    return 0;
}