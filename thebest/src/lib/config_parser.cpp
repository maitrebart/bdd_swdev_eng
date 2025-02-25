#include "config_parser.h"

#ifdef USE_FILESYSIO_LIB
#include "filesysio/facade.h"
#include "filesysio/ifile_service.h"
#endif

#include <fstream>

namespace fio = FileSysIo;

namespace TheBest
{

std::expected<bool,std::string> ConfigParser::parse(std::filesystem::path path)
{
    std::expected<bool,std::string> result;
    std::ifstream configFile(path.string());
    bool ok(configFile.is_open());
    if (ok)
    {
        for (std::string line; std::getline(configFile, line); )
            std::cout << line << "\n";
        result = true;
    }
    else
    {
        result = std::unexpected("Could not open file: " + path.string());
    }
    return result;
}

#ifdef USE_FILESYSIO_LIB
std::expected<bool,std::string> ConfigParser::parse2(std::filesystem::path path, fio::IFileService& fileService)
{
    std::expected<bool,std::string> result;
    auto error = fileService.read(path, 
        [](fio::IFileService::RwInfo lineInfo)
        {
            if (!lineInfo.isEof || !lineInfo.line.empty())
                std::cout << lineInfo.line << "\n";
            return true;
        });
    if (error)
    {
        return std::unexpected("Could not open file: " + path.string());
    }
    return true;
}
#endif

} // namespace TheBest
