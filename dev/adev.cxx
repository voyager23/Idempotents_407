/*
 * adev.cxx
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


#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char **argv)
{
	uint64_t mod, a;
	
	for(mod = 999000; mod != 998500; --mod) {
		for(a = mod-1;  a != 0; --a) {
			if((a * a % mod) == a) {
				cout << "M(" << mod << ") = " << a << endl;
				break;
			}
		}
	}
	return 0;
}