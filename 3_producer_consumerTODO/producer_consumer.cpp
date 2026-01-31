#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <mutex>
#include <random>

std::cout;
std::endl;

#define BUFFER_SIZE 8;
int buffer[BUFFER_SIZE];
int next_free_position = 0;	// next free position
int last_item_position = 0;


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

int rnd_generator()
{
	
	std::random_device dev;
	std::mt19937 rng(dev());	
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1,99); // distribution
	return dist6(rng);
}

// produces one item
void producer(){
	// TODO when to be activated? when available_items < BUFF_SIZE - 1
	if(last_item_position == BUFFER_SIZE - 1)
		consumer();
	#pragma omp critical
	{
		buffer[next_free_position] = rnd_generator();
		last_item_position = next_free_position;
		next_free_position++;
	}	
}


// consumes one item
void consumer(){
	// TODO when to be activated? when available_items > 0
	//call producer
	if(available_items(buff)==0)
	 	producer();
	// there are enough items: we can consume
	// CRITICAL SECTION
	#pragma omp critical
	{
		buffer[last_item_position] = NULL;
		last_item_position -= 1;
		next_item_position -= 1;
	}
       		
	
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
