#include "slim/debug/LogManager.hh"
#include "slim/resources/BMPFormatLoader.hh"
#include "slim/resources/FileException.hh"

namespace slim
{
namespace resources
{

BMPFormatLoader::BMPFormatLoader()
{
}

BMPFormatLoader::~BMPFormatLoader()
{
}


bool
BMPFormatLoader::load(const char* name, VirtualFile* file, BMPFormatLoader::ImageData& data)
{
    Header	header;
    InfoHeader	infoHeader;

    return this->loadHeaders(file, header, infoHeader);
    (void)name;
    (void)data;
}


bool
BMPFormatLoader::loadHeaders(VirtualFile* file, Header& header, InfoHeader& infoHeader)
{
    file->readPureData(header);
    file->readPureData(infoHeader);

    if (header.magic != SLIM_RESOURCES_BMP_MAGIC || infoHeader.compression != 0)
    {
	debug::LogManager::instance.resources.error << "SLIM doesn't support compressed BMP files." << debug::LogStream::endline;
	return false;
    }
    return true;
}

}
}
