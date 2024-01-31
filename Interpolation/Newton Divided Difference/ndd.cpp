#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double x1, ans, x_value;
    cout << "Enter the number of values for the argument x :";
    cin >> n;
    vector<double> x(n), f_x(n);
    vector<vector<double>> table(n, vector<double>(n));
    cout << "Write the values of the argument x :";
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << "Write the values of the given entry y :";
    for(int i = 0; i < n; i++) {
        cin >> f_x[i];
    }
    cout << "Enter the value of interpolation point :";
    cin >> x1;
    for(int i = 0; i < n; i++) {
        table[i][0] = f_x[i];
    }
    for(int j = 1; j < n; j++) {
        for(int i = j; i < n; i++) {
            table[i][j] = (table[i][j-1] - table[i-1][j-1])/(x[i]-x[i-j]);
        }
    }
    ans = f_x[0];
    for(int i = 1; i < n; i++) {
        x_value = 1;
        for(int j = 0; j < i; j++) {
            x_value = x_value*(x1 - x[j]);
        }
        ans = ans + (x_value*table[i][i]);
    }
    cout << "The difference table is given below :";
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << "x= " << x[i];
        for(int j = 0; j <= i; j++) {
            cout << " " << table[i][j];
        }
        cout << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "The solution of the given point : " << ans << endl;
    return 0;
}