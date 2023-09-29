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

int main(int argc, char **argv)
{
	// Output goes to std::out
	system("git symbolic-ref --short HEAD");
    
    // setup the factorisation functions
    vector<uint64_t> primes;
    SieveOfEratosthenes(primes, 1000000);
    
	vector<uint64_t> factors;
	vector< vector<uint64_t> > combinations;
 	
 	// Here n > 1
 	for(uint64_t n : {13,14,15,1155}) {
		cout << "n:" << n << endl;
		find_factors(primes, n, factors);
		combinations.clear();
		
		combinations.push_back(factors);
		while(next_permutation(factors.begin(), factors.end())) {
			combinations.push_back(factors);
		}
		// print the combinations
		//~ for(auto &c : combinations) {
			//~ for(auto &d : c) cout << d << " ";
			//~ cout << endl;
		//~ }
		//~ cout<<endl;
		
		set< vector<uint64_t> > combs;
		for(int l = 0; l != factors.size(); l++) {
			combs.clear();
			for(auto &c : combinations) {
				vector<uint64_t> d = {c.begin(), c.begin()+l+1};
				sort(d.begin(), d.end());
				combs.insert(d);
				
			}
			// print combs
			for(auto &c : combs) {
				for(auto &d : c) cout << d << " ";
				cout << endl;
			}
			//cout<<endl;
		}
	}
	
	
		
	return 0;
}

