#include<iostream>
using namespace std;

int main(){
    int a[4][4]={1,2,6,7,0,6,6,8,3,0,2,4,5,7,0,1};
    cout << "The given matrix is: " << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    int z, nz=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]==0){
                z++;
            }else{
                nz++;
            }

        }
    }

    if(nz>z){
        int s[nz][3];
        int k=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(a[i][j]!=0){
                    s[k][0] = i;
                    s[k][1]  = j;
                    s[k][2] = a[i][j];
                    k++;
                }
            }
        }

        for(int i =0;i<nz;i++){
        for(int j=0;j<3;j++){
            cout << s[i][j];
        }
        cout << endl;
    }
    }

    


    return 0;
}
