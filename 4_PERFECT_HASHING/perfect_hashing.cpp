
	//this is a simple approach to PERFECT_HASHING TWO LEVEL APPROACH
	// i want to see for real how such implementation
	// works in reality
	
#include <iostream>
#include <random>
using std::cout;	// i just import cout, not all the package




const int N = 8;	// size of the dictionary
int a, b;		// hash function parameters




// function that creates an hash function pairwise independent
int _2_hash_family(int x)
{
	return (a * x + b) % N;
}



// HASH-TABLE
class HASH_TABLE{
	//elements
	private:
	       	struct Entry{
			int key;     
			Entry *next;
		};

		Entry **h_table;
		
	public:
		explicit HASH_TABLE();
		~HASH_TABLE();
		void insert(int key);
		void erase();
	
};


HASH_TABLE::HASH_TABLE()
{
	h_table = new Entry*[N];
	for (int i=0; i<N; i++)
		h_table[i] = nullptr;
}

HASH_TABLE :: ~HASH_TABLE()
{
	for(int i=0; i<N; i++)
	{
		Entry *curr = h_table[i]; //pointer to current bin first element
		while (curr)
		{
			Entry *next = curr->next;
			delete curr;
			curr = next;
		}
	}
	delete [] h_table;
} 	


void HASH_TABLE :: insert(int key)
{
	// BASE CASE: first element inserted in this bin
	Entry *curr = h_table[_2_hash_family(key)]; //load the first element in the selected bin by the hash function
	if (curr == nullptr){
		h_table[_2_hash_family(key)] = new Entry{key, nullptr};
		return;
	}
	
	while (curr->next){
		curr = curr->next;
	}
	curr->next = new Entry{key, nullptr};
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
