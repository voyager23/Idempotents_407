/*
 * mod_search.cxx
 * 
 * Copyright 2023 Mike <mike@pop-os>
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "../inc/toolbox.hxx"

using namespace std;

void combine(vector<uint64_t> &src, set<vector<uint64_t>> &comb);

void combine(vector<uint64_t> &src, set<vector<uint64_t>> &comb) {
	// enumerate all valid combinations of src - save in set combinations
	 
	vector< vector<uint64_t> > perms;
	
	// enumerate and save all permutations of src in 'perms'	
	perms.clear();	
	perms.push_back(src);
	while(next_permutation(src.begin(), src.end())) {
		perms.push_back(src);
	}
	
	// 
	comb.clear();
	for(int l = 0; l != src.size(); l++) {
		for(auto &p : perms) {
			vector<uint64_t> d = {p.begin(), p.begin()+l+1};
			sort(d.begin(), d.end());
			comb.insert(d);	// silent fail if already in set
		}
	} // next length
	// set comb now holds vectors of all valid combinations	
}

int main(int argc, char **argv)
{
	// consider values of a in range 100 -> 199
	// possible values for a modulus  100 < modulus < 400 {2*a}
	uint64_t a,a1,m;
	vector<uint64_t> factors_a;
	vector<uint64_t> factors_a1;
	
    // setup the factorisation functions
    vector<uint64_t> primes;
    SieveOfEratosthenes(primes, 1000000);
    
	set<vector<uint64_t>> combinations;
	for(a = 100; a != 200; ++a) {
		a1 = a - 1;
		find_factors(primes, a, factors_a);
		find_factors(primes, a1, factors_a1);
		
		// concatenate a and a1		
		factors_a.insert(factors_a.end(), factors_a1.begin(), factors_a1.end());
		set<vector<uint64_t>> comb;
		sort(factors_a.begin(), factors_a.end());
		combine(factors_a, comb);
		// make and sort a set/list of each multiple
		// select multiples in range a+1 => 2*a
		for(auto &c : comb) {
			uint64_t m = 1;
			for(auto &d : c) m *= d;
			if ((m > a) && (m < 2*a)) {
				cout << "solution m:" << m << " a:" << a << endl;
			}
		}
		// TODO ?sort primary results on modulus?
	}
		
			
	return 0;
}

