#include "slim/assets/Asset.hh"
#include "slim/assets/Listener.hh"
#include "slim/assets/Manager.hh"

namespace slim
{
namespace assets
{

Listener::Listener()
{
}

Listener::~Listener()
{
}


void
Listener::onAssetsReady()
{
    // Can be overriden by user.
}

void
Listener::onAssetsUnloaded()
{
    // Can be overriden by user.
}


void
Listener::listen(const Asset* asset)
{
    if (!asset->isLoaded())
    {
	++m_waitedNumber;
	Manager::instance.addListener(this, asset);
    }
}

void
Listener::onOneAssetReady()
{
    --m_waitedNumber;
    if (m_waitedNumber == 0)
    {
	this->onAssetsReady();
    }
}

void
Listener::onOneAssetUnloaded()
{
    if (m_waitedNumber == 0)
    {
	this->onAssetsUnloaded();
    }
    ++m_waitedNumber;
}

}
}
