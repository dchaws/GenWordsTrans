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
#include <cstdlib>
#include <string.h>
#include "printvector.h"

using namespace std;

vector <int> readVector (istream &in, int S, int selfLoops)
{
    vector <int> V;
    // First S integers are the initial state

    int x;
    for (int i=0;i<S;i++)
    {
        in >> x;
        V.push_back(x);
    }
    int numTrans;
    if (selfLoops == 1)
    {
        numTrans = S*S;
    }
    else
    {
        numTrans = S*(S-1);
    }
    for (int j=0;j<numTrans;j++)
    {
        in >> x;
        V.push_back(x);
    }

    return V;
}

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
    int printSpaces = 1; // 1 means print spaces between states, 0 not.

    for (int i=3;i<argc;i++)
    {
        if (!strcmp(argv[i],"-L"))
        {
            selfLoops = 0;
        }
        if (!strcmp(argv[i],"-S"))
        {
            printSpaces = 0;
        }
    }

    // Error checking
    if (T < 0 || S < 0)
    {
        cout << "T < 0 || S < 0" << endl;
        exit(0);
    }

    if (T == 1)
    {
        vector <int> V;
        for (int i=0;i<S;i++)
        {
            V.clear();
            for (int j=0;j<S;j++)
            {
                if (i == j)
                {
                    V.push_back(1);
                }
                else
                {
                    V.push_back(0);
                }
            }
            int numTrans;
            if (selfLoops == 1)
            {
                numTrans = S*S;
            }
            else
            {
                numTrans = S*(S-1);
            }
            for (int j=0;j<numTrans;j++)
            {
                V.push_back(0);
            }
            printVector(V,printSpaces);
        }
    }
    else { // T != 1
        // Read a vector from standard input. Depends on selfloops or not.

        do 
        {
            vector <int> V;
            V = readVector(cin,S,selfLoops);
            if (!cin.good())
            {
                exit(0);
            }
            //cout << "ORIGINAL: ";
            //printVector(V,printSpaces);

            int oldInit;
            for (int j=0;j<S;j++)
            {
                if (V[j] == 1)
                {
                    oldInit = j;
                }
                V[j] = 0;
            }
            for (int i=0;i<S;i++)
            {
                if (i != oldInit || selfLoops == 1)
                {
                    V[i] = 1;

                    // Now need to increase transition count for oldInit to i;
                    int position;
                    if (selfLoops == 1)
                    {
                        position = S*i + oldInit;
                    }
                    else
                    {
                        position = (S-1)*i + oldInit;
                        if (i < oldInit)
                        {
                            position--;
                        }
                    }
                    position += S;
                    V[position]++;

                    printVector(V,printSpaces);
                    V[position]--;
                    V[i] = 0;
                }
            }
        } while(cin.good());
    }

}
