#include "slim/assets/SingleFileAsset.hpp"
#include "slim/containers/Buffer.hpp"
#include "slim/debug/LogManager.hpp"
#include "slim/io/macros.h"

namespace slim
{
namespace assets
{

SingleFileAsset::SingleFileAsset(const char* const type, const char* const name, const char* const file) :
    Asset(type, name),
    m_file(file)
{
}

SingleFileAsset::SingleFileAsset(const SingleFileAsset& reference) :
    Asset(reference),
    m_file(reference.getFile())
{
}

SingleFileAsset::~SingleFileAsset()
{
}


bool
SingleFileAsset::loadData(const char* const path)
{
    containers::Buffer<char, SLIM_ASSETS_MAX_PATH_SIZE>	buffer;
    bool						success;

    buffer << path << m_file << '\0';

    debug::LogManager::instance.assets.info << "Loading " << this->getType() << " file \"" << buffer.getData() << "\"..." << debug::LogStream::endline;
    success = this->loadFromFile(buffer.getData());
    if (success)
    {
	debug::LogManager::instance.assets.info << "Successfully loaded " << this->getType() << " file \"" << buffer.getData() << "\"." << debug::LogStream::endline;
    }

    return success;
}

}
}
