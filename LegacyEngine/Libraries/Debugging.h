#pragma once

#ifdef LEGACY_DEBUG
#include <iostream>

#define LOG(x) std::cout << x << std::endl;							// print to console

#endif // !LEGACY_DEBUG