#include <iomanip>
#include <iostream>

#include "parse_csv.hh"

namespace
{

    std::ostream& print_line(std::ostream& os,
                             const std::vector<std::string>& line)
    {
        os << '{';
        if (!line.empty())
        {
            os << std::quoted(line.front());
        }
        for (std::size_t i = 1; i < line.size(); ++i)
        {
            os << ", " << std::quoted(line[i]);
        }
        return os << '}' << std::endl;
    }

    auto try_parse_csv(const std::string& filename)
    {
        try
        {
            return parse_csv(filename);
        }
        catch (const std::exception& e)
        {
            std::cerr << "exception: " << e.what() << std::endl;
            std::exit(1);
        }
    }

} // namespace

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        const std::string program = argc >= 1 ? argv[0] : "main.out";
        std::cerr << "usage: " << program << " <file.csv>" << std::endl;
        return 1;
    }
    const std::string filename{ argv[1] };
    const auto lines = try_parse_csv(filename);
    for (const auto& line : lines)
    {
        print_line(std::cout, line);
    }
    return 0;
}
