#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if(n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int n, m;
    double x1, v, v_value, ans = 0;
    cout << "Enter the number of values for the argument x:\n";
    cin >> n;
    vector<double> x(n), f_x(n);
    vector<vector<double>> table(n, vector<double>(n+1));
    cout << "Write the values of the argument x :\n";
    for(int i = 0; i < n; i++)
        cin >> x[i];
    cout << "Write the values of the given entry y :\n";
    for(int i = 0; i < n; i++)
        cin >> f_x[i];
    cout << "Enter the value of interpolation point :\n";
    cin >> x1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n+1; j++) {
            if(j == 0)
                table[i][j] = x[i];
            else if(j == 1)
                table[i][j] = f_x[i];
            else if(j <= i+1)
                table[i][j] = table[i][j-1] - table[i-1][j-1];
        }
    }
    v = (x1 - x[n-1])/(x[n-1] - x[n-2]);
    for(int i = 0; i < n; i++) {
        m = i - 1;
        v_value = 1;
        for(int j = 0; j <= m; j++)
            v_value = v_value * (v + j);
        ans = ans + (v_value/factorial(i)) * table[n-1][i+1];
    }
    cout << "The difference table is given below : ";
    cout << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i+1; j++) {
            if(i == n-1 && j == n-1) {
                cout << table[i][j] << " " << table[i][j+1] << "\n";
                break;
            }
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "----------------------------------------------------------------------\n";
    cout << "The solution of the given point : " << ans << "\n";
    return 0;
}