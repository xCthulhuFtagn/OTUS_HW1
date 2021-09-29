#include <lib.h>
//no need to include vector or string, because they're included to lib.h
#include <iostream>

using namespace std;

int main(){ 
    vector<vector<vector<string>>> ans;
    ans = SortInput();
    for(auto line : ans){
        for(auto el : line){
            size_t size = el.size();
            for (auto i = 0; i < size; ++i){
                cout << el[i];
                if(i!=size-1) cout << ".";
            }
            cout << '\t';
        }
        cout<<endl;
    }
}