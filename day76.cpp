// C++ program to calculate power Using builtin methods
#include <iostream>
#include <cmath>
using namespace std;

double power(double b, int e) {  
    return pow(b, e);
}

int main() {
    double b = 3.0;
    int e = 5;
    cout << power(b, e);
}