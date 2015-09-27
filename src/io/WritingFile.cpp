#include "slim/io/WritingFile.hh"

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
