#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements for the array: ";
    cin >> n;
    int A[n];
    cout << "Enter the " << n << " elements: ";
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            if(i<j && A[i]>A[j]){
                count ++;
            }
        }
    }
    cout << "\nThe number of inversions are: " << count << endl;
    return 0;
}
