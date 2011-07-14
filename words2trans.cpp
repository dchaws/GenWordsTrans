// DrawStateMoveGraphs is for drawing state and move graphs of Markov chains.
// Copyright (C) 2011 David C. Haws

//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

// See LICENSE

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;



int main (int argc, char *argv[])
{
    if (argc < 3)
    {
        // Usage message here.
        exit(0);
    }

    int S = atoi(argv[1]);
    int T = atoi(argv[2]);
    int selfLoops = 1; // 1 means allow self-loops, 0 not.

    for (int i=3;i<argc;i++)
    {
        if (!strcmp(argv[i],"-L"))
        {
            selfLoops = 0;
        }
    }

    cout << "S = " << S << ", T = " << T << ", selfLoops = " << selfLoops << endl;

    
    
}
