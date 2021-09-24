#include "lib.h"

#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> SortInput(){
    vector<vector<string>> storage; 
    string buf;
    vector<string> tmp;
    //creating a storage of strings, which contain IPs
    size_t len;
    while(getline(cin, buf)){
        while((len = buf.find_first_of("\t"))!=string::npos){
            len += 1;
            auto front = buf.begin();
            tmp.push_back(buf.substr(len));
            buf.erase(front, front + len);
        }
        tmp.push_back(buf);
        storage.push_back(tmp);
        tmp.clear();
    }
    //sorting it backwards
    for(auto el : storage){
        sort(el.rbegin(), el.rend());
    }
    return storage;
}