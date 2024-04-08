#include<fstream>
#include<iostream>
using namespace std;

// Functii de afisare / Citire etc

//Functie citire din Fisier a vector / matrice 

void citireFisier(float x[10][10], int n, int m) {
    fstream f("mat_a.txt", ios::in);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f >> x[i][j];
    f.close();
}

// Functie Afisare Matrice

void afisare(float x[10][10], int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << "\t" << x[i][j];
        cout << "\n";
    }
}

// Functii Matematice 

// Gauss

void gauss1(float a[10][10], float b[10], int n, float x[10], int print) {
    int l, k, i, j;
    float p, mult;
    ofstream f("afisare.txt", ios::out); //scrierea in fisier
    for (k = 1; k <= n - 1; k++) {
        l = k;
        for (i = k + 1; i <= n; i++)
            if (abs(a[i][k]) <= abs(a[l][k]))
                l = i;
        if (l != k) {
            for (j = k; j <= n; j++) {
                p = a[k][j];
                a[k][j] = a[l][j];
                a[l][j] = p;
            }
            p = b[k];
            b[k] = b[l];
            b[l] = p;
        }
        for (i = k + 1; i <= n; i++) {
            mult = a[i][k] / a[k][k];
            for (j = 1; j <= n; j++)
                a[i][j] = a[i][j] - mult * a[k][j];
            b[i] = b[i] - mult * b[k];
        }
        if (print == 1) {
            f << "Iteratia " << k << endl;
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++)
                    f << "\t" << a[i][j];
                f << " *\t" << b[i] << " *\t";
                f << "\n";
            }
            f << "\n";
        }
        x[n] = b[n] / a[n][n];
        for (i = n - 1; i >= 1; i--) {
            p = 0;
            for (j = i + 1; j <= n; j++)
                p = p + a[i][j] * x[j];
            x[i] = (b[i] - p) / a[i][i];
        }
    }
    if (print == 1) {
        f << "\n Solutia sistemului prin algoritmul Gauss este: ";
        for (i = 1; i <= n; i++)
            f << "\n x(" << i << ")= " << x[i];
    }
    f.close();
}