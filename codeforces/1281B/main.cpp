#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>

using namespace std;

int nProblems = 0;

int comp(string str1, string str2) {
    int n = min(str1.size(), str2.size());
    for(int i = 0; i<n; i++) {
        if(str1[i] < str2[i]) {
            return -1;
        }
        if(str1[i] > str2[i]) {
            return 1;
        }
    }
    return 0;
}



string compute_string_reordered(string str1, string str2) {
    // find first character below
    int first_below = 0;
    int n = min(str1.size(), str2.size());
    char chr_to_swap = '\0';
    int ordered = 1;

    if(comp(str1, str2) == 0 && str1.size() >= str2.size()) {
        return "---";
    } 

    while(first_below < n) {
        if(str1[first_below] < str2[first_below]) {            
            break;
        }
        if(str1[first_below] > str2[first_below]) {            
            chr_to_swap = str2[first_below];
            ordered = 0;
            break;
        }
        first_below++;
    }


    if(ordered == 1) {
        return str1;
    }


    // find character to swap
    int search = first_below+1;
    while(search < str1.size()) {
        if(str1[search] <= chr_to_swap) {
            char tmp = str1[first_below];
            str1[first_below] = str1[search];
            str1[search] = tmp;
            return str1;
        }
        search ++;
    }

    return "---";


}


int main()
{
    cin >> nProblems;
    for(int i=0; i<nProblems; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        cout << compute_string_reordered(str1, str2) << endl;
    }
}
