#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * log10(x) - 1.2;
}

double fp(double x) {
    return log10(x) + 0.434294;
}

int main() {
    double x, ans, ans_old;
    int i = 0;
    const double tolerance = 0.000001;

    cout << "ENTER THE VALUE OF x: ";
    cin >> x;

    cout << "n           x           f(x)\n";

    while (1){
        ans = x - f(x) / fp(x);
        i++;

        cout << i << "           " << ans << "           " << f(ans) << endl;

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
            double ctol=(abs(ans - ans_old) / ans);
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
