/*
 * afindmod.cxx
 * 
 * Copyright 2023 Michael Tate <mike@Michaels-MBP>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include "combinations.hpp"
#include "combinations_init.hpp"
using namespace boost::combinations;

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <cassert>
#include <deque>

#include "../inc/toolbox.hxx"

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

int main(int argc, char **argv)
{
	uint64_t mod, a;
    // ul is defined as uint64_t { 8 bytes } in header toolbox.hxx
    
    // setup the factorisation functions
    vector<uint64_t> primes;
    SieveOfEratosthenes(primes, 10000000);
    
    // initialise the map
    vector<ul> factors = {};
    // Queue structure { a-1, a }
    deque<vector<ul>> a_factors = {};
    
    // declare oversized array for factors
    ul wspace[128];
    int k,n;    // k is middle, n is last {number of factors}
    
    find_factors(primes,1298,factors);
    a_factors.push_back(factors);
    
    find_factors(primes,1278,factors);
    a_factors.push_back(factors);
    
    //cout<<a_factors[0].size()<<endl;
    //cout<<a_factors[1].size()<<endl;
    n = 0;
    for(ul &j : a_factors[0]) wspace[n++] = j;
    for(ul &j : a_factors[1]) wspace[n++] = j;
    // n  is 1 past end {last}
    
    for(k = 3; k != n-1; ++k) { //DEBUG VALUES
        cout << k << endl;
        init_combination(wspace, wspace+k, wspace+n,false);
        do {
            out(wspace, wspace+k, wspace+n);
        } while (prev_combination(wspace, wspace+k, wspace+n));
    }
	return 0;
}
