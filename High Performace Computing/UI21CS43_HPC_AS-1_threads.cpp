#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

#define N 12
#define P 4

using namespace std;
vector<double> a(N, 4.0);
vector<double> b(N, 2.0);
vector<double> partial_sums(P, 0.0);
mutex barrier_mutex;
condition_variable barrier_cv;
int threads_ready = 0;

void parallelFunction(int my_id)
{
  int start = (N / P) * my_id;
  int end = (N / P) * (my_id + 1) - 1;
  double s = 0.0;
  for (int i = start; i <= end; ++i)
    s += a[i] * b[i];
  partial_sums[my_id] = s;

  {
    unique_lock<mutex> lock(barrier_mutex);
    threads_ready++;
    if (threads_ready == P)
    {
      threads_ready = 0;
      barrier_cv.notify_all();
    }
    else
    {
      barrier_cv.wait(lock);
    }
  }
}

int main()
{
  vector<thread> threads;

  for (int i = 0; i < P - 1; ++i)
  {
    threads.emplace_back(parallelFunction, i + 1);
  }

  parallelFunction(0);

  for (auto &thread : threads)
  {
    thread.join();
  }

  double dot_product = 0.0;
  for (int i = 0; i < P; ++i)
  {
    dot_product += partial_sums[i];
  }

  cout << "The dot product is " << dot_product << std::endl;

  return 0;
}