
	//this is a simple approach to PERFECT_HASHING TWO LEVEL APPROACH
	// i want to see for real how such implementation
	// works in reality
	
#include <iostream>
#include <random>
using std::cout;	// i just import cout, not all the package



const int N = 20;	// size of the dictionary
int a, b;		// hash function parameters FIRST LEVEL




// function that creates a pairwise independent hash function
int _2_hash_family(int x)
{
	int size_hash = N/4; // as example TODO
	return (a * x + b) % size_hash;
}



// HASH-TABLE
// FIRST LEVEL APPROACH
class HASH_TABLE{
	//elements
	private:
	       	struct Entry{
			int key;     
			Entry *next;
		};

		Entry **h_table;
		const int size_hash = N/4;

	public:
		explicit HASH_TABLE();
		~HASH_TABLE();
		void insert(int key);
		void print_hashtable();
		int bin_size(int index);
		int size_HASH_TABLE();
};


HASH_TABLE::HASH_TABLE()
{
	h_table = new Entry*[size_hash];
	for (int i=0; i < size_hash; i++)
		h_table[i] = nullptr;
}


HASH_TABLE :: ~HASH_TABLE()
{
	for(int i=0; i < size_hash; i++)
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

int HASH_TABLE :: size_HASH_TABLE(){ return size_hash;}

void HASH_TABLE :: print_hashtable()
{
	cout << "\n ******************************\nPrinting hash table";
	for(int i=0; i<size_hash; i++){
		Entry *curr_bin_pos_i = h_table[i];
		cout << "\n bin " << i << ":   ";
		while (curr_bin_pos_i){
			cout << curr_bin_pos_i->key << " ";
			Entry *next = curr_bin_pos_i->next;
			curr_bin_pos_i = next;	
		}
	}
}


// returns the size of this bin
int HASH_TABLE :: bin_size(int index)
{
	Entry *curr_bin = h_table[index];
	int counter = 0;
	while(curr_bin->next){
		curr_bin = curr_bin->next;
		counter++;
	}
	return counter;
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


class _2_level_HASH_TABLE : public HASH_TABLE 
{
	private:
		HASH_TABLE h;
		
	public:
		explicit _2_level_HASH_TABLE();
		~ _2_level_HASH_TABLE();
		void insert_bin_into_second_HASH_TABLE(HASH_TABLE h);
};


// TODO how to implement the second level hash?
// i need to create another hash_table: each bin of the first level will point 
// into the second level.
void _2_level_HASH_TABLE :: insert_bin_into_second_HASH_TABLE(HASH_TABLE h)
{
	// i take one bin: for that bin i create a separate hash table
	for(int i=0; i < h.size_HASH_TABLE(); i++){
		Entry *curr_bin = h[i];
		
	}	
}



// modern approach to generate rnd numbers in [0, 99]
int generate_randomness(){
	// modern approach to randomness
	std::random_device rd; // obtain a random number from hardware
 	std::mt19937 gen(rd()); // seed the generator
    	std::uniform_int_distribution<> distr(0, 99); // define the range
	return distr(gen);
}


void print_dictionary(int S[], int length)
{
	for(int i=0; i < length; i++)
		cout << "value: " << S[i] << ", hashed: " << _2_hash_family(S[i]) << "\n";
}

void fill_dictionary(int S[], int length)
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
	cout << "\n\nPrinting my dictionary S\n";
	print_dictionary(S, length_S);
	
	// setting Universe
	int U[2] = {};
	int length_U = sizeof(U) / sizeof(int);
	fill_dictionary(U, length_U);
	cout << "\n\nPrinting my dictionary U\n";
	print_dictionary(U, length_U);


	HASH_TABLE h;
	for (int i=0; i < N; i++)
		h.insert(S[i]);
	h.print_hashtable();	


	return 0;
}
