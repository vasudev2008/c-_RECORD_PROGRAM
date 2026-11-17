#include <iostream>
#include <cassert>
using namespace std;

class Matrix {
    int data[2][2];
public:
    Matrix(int a=0, int b=0, int c=0, int d=0) : data{{a,b},{c,d}} {}
    Matrix operator+(const Matrix& m) const {
        Matrix result;
        for (int i=0;i<2;i++) for (int j=0;j<2;j++) result.data[i][j]=data[i][j]+m.data[i][j];
        return result;
    }
    Matrix operator*(const Matrix& m) const {
        Matrix result;
        for (int i=0;i<2;i++) for (int j=0;j<2;j++) {
            result.data[i][j]=0;
            for (int k=0;k<2;k++) result.data[i][j]+=data[i][k]*m.data[k][j];
        }
        return result;
    }
    int* operator[](int index) { assert(index>=0 && index<2); return data[index]; }
    const int* operator[](int index) const { assert(index>=0 && index<2); return data[index]; }
    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for(int i=0;i<2;i++){ for(int j=0;j<2;j++) out<<m.data[i][j]<<' '; out<<'\n'; }
        return out;
    }
};
int main() {
    Matrix A(1,2,3,4), B(5,6,7,8);
    Matrix sum=A+B, product=A*B;
    assert(sum[0][0]==6 && sum[1][1]==12);
    assert(product[0][0]==19 && product[0][1]==22 && product[1][0]==43 && product[1][1]==50);
    cout<<"Matrix A:\n"<<A<<"Matrix B:\n"<<B<<"Addition of Matrices:\n"<<sum
        <<"Multiplication of Matrices:\n"<<product<<"All unit tests passed successfully.\n";
}
