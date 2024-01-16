#include <bits/stdc++.h>

using namespace std;

// Function to find the root of the equation
double f(double x) {
    return x * log10(x) - 1.2; // Edit this line for different functions
}

int main() {
    // Initialization
    double a, b, p, p_old = 0;
    const double tolerance = 0.000001;
    int i = 0;

    // Input interval from the user
    cout << "Enter the values of a and b between which the root lies: ";
    cin >> a >> b;

    // Check if the root exists within the interval
    while (f(a) * f(b) > 0) {
        cout << "Root doesn't exist within this interval. Rewrite interval." << endl;
        cin >> a >> b;
    }

    // Main loop for the bisection method
    while (1) {
        // Bisection method
        p = (a + b) / 2;
        i++;

        // Output current iteration information
        cout << i << ". Root: " << p << " Value: " << f(p);

        // Calculate and output tolerance
        double ctol = abs(p - p_old) / p;
        cout << " Tolerance: " << ctol << endl;

        // Check for root and tolerance conditions
        if (i == 1) {
            if (f(p) == 0.0) {
                cout << "Root is " << p << " (correct up to 5 decimal places)." << endl;
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
                cout << "Root is " << p << " (correct up to 5 decimal places)." << endl;
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
