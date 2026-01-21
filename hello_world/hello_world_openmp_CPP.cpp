#include <iostream>
#include <omp.h>

int main() {
    // Set the number of threads (optional; defaults to environment variable OMP_NUM_THREADS)
    omp_set_num_threads(4);

    // Parallel region: each thread executes this block
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        std::cout << "Hello from thread " << thread_id << " of " 
                  << omp_get_num_threads() << std::endl;
    }

    return 0;
}
