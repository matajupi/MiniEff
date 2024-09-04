#include <iostream>
#include <cstdlib>

#include "parser/driver.h"
#include "eval/interpreter.h"

int main(int argc, char **argv) {
    Driver drv;
    Interpreter itp;
    if (argc >= 2 && !drv.Parse(argv[1])) {
        itp.Eval(drv.GetResult());
    }
    return EXIT_SUCCESS;
}
