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
    assert(argc > 1 && "insufficient arguments");

    // handle exceptions
    try {
        std::stoi(cliArgs[1]);
        assert("this is okay");
    } catch (const std::invalid_argument&)
    {
        return 1;
    } catch (const std::out_of_range&)
    {
        return 1;
    }

    // print for even
    std::cout << (std::stoi(cliArgs[1]) % 2 == 0 ? "true\n": "false\n");

    return 0;
}
