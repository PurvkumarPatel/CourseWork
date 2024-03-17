#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>
#define N 10000000
#define P 4

std::vector < double > crossProduct(const std::vector < double > & vectorA,
        const std::vector < double > & b) {
        std::vector < double > result(N, 0.0);
        #pragma omp parallel
        for
        for (int i = 0; i < N; ++i) {
                result[i] = vectorA[(i + 1) % N] * b[(i + 2) % N] - vectorA[(i + 2) % N] * b[(i + 1) % N];
        }
        return result;
}
void parallelDotProduct(double vectorA[], double b[], double & dot_product, double execution_times[]) {
        int my_id, i, start, end;
        double dot_local = 0.0;
        double start_time, end_time;
        my_id = omp_get_thread_num();
        start = (N / P) * my_id;
        end = (N / P) * (my_id + 1) - 1;
        start_time = omp_get_wtime();
        for (i = start; i <= end; i++) {
                dot_local += vectorA[i] * b[i];
        }
        end_time = omp_get_wtime();
        dot_product += dot_local;
        #pragma omp critical {
                execution_times[my_id] = end_time - start_time;
        }
        #pragma omp barrier
}
int main() {
        std::vector < double > vectorA(N);
        std::vector < double > b(N);
        for (int i = 0; i < N; i++) {
                vectorA[i] = i + 4;
                b[i] = i + 2;

        }
        if (vectorA.size() != b.size()) {
                std::cerr << "Vectors must have the same size." << std::endl;
                return 1;
        }
        auto cross_start_time = std::chrono::high_resolution_clock::now();
        std::vector < double > c = crossProduct(vectorA, b);
        auto cross_end_time = std::chrono::high_resolution_clock::now();
        auto cross_elapsed_time = std::chrono::duration_cast < std::chrono::microseconds > (cross_end_time - cross_start_time).count();
        double dot_product = 0.0;
        double execution_times[P] = {
                0.0
        };
        auto dot_start_time = std::chrono::high_resolution_clock::now();
        #pragma omp parallel num_threads(P) {
                parallelDotProduct(vectorA.data(), b.data(), dot_product, execution_times);
        }
        auto dot_end_time = std::chrono::high_resolution_clock::now();
        auto dot_elapsed_time = std::chrono::duration_cast < std::chrono::microseconds > (dot_end_time - dot_start_time).count();
        std::cout << "\nCross Product \n";
        std::cout << "Time taken for cross product: " << cross_elapsed_time << " ms" << std::endl;
        std::cout << "Resulting cross product vector: [";
        for (int i = 0; i < std::min(10, static_cast < int > (c.size())); ++i) {
                std::cout << c[i];
                if (i < 9) std::cout << ", ";
        }
        std::cout << ", ...]" << std::endl;
        std::cout << "\nDot Product \n";
        std::cout << "Total time taken for dot product: " << dot_elapsed_time << " ms" << std::endl;
        std::cout << "Resulting dot product :" << dot_product << "\n\n";
        return 0;
}
