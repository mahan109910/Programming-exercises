#include <iostream>


using namespace std;

class DZYـLovesـChessboard{
    private:

    int n, m;
    char matrix[100][100];
    char keymatrix[100][100];

    public:
        DZYـLovesـChessboard(){
            cin >> n >> m;

            for (int i=0 ; i<n ; i++){
                for (int j=0 ; j<m ; j++){
                    cin >> matrix[i][j];
                }
            }

        }

        void key (){
            for (int i=0 ; i<n ; i++){
                for (int j=0 ; j<m ; j++){
                    if(matrix[i][j]== '-'){
                        keymatrix[i][j] = '-';
                    }else {
                        if ((i + j) % 2 == 0) {
                            keymatrix[i][j] = 'B';
                        } else {
                            keymatrix[i][j] = 'W';
                        }
                    }
                }
            }
        }

        void print (){
            for (int i=0 ; i<n ; i++){
                for (int j=0 ; j<m ; j++){
                    cout << keymatrix[i][j];
                }
                cout << endl;
            }
        }
};


int main()
{
    DZYـLovesـChessboard a1_1;

    a1_1.key();
    a1_1.print();


    return 0;
}