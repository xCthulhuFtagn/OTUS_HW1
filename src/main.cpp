#include <lib.h>
//no need to include vector or string, because they're included to lib.h
#include <iostream>

using namespace std;

int main(){ 
    vector<vector<string>> ans;
    ans = SortInput();
    for(auto line : ans){
        for(auto el : line){
            cout << el << "\t";
        }
        cout<<endl;
    }
}