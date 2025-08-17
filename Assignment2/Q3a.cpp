#include<iostream>
using namespace std;

int Searching(int arr[], int n){
    for(int i=0;i<6;i++){
        int value;
        int search = 0;
        if(arr[i]==search){
            return i;
          
        }
      
    }
    return -1;
}

int main(){
    int arr[6]={1,2,3,4,5};
    int index = Searching(arr,6);
    cout << "Index is : " << index << endl;
    cout << "Value is : " << index+1;
   

    return 0;
}