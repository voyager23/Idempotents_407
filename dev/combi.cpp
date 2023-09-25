#include "combinations.hpp"
#include "combinations_init.hpp"
using namespace boost::combinations;

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename Iter>
void out (Iter first, Iter middle, Iter last)
{
	for (Iter i = first; i != middle; ++i)
		cout << "\t" << *i;

	if (middle != last)
	{
		cout << "\t[" << *middle;
		for (Iter i = middle; ++i != last;)
			cout << "\t" << *i;
		cout << "]";
	}
	cout << endl;
}

template <typename Iter>
uint64_t product (Iter first, Iter middle, Iter last)
{
	uint64_t p = 1;
	for (Iter i = first; i != middle; ++i)
		p *= *i;
	return p;
}

int main ()
{
	//char a[5] = {'a', 'b', 'c', 'd', 'e'};
	//int a[5] = {2,3,7,37,613};
	const uint64_t modulus = 4999998;
	const uint64_t a2 = 4694589;
	cout << "base modulus:" << modulus << endl;
	uint64_t a[8] = {3,3,91,2731,2,2,269,4363};
	uint64_t k = 4, n = 8;

	// initialize to the smallest sequence
	init_combination (a, a + k, a + n, false);
	
	vector<uint64_t> v = {};
	// generate loop
	do
	{
		// use the sequence
		//out (a, a + k, a + n);
		uint64_t p = product(a, a + k, a + n) ;
		if ((p <= modulus*2)&&(p >= modulus)) {
		//cout << "Candidate modulus:" << p << endl;
		v.push_back(p);
		}

	}
	// generate to next sequence, and judge whether end
	while (prev_combination (a, a + k, a + n));
	
	sort(v.begin(), v.end());
	for(uint64_t &i : v){
		cout << i << " ";
		if((((uint64_t)(a2)*(uint64_t)(a2 - 1))%i)==0) cout << "solution";
		cout << endl;
	}
}

