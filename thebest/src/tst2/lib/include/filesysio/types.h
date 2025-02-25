#ifndef FSIO_TYPES_H
#define FSIO_TYPES_H

#include <filesystem>
#include <string>
#include <functional>
#include <expected>
#include <optional>

namespace FileSysIo
{

enum class EntryType : int
{
   Unsupported = -1,
   File,
   Dir,
   Pipe,
   Link
};

using EntryInfo = std::pair<EntryType,EntryType>; // direct type, final type

using SizeType = uint64_t;

}

#endif // FSIO_TYPES_H