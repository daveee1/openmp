#include <omp.h>
#include <iostream>

using namespace std;


static long num_steps = 100000;
double step;

int main ()
{ 
	double pi_final = 0.0, pi_local = 0.0;
	step = 1.0/(double) num_steps;

	

	/* REDUCTION VERSION: more efficient.
	 * Each thread has its copy of "pi_final=0.0". At the END sum em all together
	 *
	*/
	#pragma omp parallel for reduction(+:pi_final)
	for (int i=0; i < num_steps; i++){
		double x = (i + 0.5) * step;
		pi_final += 4.0/(1.0 + x * x);
	}
	

	pi_final *= step;
	cout << pi_final;
}
	/* unefficient version: here "omp parallel" handles alone all threads's jobs
	 * by assigning work when due. Each thread takes its i's, computes and stores 
	 * in pi_local. After that we store the final result: each 
	 * thread in "omp critical" increments pi_final by its local result computed
	 * previously. In "critical" each thread must wait its turn because another 
	 * thread may be entered from before: if two threads entered at the same time 
	 * , take pi_local1 = 2, pi_local2 = 4, pi_final = 0: if both accessed together
	 * then pi_final = 2 or 4 -> WE NEED SYNCHRONIZATION

	double pi_final = 0.0, pi_local = 0.0;
	step = 1.0/(double) num_steps;
	
	#pragma omp parallel private (pi_local) shared(pi_final)
	{
		double x;
		int i;
		#pragma omp for
		for (i=0; i < num_steps; i++){
			x = (i+0.5)*step;
			pi_local += 4.0/(1.0+x*x);
			int tid = omp_get_thread_num();
			cout << "im thread "<< tid << endl;
		}

		#pragma omp critical
		{
			pi_final += pi_local;
			//pi_final = pi_final * step; //wrong! i mul for every thread!

		}
	}

	pi_final = pi_final * step;
	cout<<pi_final;
	
	return 0;
	}
	*/
