#include<iostream>
using namespace std;

void bubble(int arr[],int n){
    for(int i=1;i<n;i++){
     bool swapped = false;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
         if(swapped==false){
        break;
    }
    }
   
}

int main(){
    int arr[7]={64,34,25,12,22,11,90};

    bubble(arr,7);
    for(int i=0;i<7;i++){
        cout << "Sorted Array : " << arr[i] << endl;
    }

    return 0;
}