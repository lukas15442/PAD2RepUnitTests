//
// Created by lukas on 22.08.18.
//

#ifndef LUKASCODE_MATRIX_H
#define LUKASCODE_MATRIX_H


class Matrix {
public:
    Matrix(int reihen, int spalten);

    Matrix(int reihen, int spalten, double wert);

    Matrix(const Matrix &matrix);

    ~Matrix();

    double at(int reihe, int spalte) const;

    double &at(int reihe, int spalte);

    int getRows();

    int getCols();

    Matrix &operator=(const Matrix &matrix);

    Matrix operator+(const Matrix &matrix) const;

    Matrix operator-(const Matrix &matrix) const;

    bool operator==(const Matrix &matrix) const;

    double &operator()(int reihe, int spalte);

private:
    int reihen;
    int spalten;
    double **werte;
};


#endif //LUKASCODE_MATRIX_H
