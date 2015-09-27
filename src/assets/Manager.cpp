#include <algorithm>

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
    this->unloadAllAssets();
}

void
Manager::setExecutablePath(const char* path)
{
    SLIM_DEBUG_ASSERT(m_path.isEmpty()); // This function is supposed to be called only once.
    m_path << path << SLIM_IO_SEPARATOR_CHAR << SLIM_ASSETS_FOLDER << SLIM_IO_SEPARATOR_CHAR;
}


void
Manager::loadNeededAssets()
{
    unsigned int	pathRootSize = m_path.getSize();

    for (std::pair<const char*, std::vector<Asset*>> assets : m_assets)
    {
	debug::LogManager::instance.assets.info << "Starting loading of " << assets.first << " assets."
						<< debug::LogStream::endline;
	m_path << assets.first << 's' << SLIM_IO_SEPARATOR_CHAR << '\0';
	for (Asset* asset : assets.second)
	{
	    if (asset->isNeeded() && !asset->isLoaded()) 
	    {
		this->load(asset);
	    }
	}
	m_path.resetToSize(pathRootSize);
	debug::LogManager::instance.assets.info << "Finished loading of " << assets.first << " assets."
						<< debug::LogStream::endline;
    }
}

void
Manager::unloadUnneededAssets()
{
    for (std::pair<const char*, std::vector<Asset*>> assets : m_assets)
    {
	debug::LogManager::instance.assets.info << "Starting unloading of " << assets.first << " unneeded assets."
						<< debug::LogStream::endline;
	for (Asset* asset : assets.second)
	{
	    if (!asset->isNeeded() && asset->isLoaded()) 
	    {
		this->unload(asset);
	    }
	}
	debug::LogManager::instance.assets.info << "Finished loading of " << assets.first << " unneeded assets."
						<< debug::LogStream::endline;
    }
}

void
Manager::unloadAllAssets()
{
    for (std::pair<const char*, std::vector<Asset*>> assets : m_assets)
    {
	debug::LogManager::instance.assets.info << "Starting unloading of " << assets.first << " assets."
						<< debug::LogStream::endline;
	for (Asset* asset : assets.second)
	{
	    if (asset->isLoaded()) 
	    {
		this->unload(asset);
	    }
	}
	debug::LogManager::instance.assets.info << "Finished loading of " << assets.first << " assets."
						<< debug::LogStream::endline;
    }
}


void
Manager::addToLoadList(Asset* asset)
{
    std::vector<Asset*>&	list = m_assets[asset->getType()];

    if (std::find(list.begin(), list.end(), asset) == list.end())
    {
	list.push_back(asset);
    }
}


void
Manager::load(Asset* asset)
{
    asset->load(m_path.getData());
    m_listenersManager.onLoad(asset);
}

void
Manager::unload(Asset* asset)
{
    asset->unload();
    m_listenersManager.onUnload(asset);
}

}
}
