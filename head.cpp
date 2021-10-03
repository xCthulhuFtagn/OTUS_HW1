#include "head.h"
#include "config.h"

#include <iostream>

void PrintVersion(){
    std::cout << "Version: " << (PROJECT_VERSION_PATCH) << std::endl;
}