#include "lib.h"

#include <iostream>
#include <algorithm>

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

using lines_of_IPs = vector<vector<char>>;

lines_of_IPs ConfigureInput(){
    lines_of_IPs storage; 
    string buf;
    //creating a storage of strings, which contain IPs
    size_t len;
    while (getline(cin, buf)){
        vector<string> tmp = split(buf, '\t');
        for (auto el : tmp) {
            vector<string> tmp1 = split(el, '.');
            vector<char> v;
            transform(tmp1.begin(), tmp1.end(), back_inserter(v), [](string& s){
                return stoi(s); });
            if(tmp1.size() == 4)    storage.push_back(v);
        }
    }
    return storage;
}

void PrintIf(function<bool(std::vector<char>)> cond, const lines_of_IPs& input){
    for(const auto& el : input){
        if(cond(el)){
            size_t size = el.size();
            for (auto i = 0; i < size; ++i){
                cout << int(el[i]);
                if(i!=size-1) cout << ".";
            }
            cout << '\n';
        }
    }
}
