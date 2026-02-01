
	//this is a simple approach to PERFECT_HASHING TWO LEVEL APPROACH
	// i want to see for real how such implementation
	// works in reality
	
#include <iostream>
//using namespace std;
using std::cout;	// i just import cout, not all the package
#include <random>




const int N = 8;	// size of the dictionary
int a, b;		// hash function parameters


// HASH-TABLE

class HASH_TABLE{
	//elements
	private:
	       	struct Entry{
			int *key;
			int *values;
			
		}


}






void mapping(int S[])
{
	// now we need an hash table of hash tables
	
}




// function that creates an hash function pairwise independent
int _2_hash_family(int x)
{
	return (a * x + b) % N;
}

 


// modern approach to generate rnd numbers in [0, 99]
int generate_randomness(){
	// modern approach to randomness
	std::random_device rd; // obtain a random number from hardware
 	std::mt19937 gen(rd()); // seed the generator
    	std::uniform_int_distribution<> distr(0, 99); // define the range
	return distr(gen);
}




void print_dictionary(int S[N], int length)
{
	cout << "\n\nPrinting my dictionary\n";
	for(int i=0; i < length; i++)
		cout << "value: " << S[i] << " " << _2_hash_family(S[i]) << "\n";
}

void fill_dictionary(int S[N], int length)
{
	for(int i=0; i < length; i++)
		S[i] = generate_randomness();
}

int main()
{
	// i need:
	// 	1) family of 2 hash functions
	// 	2) two hash tables
	// 	3) dictionary (to be mapped in the hash table, e.g users's pwds)
	// 	4) universe to map

	// hash function parameters
	a = generate_randomness();
	b = generate_randomness();


	// setting Static Dictionary
	int S[N] = {};
	int length_S = N;
	fill_dictionary(S, length_S);
	print_dictionary(S, length_S);
	
	// setting Universe
	int U[2] = {};
	int length_U = sizeof(U) / sizeof(int);
	fill_dictionary(U, length_U);
	print_dictionary(U, length_U);


	return 0;
}
