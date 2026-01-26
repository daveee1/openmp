#include <iostream>
//using namespace std;
using std::cout;	// i just import cout, not all the package
#include <random>




#define N = 8;	// global variable
#define 



void mapping(int S[])
{
	
	

}

// function that creates an hash function pairwise independent
int _2_family_hash(int x, int a, int b)
{
	return (a*x+b)%n;
}

 

/*
 * modern approach to generate rnd numbers in [0, 99]
 *
 */

int generate_randomness(){

	// modern approach to randomness
	std::random_device rd; // obtain a random number from hardware
 	std::mt19937 gen(rd()); // seed the generator
    	std::uniform_int_distribution<> distr(0, 99); // define the range
	return distr(gen);
}


int main()
{
	//this is a simple approach to PERFECT_HASHING TWO LEVEL APPROACH
	// i want to see for real how such implementation
	// works in reality
	
	// i need:
	// 	1) family of 2 hash functions
	// 	2) two hash tables
	// 	3) dictionary (to be mapped in the hash table, e.g users's pwds)
	// 	4) universe to map

	int i = 0;
	int a = generate_randomness();
	int b = generate_randomness();

	int S[n] = {};
	for (int i=0; i < n; i++){
		S[i] = generate_randomness();
	}	
	


	return 0;
}
