/// program to show cli args
#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <iterator>
#include <cassert>
#include <stdexcept>

template <class T>

/// function to cout vector retained from previous
void cout_vector(const std::vector<T>& vec)
{
    std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<T>(std::cout, " "));
}

/// main program
int main(int argc, char* argv[])
{
    // convert argv to string retained from previous
    std::vector<std::string> cliArgs(argv, argv + argc);

    // check if any arguments
    //cout_vector(cliArgs);
    if(cliArgs.size() == 1) exit(EXIT_FAILURE);

    // check function
    assert(std::stoi("123") == 123);

    // handle exceptions
    try {
        std::stoi(cliArgs[1]);
        //assert("Should not get here"); // what is this line even for
    }
    catch (const std::invalid_argument&)
    {
        std::cerr << "not a num arg to stoi\n";
        exit(EXIT_FAILURE);
    }
    catch (const std::out_of_range&)
    {
        std::cerr << "num too big for stoi\n";
        exit(EXIT_FAILURE);
    }

    // print for even
    std::cout << (std::stoi(cliArgs[1]) % 2 == 0 ? "false": "true") << "\n";

    return 0;
}
