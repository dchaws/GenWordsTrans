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

// Takes in S and T as the first two parameters. Outputs all the words S^T.
// Option -L produces all words with no self-loops.

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void printVector (vector <int> &V)
{
    int myWidth = 2;
    for (int i=0;i<V.size()-1;i++)
    {
        cout << setw(myWidth) << V[i] << " ";
    }
    cout << setw(myWidth) << V[V.size()-1] << endl;
}

// This tries to increase the value of V[position]. 
// Returns 1 on success, and 0 on failure.
// if selfLoops == 1, then it simply tries to add 1.
// if selfLoops == 0, then it will try to find the next 
// largest integer so that there are no selfLoops
int incPosVector (vector <int> &V, int position, int S, int selfLoops)
{
    if(V[position] >= S || V[position] < 0)
    {
        return 0;
    }
    if (selfLoops == 1)
    {
        V[position] = V[position] + 1;
        return 1;
    }
    else if (selfLoops == 0)
    {
        int oldValue = V[position];
        V[position] = V[position] + 1;
        if (position == 0)
        {
            while (V[position+1] == V[position])
            {
                V[position] = V[position] + 1;
                if (V[position] > S)
                {
                    V[position] = oldValue;
                    return 0;
                }
            }
        }
        else if (position == V.size()-1)
        {
            while (V[position-1] == V[position])
            {
                V[position] = V[position] + 1;
                if (V[position] > S)
                {
                    V[position] = oldValue;
                    return 0;
                }
            }
        }
        else 
        {
            while (V[position+1] == V[position] || V[position-1] == V[position])
            {
                V[position] = V[position] + 1;
                if (V[position] > S)
                {
                    V[position] = oldValue;
                    return 0;
                }
            }
        }
        return 1;
    }

}

// Takes in a vector V and increments it to the next
// lexicographic vector. S is the upper limit on the vector values.
// E.g. 111 -> 112 -> 113 -> 121 -> 122 -> 123 -> 131
// Returns 1 on success, 0 on failure.
// selfLoops == 1 means allow selfLoops. 0 not
int nextVector (vector <int> &V, int position, int S, int selfLoops)
{
    //cout << "[nextVector]: position = " << position << ", S = " << S << "    "; printVector(V);

    if (position > V.size() || position < 0)
    {
        return 0;
    }

    // Try to increase position.
    if (incPosVector (V,position,S,selfLoops))
    {
        return 1;
    }

    // Failed to increase if we get here.
    if (position == 0)
    {
        return 0;
    }

    // Temporarily set to -1
    V[position] = -1;
    if (nextVector(V,position-1,S,selfLoops) == 0)
    {
        return 0;
    }

    if (selfLoops == 1)
    {
        V[position]=1;
    }
    else
    {
        if (V[position-1] == 1)
        {
            V[position]=2;
        }
        else
        {
            V[position]=1;
        }
    }
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

    for (int i=3;i<argc;i++)
    {
        if (!strcmp(argv[i],"-L"))
        {
            selfLoops = 0;
        }
    }

    //cout << "S = " << S << ", T = " << T << ", selfLoops = " << selfLoops << endl;

    vector <int> V;
    for (int i=0;i<T;i++)
    {
        V.push_back(1 + (1 - selfLoops)*(i % 2));
    }

    do
    {
        printVector(V);
    }
    while(nextVector(V,T-1,S,selfLoops));

}
