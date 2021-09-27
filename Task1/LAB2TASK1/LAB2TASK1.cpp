#include <iostream>
#include <iomanip>
#include <cmath>

class Vector {
private:
    long double* array;
    int Length;
public:
    Vector() {
        this->array = new long double[0];
        Length = 0;
    }
    Vector(int Size) {
        this->array = new long double[Size];
        this->Length = Size;
        for (int i = 0; i < Length; i++)
            this->array[i] = 1;
    }
    ~Vector() {
        delete[] this->array;
    }
    int GetLength() const{
        return this->Length;
    }

    Vector& operator++() {
        for (int i = 0; i < Length; i++)
            this->array[i]++;
        return *this;
    }

    Vector& operator++(int) {
        ++(*this);
        return *this;
    }

    Vector& operator--() {
        for (int i = 0; i < Length; i++)
            this->array[i]--;
        return *this;
    }
    Vector& operator--(int) {
        --(*this);
        return *this;
    }
    long double& operator[](int index) {
        return this -> array[index];
    }
    Vector& operator=(const Vector& T) {
        if (this == &T)
            return *this;
        if (array)
            delete[] this->array;
        this->Length = T.Length;
        this->array = new long double[this->Length];
        for (int i = 0; i < Length; i++)
            this->array[i] = T.array[i];
        return *this;
    }
    void Print() {
        for (int i = 0; i < this->Length; i++)
            std::cout << this->array[i] << ' ';
    }
    friend std::ostream& operator<< (std::ostream& out, const Vector& vector);
};
std::ostream& operator<< (std::ostream& out,const Vector& v)
{
    for (int i = 0; i < v.GetLength(); i++)
        out << std::setw(10) << v.array[i] << ' ';
    return out;
}

class Matrix {
private:
    long double** matrix;
    int AmountOfArrays;
    int AmountOfElements;
public:
    Matrix(const int AmountOfArrays_, const int AmountOfElements_) {
        AmountOfArrays = AmountOfArrays_;
        AmountOfElements = AmountOfElements_;
        matrix = new long double* [AmountOfArrays];
        for (int i = 0; i < AmountOfArrays; i++)
            matrix[i] = new long double[AmountOfElements] {1};
    }
    ~Matrix() {
        for (int i = 0; i < AmountOfArrays; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
    int GetAmountOfArrays() {
        return AmountOfArrays;
    }
    int GetAmountOfElements() {
        return AmountOfElements;
    }
    long double At(int i, int j) {
        return matrix[i][j];
    }
    void SetAt(int i, int j, long double value) {
        matrix[i][j] = value;
    }
    void Print() {
        using namespace std;
        cout.precision(4);
        cout << fixed;
        for (int i = 0; i < AmountOfArrays; i++)
        {
            for (int j = 0; j < AmountOfElements; j++)
                cout << setw(10) << matrix[i][j];
            cout << endl;
        }
    }
    void FillForTask() {
        for (int i = 0; i < AmountOfArrays; i++)
            for (int j = 0; j < AmountOfElements; j++)
                matrix[i][j] = sin(i - j) + cos(i + j);
    }


};
void  From2Din1D(Vector v, Matrix m) {
    int size = m.GetAmountOfElements() * m.GetAmountOfArrays(), now = 0;
    Vector tmp(size);
    for (int i = 0; i < m.GetAmountOfArrays(); i++)
        for (int j = 0; j < m.GetAmountOfArrays(); j++, now++)
            tmp[now] = m.At(i, j);
    v = tmp;
}
int main() {
    Vector a;
    Matrix b(5, 3);
    b.FillForTask();
    From2Din1D(a, b);
    std::cout << "[ " << a << " ]";
    return 0;
}