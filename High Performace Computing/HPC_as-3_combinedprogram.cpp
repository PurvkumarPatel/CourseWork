#include <iostream>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    const int np = 100000;  // Number of random points
    int insideCircle = 0;

    // Sequential version
    std::clock_t start_time_seq = std::clock();

    for (int i = 0; i < np; ++i) {
        // Generate random points within the square [-1,1] x [-1,1]
        double x = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
        double y = static_cast<double>(rand()) / RAND_MAX * 2 - 1;

        // Check if the point is inside the circle
        if (x * x + y * y <= 1) {
            insideCircle++;
        }
    }

    // Estimate the probability P and calculate π
    double probability_seq = static_cast<double>(insideCircle) / np;
    double pi_estimate_seq = 4 * probability_seq;

    std::clock_t end_time_seq = std::clock();
    double elapsed_time_seq = static_cast<double>(end_time_seq - start_time_seq) / CLOCKS_PER_SEC;

    // Parallel version
    insideCircle = 0;  // Reset for parallel version

    std::clock_t start_time_parallel = std::clock();

    #pragma omp parallel for reduction(+:insideCircle)
    for (int i = 0; i < np; ++i) {
        // Generate random points within the square [-1,1] x [-1,1]
        double x = static_cast<double>(rand()) / RAND_MAX * 2 - 1;
        double y = static_cast<double>(rand()) / RAND_MAX * 2 - 1;

        // Check if the point is inside the circle
        if (x * x + y * y <= 1) {
            #pragma omp atomic
            insideCircle++;
        }
    }

    // Estimate the probability P and calculate π
    double probability_parallel = static_cast<double>(insideCircle) / np;
    double pi_estimate_parallel = 4 * probability_parallel;

    std::clock_t end_time_parallel = std::clock();
    double elapsed_time_parallel = static_cast<double>(end_time_parallel - start_time_parallel) / CLOCKS_PER_SEC;

    // Output the results
    std::cout << "Sequential version:\n";
    std::cout << "Estimated value of π: " << pi_estimate_seq << "\n";
    std::cout << "Elapsed time: " << elapsed_time_seq << " seconds\n\n";

    std::cout << "Parallel version:\n";
    std::cout << "Estimated value of π: " << pi_estimate_parallel << "\n";
    std::cout << "Elapsed time: " << elapsed_time_parallel << " seconds\n";

    return 0;
}


