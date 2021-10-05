#include "lib.h"

#include <iostream>

using namespace std;

vector<string> split(string input, char delim){
    size_t len;
    vector<string> ans;
    while((len = input.find_first_of(delim, 0))!=string::npos){
        auto front = input.begin();
        ans.push_back(input.substr(0, len));
        input.erase(front, front + len + 1);
    }
    ans.push_back(input);
    return ans;
}

using lines_of_IPs = vector<vector<vector<string>>>;

lines_of_IPs ConfigureInput(){
    lines_of_IPs storage; 
    string buf;
    //creating a storage of strings, which contain IPs
    size_t len;
    for (size_t i = 0; getline(cin, buf); ++i){
        storage.resize(i + 1);
        vector<string> tmp = split(buf, '\t');
        for (auto el : tmp) {
            vector<string> tmp1 = split(el, '.');
            if(tmp1.size() == 4)    storage[i].push_back(tmp1);
        }
    }
    return storage;
}

void PrintIf(function<bool(std::vector<std::string>)> cond, const lines_of_IPs& input){
    for(auto line : input){
        for(auto el : line){
            if(cond(el)){
                size_t size = el.size();
                for (auto i = 0; i < size; ++i){
                    cout << el[i];
                    if(i!=size-1) cout << ".";
                }
                cout << '\n';
            }
        }
    }
}
