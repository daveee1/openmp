#include <iostream>
//using namespace std;
using std::cout;	// i just import cout, not all the package
using std::endl;
#include <random>




const int N = 8;	// size of the dictionary



void mapping(int S[])
{
	
}

// function that creates an hash function pairwise independent
int _2_family_hash(int x, int a, int b)
{
	return (a * x + b) % N;
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

void print_dictionary(int S[N])
{
	cout << "Printing my dictionary" << endl;
	for(int i=0; i<N ;i++)
		cout << S[i] << " ";
	
	cout << endl;
}

void fill_dictionary(int S[N])
{
	for(int i=0; i<N; i++)
		S[i] = generate_randomness();
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

	int S[N] = {};
	fill_dictionary(S);
	print_dictionary(S);




	return 0;
}
