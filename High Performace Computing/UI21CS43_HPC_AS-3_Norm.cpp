#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int np = 100000;
    int insideCircle = 0;
    double r;
    cout<<"Enter the value of R(radius) : ";
    cin>>r;
    std::srand(std::time(0));

    for (int i = 0; i < np; ++i) {
        double x = static_cast<double>(rand()*r) / RAND_MAX ;
        double y = static_cast<double>(rand()*r) / RAND_MAX ;

        if (x * x + y * y <= r*r) {
            insideCircle++;
        }
    }

    double probability = static_cast<double>(insideCircle) / np;
    double pi_estimate = 4 * probability;

    std::cout << "Estimated value of π: " << pi_estimate << std::endl;

    return 0;
}
