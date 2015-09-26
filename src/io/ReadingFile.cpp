#include "slim/io/ReadingFile.hh"

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
