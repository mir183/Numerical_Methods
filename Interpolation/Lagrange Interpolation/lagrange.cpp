#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double x1, ans = 0.0, x_value, f_value;
    cout << "Enter the number of values for the argument x :";
    cin >> n;
    vector<double> x(n), f_x(n);
    cout << "Write the values of the argument x :";
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << "Write the values of the corresponding values for the given argument x :";
    for(int i = 0; i < n; i++) {
        cin >> f_x[i];
    }
    cout << "Enter the value of interpolation point :";
    cin >> x1;
    for(int i = 0; i < n; i++) {
        x_value = 1;
        f_value = 1;
        for(int j = 0; j < n; j++) {
            if(j != i) {
                x_value = x_value * (x1 - x[j]);
                f_value = f_value * (x[i] - x[j]);
            }
        }
        ans = ans + (x_value / f_value) * f_x[i];
    }
    cout << "The solution of the given point : " << ans << endl;
    return 0;
}