#include <lib.h>
//no need to include vector or string, because they're included to lib.h
#include <iostream>

using namespace std;

int main(){ 
    vector<vector<string>> ans;
    ans = SortInput();
    for(auto line : ans){
        for(auto el : line){
            for (auto i = 0; i < el.size(); ++i){
                cout << el[i];
                if(i>0) cout << ".";
            }
            cout << '\t';
        }
        cout<<endl;
    }
}