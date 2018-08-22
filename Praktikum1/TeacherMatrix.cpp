//
// Created by lukas on 22.08.18.
//

#include "TeacherMatrix.h"

using namespace teacher;

Matrix::Matrix(int reihen, int spalten) : reihen(reihen), spalten(spalten) {
    if (reihen <= 0) {
        throw "row less then one";
    }
    if (spalten <= 0) {
        throw "column less then one";
    }
    werte = new double *[reihen];
    for (int i = 0; i < reihen; i++) {
        werte[i] = new double[spalten];
    }
}

Matrix::Matrix(int reihen, int spalten, double wert) : reihen(reihen), spalten(spalten) {
    if (reihen <= 0) {
        throw "row less then one";
    }
    if (spalten <= 0) {
        throw "column less then one";
    }
    werte = new double *[reihen];
    for (int i = 0; i < reihen; i++) {
        werte[i] = new double[spalten];
        for (int j = 0; j < spalten; j++) {
            werte[i][j] = wert;
        }
    }
}

Matrix::Matrix(const Matrix &matrix) : reihen(matrix.reihen), spalten(matrix.spalten) {
    werte = new double *[reihen];
    for (int i = 0; i < reihen; i++) {
        werte[i] = new double[spalten];
        for (int j = 0; j < spalten; j++) {
            werte[i][j] = matrix.werte[i][j];
        }
    }
}

double Matrix::at(int reihe, int spalte) const {
    if (reihe < 0 || reihe >= reihen) {
        throw "wrong row";
    }
    if (spalte < 0 || spalte >= spalten) {
        throw "wrong column";
    }
    return werte[reihe][spalte];
}

double &Matrix::at(int reihe, int spalte) {
    if (reihe < 0 || reihe >= reihen) {
        throw "wrong row";
    }
    if (spalte < 0 || spalte >= spalten) {
        throw "wrong column";
    }
    return werte[reihe][spalte];
}

int Matrix::getRows() {
    return reihen;
}

int Matrix::getCols() {
    return spalten;
}

Matrix::~Matrix() {
    for (int i = 0; i < reihen; i++) {
        delete[] werte[i];
    }
    delete[] werte;
}

Matrix &Matrix::operator=(const Matrix &matrix) {
    for (int i = 0; i < reihen; i++) {
        delete[] werte[i];
    }
    delete[] werte;

    reihen = matrix.reihen;
    spalten = matrix.spalten;

    werte = new double *[reihen];
    for (int i = 0; i < reihen; i++) {
        werte[i] = new double[spalten];
        for (int j = 0; j < spalten; j++) {
            werte[i][j] = matrix.werte[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix &matrix) const {
    if (reihen != matrix.reihen) {
        throw "Matrizen have not same count of rows";
    }
    if (spalten != matrix.spalten) {
        throw "Matrizen have not same count of columns";
    }
    Matrix tmp(reihen, spalten);
    for (int i = 0; i < reihen; i++) {
        for (int j = 0; j < spalten; j++) {
            tmp.werte[i][j] = werte[i][j] + matrix.werte[i][j];
        }
    }
    return tmp;
}

Matrix Matrix::operator-(const Matrix &matrix) const {
    if (reihen != matrix.reihen) {
        throw "Matrizen have not same count of rows";
    }
    if (spalten != matrix.spalten) {
        throw "Matrizen have not same count of columns";
    }
    Matrix tmp(reihen, spalten);
    for (int i = 0; i < reihen; i++) {
        for (int j = 0; j < spalten; j++) {
            tmp.werte[i][j] = werte[i][j] - matrix.werte[i][j];
        }
    }
    return tmp;
}

bool Matrix::operator==(const Matrix &matrix) const {
    if (reihen != matrix.reihen) {
        return false;
    }
    if (spalten != matrix.spalten) {
        return false;
    }
    for (int i = 0; i < reihen; i++) {
        for (int j = 0; j < spalten; j++) {
            if (werte[i][j] != matrix.werte[i][j]) {
                return false;
            }
        }
    }
    return true;
}

double &Matrix::operator()(int reihe, int spalte) {
    if (reihe < 0 || reihe >= reihen) {
        throw "wrong row";
    }
    if (spalte < 0 || spalte >= spalten) {
        throw "wrong column";
    }
    return werte[reihe][spalte];
}

