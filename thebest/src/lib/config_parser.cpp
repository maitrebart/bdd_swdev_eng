#include "config_parser.h"

#include <fstream>

namespace TheBest
{

std::expected<bool,std::string> ConfigParser::parse(std::filesystem::path path)
{
    std::expected<bool,std::string> result;
    std::ifstream configFile(path.string());
    bool ok(configFile.is_open());
    if (ok)
    {
        //...
        result = true;
    }
    else
    {
        result = std::unexpected("Could not open file: " + path.string());
    }
    return result;
}

} // namespace TheBest
