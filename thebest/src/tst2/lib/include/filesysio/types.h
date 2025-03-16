#ifndef FSIO_TYPES_H
#define FSIO_TYPES_H

#include <expected>
#include <filesystem>
#include <functional>
#include <optional>
#include <string>

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

using EntryInfo = std::pair<EntryType, EntryType>; // direct type, final type

using SizeType = uint64_t;

}

#endif // FSIO_TYPES_H