#include "slim/resources/BMPFormatLoader.hh"
#include "slim/resources/FileException.hh"
#include "slim/resources/ResourceException.hh"

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


void
BMPFormatLoader::load(const char* name, VirtualFile* file, BMPFormatLoader::ImageData& data)
{
    Header	header;
    InfoHeader	infoHeader;

    this->loadHeaders(name, file, header, infoHeader);
    (void)file;
    (void)data;
}


void
BMPFormatLoader::onError(const char* name)
{
    throw ResourceException(name, "Corrupted bmp file.", __FILE__, __func__, __LINE__);
}


void
BMPFormatLoader::loadHeaders(const char* name, VirtualFile* file, Header& header, InfoHeader& infoHeader)
{
    file->readPureData(header);
    file->readPureData(infoHeader);

    if (header.magic != SLIM_RESOURCES_BMP_MAGIC)
    {
	this->onError(name);
    }
    if (infoHeader.compression != 0)
    {
	throw ResourceException(name, "SLIM doesn't handle compressed BMP files.", __FILE__, __func__, __LINE__);
    }
}

}
}
