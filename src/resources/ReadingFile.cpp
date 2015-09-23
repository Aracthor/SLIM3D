#include "slim/resources/ReadingFile.hh"

namespace slim
{
namespace resources
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
