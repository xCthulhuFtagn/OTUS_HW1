#include "lib.h"

#include <iostream>
#include <algorithm>

using namespace std;

vector<string> split(string input, char delim){
    size_t len;
    vector<string> ans;
    while((len = input.find_first_of("\t"))!=string::npos){
        len += 1;
        auto front = input.begin();
        ans.push_back(input.substr(len));
        input.erase(front, front + len);
    }
    ans.push_back(input);
    return ans;
}

vector<vector<string>> SortInput(){
    vector<vector<string>> storage; 
    string buf;
    //creating a storage of strings, which contain IPs
    size_t len;
    while(getline(cin, buf)){
        vector<string> tmp = split(buf, '.');
        storage.push_back(tmp);
    }
    //sorting it backwards
    for(auto el : storage){
        sort(el.rbegin(), el.rend());
    }
    return storage;
}