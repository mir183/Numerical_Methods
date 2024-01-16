#include <bits/stdc++.h>
using namespace std;

// Function for which root is to be found
double f(double x) {
    return 4 * exp(-x) * sin(x) - 1; // Edit this line for the desired function
}


int main() {
    double a, b, p, p_old = 0, tolerance = 0.000001;
    int i = 0;

    // Inputting the interval [a, b] from the user
    cout << "ENTER THE VALUE OF a AND b BETWEEN WHICH THE ROOT LIES: ";
    cin >> a >> b;

    // Checking if the initial interval is valid
    while (1) {
        if (f(a) * f(b) > 0) {
            cout << "ROOT DOESN'T EXISTS WITHIN THIS INTERVAL. REWRITE INTERVAL" << endl;
            cin >> a >> b;
        } else {
            break;
        }
    }

    // Loop for performing the Regula Falsi method
    while (1) {
        // Computing the next approximation using Regula Falsi method
        p = (a * f(b) - b * f(a)) / (f(b) - f(a));
        i++;

        // Computing the tolerance for the current iteration
        double ctol = abs(p - p_old) / p;

        // Displaying the iteration details
        cout << i << ". " << fixed << setprecision(5) << "Root: " << p << " " << "Value: " << f(p) << " Tolerance: " << ctol << endl;

        // Checking conditions for convergence
        if (i == 1) {
            if (f(p) == 0.0) {
                cout << "ROOT IS " << fixed << setprecision(5) << p << " (CORRECT UPTO 5 DECIMAL PLACES)" << endl;
                break;
            } else {
                p_old = p;
                if (f(a) * f(p) > 0) {
                    a = p;
                } else {
                    b = p;
                }
            }
        }

        if (i > 1) {
            if (f(p) == 0.0 || ctol <= tolerance) {
                cout << "FINAL ROOT IS " << fixed << setprecision(5) << p << " (CORRECT UPTO 5 DECIMAL PLACES)" << endl;
                break;
            } else {
                p_old = p;
                if (f(a) * f(p) > 0) {
                    a = p;
                } else {
                    b = p;
                }
            }
        }
    }

    return 0;
}
