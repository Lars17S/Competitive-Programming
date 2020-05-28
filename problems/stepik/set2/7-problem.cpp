#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 
   
double polygonArea(double X[], double Y[], int n) 
{
    double area = 0.0;
    int j = n - 1; 
    for (int i = 0; i < n; i++) { 
        area += (X[j] + X[i]) * (Y[j] - Y[i]); 
        j = i;
    } 
    return abs(area / 2.0); 
} 

int main() 
{
    int n;
    cin >> n;
    double* X = new double[n];
    double* Y = new double[n];
    for (int i = 0; i < n; ++i)
        cin >> X[i] >> Y[i];
    cout << fixed << setprecision(2) << polygonArea(X, Y, n); 
} 