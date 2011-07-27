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


#include "printvector.h"

void printVector (vector <int> &V, int printSpaces)
{
    int myWidth = 2;
    for (int i=0;i<V.size()-1;i++)
    {
        if (printSpaces == 1)
        {
            cout << setw(myWidth) << V[i] << " ";
        }
        else if (printSpaces == 0)
        {
            cout << V[i];
        }
    }
    if (printSpaces == 1)
    {
        cout << setw(myWidth) << V[V.size()-1] << endl;
    }
    else if (printSpaces == 0)
    {
        cout << V[V.size()-1] << endl;
    }
}
