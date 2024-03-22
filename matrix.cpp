#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void readFromFile(const string& filePath, int **& matrix1, int **& matrix2, int& size){
    ifstream file(filePath);
    if(file){
        file >> size;

        matrix1 = new int*[size];
        matrix2 = new int*[size];

        for(int i = 0; i < size; ++i){
            matrix1[i] = new int[size];
            for (int j = 0; j < size; ++j){
                file >> matrix1[i][j];
            }
        }

        for (int i = 0; i < size; ++i) {
            matrix2[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                file >> matrix2[i][j];
            }
        }
        
    }
    else{
        cout << "The file is not here" << endl;
    }
}

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void addMatrix(int **matrix1, int **matrix2, int **&result, int size) {
    result = new int*[size];
    for (int i = 0; i < size; i++) {
        result[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyTheMatrix(int **matrix1, int **matrix2, int **&result, int size) {
    result = new int*[size];
    for (int i = 0; i < size; i++) {
        result[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void subtractMatrix(int **matrix1, int **matrix2, int **&result, int size){
    result = new int*[size];
    for (int i = 0; i < size; i++){
        result[i] = new int[size];
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void copyMatrix(int **matrix1, int **matrix2, int size){
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix2[i][j] = matrix1[i][j];
        }
    }
}

void updateMatrix(int **matrix1, int **updatedMatrix, int row, int col, int value, int size){
    copyMatrix(matrix1, updatedMatrix, size);
    if (row >= 0 && row < size && col >= 0 && col < size){
        updatedMatrix[row][col] = value;
    }
    else{
        cout << "Error" << endl;
    }
}


int getMax(int **matrix, int size){
    int max = matrix[0][0];
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(matrix[i][j] > max){
               max = matrix[i][j];
            }
        }
    }
    return max;
}

void trans(int **matrix1, int **transposedMatrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transposedMatrix[j][i] = matrix1[i][j];
        }
    }
}

int main(){
    int** matrix1;
    int** matrix2;
    int matrixSize = 3;
    int** addedMatrix;
    int** multiplyMatrix;
    int** subtractedMatrix;
    int** updatedMatrix = new int*[matrixSize];
    int maxVal;
  
    

    string filePath = "matrix_input.txt";
    readFromFile(filePath, matrix1, matrix2, matrixSize);

    for(int i = 0; i < matrixSize; ++i) {
        updatedMatrix[i] = new int[matrixSize];
        for(int j = 0; j < matrixSize; ++j) {
            updatedMatrix[i][j] = 0;
        }
    }

    int **transposedMatrix = new int*[matrixSize];
    for (int i = 0; i < matrixSize; ++i) {
        transposedMatrix[i] = new int[matrixSize];
        for (int j = 0; j < matrixSize; ++j) {
            transposedMatrix[i][j] = 0;
        }
    }

    cout << "Matrix 1:" << endl;
    printMatrix(matrix1, matrixSize);
    cout << endl;
    cout << "Matrix 2:" << endl;
    printMatrix(matrix2, matrixSize);

    cout << endl;

    addMatrix(matrix1, matrix2, addedMatrix, matrixSize);
    cout << "Added Matrix is:" << endl;
    printMatrix(addedMatrix, 3);

    cout << endl;

    multiplyTheMatrix(matrix1, matrix2, multiplyMatrix, matrixSize);
    cout << "Multiply Matrix is:" << endl;
    printMatrix(multiplyMatrix, matrixSize);

    cout << endl;

    subtractMatrix(matrix1, matrix2, subtractedMatrix, matrixSize);
    cout << "Subtracted Matrix is:" << endl;
    printMatrix(subtractedMatrix, matrixSize);

    cout << endl;

    updateMatrix(matrix1, updatedMatrix, 0 , 2, 100, 3);
    cout << "Updated Matrix 1 1st row and last col to 100:" << endl;
    printMatrix(updatedMatrix, matrixSize);

    cout << endl;

    maxVal = getMax(matrix1, 3);
    cout << "The max value of the first matrix is " << maxVal << endl;

    cout << endl;

    trans(matrix1, transposedMatrix, matrixSize);
    cout << "Transposed Matrix:" << endl;
    printMatrix(transposedMatrix, matrixSize);


    for (int i = 0; i < matrixSize; ++i) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] addedMatrix[i];
        delete[] multiplyMatrix[i];
        delete[] subtractedMatrix[i];
        delete[] updatedMatrix[i];
        delete[] transposedMatrix[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] addedMatrix;
    delete[] multiplyMatrix;
    delete[] subtractedMatrix;
    delete[] updatedMatrix;
    delete[] transposedMatrix;
    return 0;
}
