#include <iostream>
#include <string>

std::string sliceString (const std::string &str)
{
  return str.substr(1, str.length() - 2);
}

int main(int argc, char const *argv[])
{
    std::cout << (sliceString("country") =="ountr") << '\n';
    std::cout << (sliceString("place") =="lac") << '\n';
    std::cout << (sliceString("translation") =="ranslatio") << '\n';

    return 0;
}
