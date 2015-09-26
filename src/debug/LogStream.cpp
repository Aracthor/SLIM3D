#include "slim/core/attributes.h"
#include "slim/debug/assert.hh"
#include "slim/debug/LogStream.hh"
#include "slim/debug/Log.hh"
#include "slim/io/maccros.h"

namespace slim
{
namespace debug
{

const char*
LogStream::s_levels[4] = {"LOG", "INFO", "WARNING", "ERROR"};


LogStream::LogStream(Log* log, const char* name, unsigned int level) :
    m_log(log),
    m_name(name),
    m_level(level)
{
    this->prepareNextLine();
}

LogStream::~LogStream()
{
}


LogStream&
LogStream::operator<<(ESpecialData data)
{
    SLIM_CORE_USE(data);
    SLIM_DEBUG_ASSERT(data == LogStream::endline);

    m_buffer << SLIM_IO_ENDLINE_STR;
    m_buffer[m_buffer.getSize()] = '\0';
    m_log->write(m_buffer.getData(), m_buffer.getSize(), m_level);
    this->prepareNextLine();

    return *this;
}


void
LogStream::prepareNextLine()
{
    m_buffer.clear();
    m_buffer << '[' << m_name << "] [" << s_levels[m_level] << "] ";
}

}
}
