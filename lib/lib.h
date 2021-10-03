#pragma once

#include <string>
#include <vector>
#include <functional>

using lines_of_IPs = std::vector<std::vector<std::vector<std::string>>>;

lines_of_IPs ConfigureInput();

void PrintIf(std::function<bool(std::vector<std::string>)>, const lines_of_IPs&);
