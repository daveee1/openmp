#include <omp.h>
#include <iostream>

using namespace std;


static long num_steps = 100000;
double step;

int main ()
{ 
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
			//pi_final = pi_final * step; //wrong! i mul for every step!

		}
	}

	pi_final = pi_final * step;
	cout<<pi_final;
	return 0;
}
