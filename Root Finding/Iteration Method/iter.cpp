#include <iostream>
#include <cmath>
using namespace std;


// Function definitions
double f(double x) {
    return 2 * pow(x, 3) - 7 * pow(x, 2) - 6 * x + 1;
}

double phi(double x) {
    return pow((7 * pow(x, 2) + 6 * x - 1) / 2, 1.0 / 3.0);
}

double phiprime(double x) {
    double numerator = 7 * pow(x, 2) + 6 * x - 1;
    return (1.0 / 3.0) * (numerator / 2) * pow(numerator, -2.0 / 3.0);
}


int main() {
    double x, tolerance = 0.000001, ans, ans_old;
    int i = -1;

    cout << "ENTER THE VALUE OF x: ";
    cin >> x;

    while (1) {
        if (phiprime(x) >= 1) {
            cout << "REWRITE VALUE\n";
            cin >> x;
        } else {
            break;
        }
    }

    while (1) {
        ans = phi(x);
        i++;

        cout << i << "   " << x << "          " << f(ans) << '\n';

        if (i == 1) {
            if (f(ans) == 0.0) {
                cout << "ROOT IS " << ans << " (CORRECT UPTO 5 DECIMAL PLACES)\n";
                break;
            } else {
                ans_old = ans;
                x = ans;
            }
        }

        if (i > 1) {
            double ctol = abs((ans - ans_old) / ans);
            if (f(ans) == 0.0 || ctol <= tolerance) {
                cout << "ROOT IS " << ans << " (CORRECT UPTO 5 DECIMAL PLACES)\n";
                break;
            } else {
                ans_old = ans;
                x = ans;
            }
        }
    }

    return 0;
}
