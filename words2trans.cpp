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

// Takes in S and T as the first two parameters. Outputs all the words S^T.
// Option -L produces all words with no self-loops.
// Option -S produces words with no spaces between the states

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <string.h>

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
    int initial = 0;

    for (int i=3;i<argc;i++)
    {
        if (!strcmp(argv[i],"-L"))
        {
            selfLoops = 0;
        }
        if (!strcmp(argv[i],"-I"))
        {
            initial = 1;
        }
    }

    //cout << "S = " << S << ", T = " << T << ", selfLoops = " << selfLoops << endl;

    
    int transitions[S][S];

    string input;
    cin >> input;
    while(cin.good())
    {
        // Zero out transitions
        for (int i=0;i<S;i++)
        {
            for (int j=0;j<S;j++)
            {
                transitions[i][j] = 0;
            }
        }

        int prevState = -1;
        for (int i=0;i<T;i++)
        {
            int curState = atoi(input.c_str());
            //cout << input << endl;
            if (prevState != -1)
            {
                //cout << "prevState = " << prevState << ", curState = " << curState << endl;
                transitions[prevState-1][curState-1]++;
            }
            else
            {
                if (initial == 1)
                {
                    for (int j=0;j<curState-1;j++)
                    {
                        cout << setw(3) << 0 << " "; 
                    }
                    cout << setw(3) << 1 << " ";
                    for (int j=curState;j<S;j++)
                    {
                        cout << setw(3) << 0 << " "; 
                    }
                }
            }
            prevState = atoi(input.c_str());
            cin >> input;
        }

        for (int i=0;i<S;i++)
        {
            for (int j=0;j<S;j++)
            {
                if (i != j || selfLoops == 1)
                {
                    cout << setw(3) << transitions[i][j] << " ";
                }
            }
        }
        cout << endl;
        
    }
     
}
