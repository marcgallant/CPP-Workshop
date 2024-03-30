#include <iostream>

#include "unix_path.hh"
#include "windows_path.hh"

int main()
{
    auto windows_path = WindowsPath('E');

    std::cout << windows_path.join("Users").join("YAKA").join("cpp").to_string()
              << '\n';

    auto unix_path = UnixPath();

    std::cout << unix_path.join("home").join("yaka").join("cpp").to_string()
              << '\n';

    std::cout << unix_path.join("main1.cc", true).to_string() << '\n';

    return 0;
}
