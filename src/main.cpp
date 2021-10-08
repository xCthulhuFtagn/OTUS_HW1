#include "lib.h"
//no need to include vector or string, because they're included to lib.h
#include <iostream>
#include <algorithm>

using namespace std;

int main(){ 
    vector<vector<int>> ans = ConfigureInput();
    sort(ans.rbegin(), ans.rend());
    auto cond1 = [](const vector<int>& input) {return true;};
    PrintIf(cond1, ans);
    auto cond2 = [](const vector<int>& input) {return input[0] == 1;};
    PrintIf(cond2, ans);
    auto cond3 = [](const vector<int>& input) {return input[0] == 46 && input[1] == 70;};
    PrintIf(cond3, ans);
    auto cond4 = [](const vector<int>& input) {
        return any_of(input.begin(), input.end(), [](const char& x) {return x == 46;});
    };
    PrintIf(cond4, ans);
}