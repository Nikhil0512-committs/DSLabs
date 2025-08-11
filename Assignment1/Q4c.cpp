#include<iostream>
using namespace std;

int main(){
    int a[10][10], b[10][10],row,col;
    cout << "Enter no. of rows: ";
    cin >> row;
    cout <<"\nEnter no. of columns: ";
    cin>> col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            b[j][i]=a[i][j];
        }
    }
    cout << "\nTranspose of the matrix is : \n";
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout << b[i][j] << " ";

        }
        cout << endl;
    }

    return 0;
}