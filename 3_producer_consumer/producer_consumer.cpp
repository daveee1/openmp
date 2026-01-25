#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <mutex>
using namespace std; 

// TODO i need a MUTEX
mutex buff_mutex;


int available_items(int [] arr){
	if(arr[0]==NULL)
		return 0;
	if(arr[-1]!=NULL)
		return arr.length-1;

	for(int i=0;i<arr.length;i++){
		if(arr[i]==NULL)
			return i+1;
	}
}

void producer(int writer_id, int [] arr){
	// TODO when to be activated? when available_items == 0
	if()	
}

void consumer(){
	// TODO when to be activated? when available_items >= 0
	if(available_items(buff)==0);
		//call producer
	
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
