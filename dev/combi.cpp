#include "combinations.hpp"
#include "combinations_init.hpp"
using namespace boost::combinations;

#include <iostream>
#include <cstdint>
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
  const uint64_t modulus = 998503;
  cout << "modulus:" << modulus << endl;
  uint64_t a[8] = {2,3,7,11,2111,37,43,613};
  uint64_t k = 3, n = 8;

  cout << endl
       << "select 3 from 5, descending sequence"
       << endl;
  // initialize to the smallest sequence
  init_combination (a, a + k, a + n, false);
  
  // generate loop
  do
    {
      // use the sequence
      //out (a, a + k, a + n);
      uint64_t p = product(a, a + k, a + n) ;
      if ((p < modulus) && (p > modulus/2))
		cout << "Candidate a:" << p << endl;
      
    }
  // generate to next sequence, and judge whether end
  while (prev_combination (a, a + k, a + n));
}
