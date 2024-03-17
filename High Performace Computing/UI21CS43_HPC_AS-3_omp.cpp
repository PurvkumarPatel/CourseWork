#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <omp.h>

using namespace std;

int main() {
    const int np = 100000;
    int count = 0;
    double r;
    cout<<"Enter the value of R(radius) : ";
    cin>>r;

    #pragma omp parallel for reduction(+:count)
    for (int i = 0; i < np; ++i) {
        double x = (double)(rand()*r) / RAND_MAX; 
        double y = (double)(rand()*r) / RAND_MAX;

        if (x * x + y * y <= r*r) {
            count++;
        }
    }

    double probability = (double)(count) / np;
    double pi_estimate = 4.0 * probability;

    cout << "Estimated value of π: " << pi_estimate << std::endl;

    return 0;
}

