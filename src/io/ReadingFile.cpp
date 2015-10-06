#include "slim/io/ReadingFile.hpp"

namespace slim
{
namespace io
{

ReadingFile::ReadingFile(const char* name) :
    File(name)
{
}

ReadingFile::~ReadingFile() noexcept(false)
{
}

}
}
