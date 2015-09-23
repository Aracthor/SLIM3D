#include "slim/resources/WritingFile.hh"

namespace slim
{
namespace resources
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
