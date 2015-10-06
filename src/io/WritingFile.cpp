#include "slim/io/WritingFile.hpp"

namespace slim
{
namespace io
{

WritingFile::WritingFile(const char* name) :
    File(name)
{
}

WritingFile::~WritingFile() noexcept(false)
{
}

}
}
