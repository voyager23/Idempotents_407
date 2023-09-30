/*
 * derive.cxx
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
 * Derive a vector of combinations using the permutations function
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
    
    //~ // setup the factorisation functions
    //~ vector<uint64_t> primes;
    //~ SieveOfEratosthenes(primes, 1000000);
    
	vector<uint64_t> src = {3,5,5,7,11,13,17};
	set<vector<uint64_t>> combinations;
	combine(src, combinations);
	for(auto &c : combinations) {
		uint64_t m = 1;
		for(auto &d : c) {
			cout << d << " ";
			m *= d;
		}
		cout << "  =>  " << m << endl;
	}
		
	return 0;
}

