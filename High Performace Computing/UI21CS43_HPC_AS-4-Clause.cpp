#include <iostream>
#include <omp.h>

const int num_sections = 4;
const int array_size = 12;
int main()
{
  int array[array_size];
  // Initialize array
  for (int i = 0; i < array_size; ++i)
  {
    array[i] = i;
  }
#pragma omp parallel sections {
// Section 1: Use of Schedule Clause
#pragma omp section {
#pragma omp for schedule(static, 2)
  for (int i = 0; i < array_size; ++i)
  {
    array[i] += 10;
    std::cout << "Thread " << omp_get_thread_num() << " modifies element " << i << " in Section 1. " << std::endl;
  }
}
// Section 2: Use of Section Clause
#pragma omp section {
#pragma omp parallel for
for (int i = 0; i < array_size; ++i)
{
  array[i] *= 2;
  std::cout << "Thread " << omp_get_thread_num() << " modifies element " << i << " in Section 2. " << std::endl;
}
}
// Section 3: Use of Synchronization Clause
#pragma omp section {
#pragma omp
      for
        for (int i = 0; i < array_size; ++i)
        {
      // Critical section to ensure mutual exclusion
#pragma omp critical {
          array[i] -= 5;
          std::cout << "Thread " << omp_get_thread_num() << " modifies element " << i << " in Section 3. " << std::endl;
        }
      }
      }
      // Section 4: Another Example of Schedule Clause
#pragma omp section {
#pragma omp
      for
        schedule(dynamic, 3) for (int i = 0; i < array_size; ++i)
        {
          array[i] += 8;
          std::cout << "Thread " << omp_get_thread_num() << " modifies element " << i << " in Section 4. " << std::endl;
        }
      }
      }
      // Print the final array
      std::cout << "Final Array: ";
      for (int i = 0; i < array_size; ++i)
      {
        std::cout << array[i] << " ";
      }
      std::cout << std::endl;
      return 0;
      }