#include <omp.h>
#include <stdio.h>
#include <iostream>

using namespace std; 

// TODO i need a MUTEX

void producer(){
	// TODO when to be activated? when available_items == 0
	
}

void consumer(){
	// TODO when to be activated? when available_items >= 0
}

int main()
{
	//TODO project on consumer/producer since there are not a lot of 
	// possible execises with openmp (strange)
	
	// general idea: even number of threads. Suppose for the moment 1 prod., 1 cons. .
	// I consume till I finish all elements (like a signal semaphore implementation, similar to CRTP course)
	
	int length_buff = 8;
	int buffer[length_buff] = {};
	
	int consumer = length_buff - 1;
	int producer = 0;

	#pragma omp parallel 


}
