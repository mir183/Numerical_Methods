#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if(n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter the number of values for the argument x :";
    cin >> n;
    vector<float> x(n), f_x(n);
    vector<vector<float>> table(n, vector<float>(n+1));
    cout << "Write the values of the argument x :";
    for(int i = 0; i < n; i++)
        cin >> x[i];
    cout << "Write the values of the given entry y :";
    for(int i = 0; i < n; i++)
        cin >> f_x[i];
    float x1;
    cout << "Enter the value of interpolation point :";
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
    float u = (x1 - x[0])/(x[1] - x[0]);
    float ans = 0;
    for(int i = 0; i < n; i++) {
        int m = i - 1;
        float u_value = 1;
        for(int j = 0; j <= m; j++)
            u_value = u_value * (u - j);
        ans = ans + (u_value/factorial(i)) * table[i][i+1];
    }
    cout << "The difference table is given below :";
    cout << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i+1; j++) {
            if(i == n - 1 && j == n) {
                cout << table[i][j] << " " << table[i][j+1] << "\n";
                break;
            }
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------------------------------------------\n";
    cout << "The solution of the given point : " << ans << "\n";
    return 0;
}