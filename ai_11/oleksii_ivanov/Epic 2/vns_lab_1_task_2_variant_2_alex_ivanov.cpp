#include <iostream>
using std::cout, std::cin, std::endl;

/**
 * <h4>Task 1-2</h4> <p>
 * Evaluates weird C++ statements <p>
 *
 * Statement 1 ("++n*++m): operator ++number
 * returns number + 1 after incrementation,
 * so ++n*++m == (n + 1) * (m + 1). <p>
 *
 * Statement 2 (m++<n): operator m++ returns m,
 * but changes m, so the expression m++<n
 * actually would be the same as m < n, but m is
 * incremented after. <p>
 *
 * Statement 3 (n++>m): operator n++ returns n,
 * but increments it, so n++>m would be the same
 * as n > m, but n is incremented after. <p>
 */
int main() {
    // Set output of booleans to its string representation
    cout << std::boolalpha;

    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;

    cout << "++n*++m: " << ++n*++m << endl;
    cout << "m++<n: "   << (m++<n) << endl;
    cout << "n++>m: "   << (n++>m) << endl;

    return 0;
}
