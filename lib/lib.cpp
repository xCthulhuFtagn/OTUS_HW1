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

vector<vector<vector<string>>> SortInput(){
    vector<vector<vector<string>>> storage; 
    string buf;
    //creating a storage of strings, which contain IPs
    size_t len;
    for (size_t i = 0; getline(cin, buf); ++i){
        storage.resize(i + 1);
        vector<string> tmp = split(buf, '\t');
        for (auto el : tmp) storage[i].push_back(split(el, '.'));
        sort(storage[i].rbegin(), storage[i].rend());
    }
    //sorting it backwards
    return storage;
}