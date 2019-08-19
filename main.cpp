/// program to show cli args
#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <iterator>
#include <cassert>

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

  // convert string to int section
  // check the function works
  assert(std::stoi("123") == 123);

  std::cout << cliArgs[1];
  // try to convert and handle exceptions
  try {
      std::stoi(cliArgs[1]);
      assert(!"this is not an integer");
  } catch (const std::invalid_argument&) {
    assert("this is okay");
  }

  // print vector
  cout_vector(cliArgs);

  return 0;
}
