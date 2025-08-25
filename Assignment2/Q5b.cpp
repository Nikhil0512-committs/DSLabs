#include <iostream>
using namespace std;

int main() {
    int sparseMatrix[4][4] = {
        {1, 4, 0, 0},
        {3, 4, 1, 0},
        {0, 2, 3, 4},
        {0, 0, 1, 3}
		
	};

    int size = 0;

   
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (sparseMatrix[i][j] != 0) {
                size++;
            }
        }
    }

    int compactMatrix[3][size]; 
    int k = 0;

  
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i;           
                compactMatrix[1][k] = j;             
                compactMatrix[2][k] = sparseMatrix[i][j];  
                k++;
            }
        }
    }

    
    cout << "Compact representation of sparse matrix :" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            cout << compactMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
