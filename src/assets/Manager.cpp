#include "slim/assets/Asset.hh"
#include "slim/assets/Manager.hh"
#include "slim/debug/assert.hh"
#include "slim/debug/LogManager.hh"
#include "slim/io/macros.h"

namespace slim
{
namespace assets
{

Manager
Manager::instance;


Manager::Manager()
{
}

Manager::~Manager()
{
}


void
Manager::onInit()
{
}

void
Manager::onDestroy()
{
}

void
Manager::setExecutablePath(const char* path)
{
    SLIM_DEBUG_ASSERT(m_path.isEmpty()); // This function is supposed to be called only once.
    m_path << path << SLIM_IO_SEPARATOR_CHAR << SLIM_ASSETS_FOLDER << SLIM_IO_SEPARATOR_CHAR << '\0';
}



void
Manager::addToLoadList(Asset* asset)
{
    m_assets[asset->getType()].push_back(asset);
}

void
Manager::loadNeededAssets()
{
    unsigned int	pathRootSize = m_path.getSize();

    for (std::pair<const char*, std::vector<Asset*>> assets : m_assets)
    {
	debug::LogManager::instance.assets.info << "Starting loading of " << assets.first << " assets." << debug::LogStream::endline;
	m_path << assets.first << SLIM_IO_SEPARATOR_CHAR;
	for (Asset* asset : assets.second)
	{
	    if (asset->isNeeded() && !asset->isLoaded()) 
	    {
		asset->load(m_path.getData());
	    }
	}
	m_path.resetToSize(pathRootSize);
	debug::LogManager::instance.assets.info << "Finished loading of " << assets.first << " assets." << debug::LogStream::endline;
    }
}

}
}
