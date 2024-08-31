#include <iostream>
#include <cstdlib>

#include "parser/driver.h"

int main(int argc, char **argv) {
    Driver drv;
    if (argc >= 2 && !drv.Parse(argv[1])) {
        drv.GetResult()->Dump(std::cout);
    }
    return EXIT_SUCCESS;
}
