#ifndef SLIM_RESOURCES_BMP_FORMAT_LOADER_HH_
# define SLIM_RESOURCES_BMP_FORMAT_LOADER_HH_

# include "slim/core/attributes.h"
# include "slim/resources/data.hh"
# include "slim/resources/IFormatLoader.hh"

namespace slim
{
namespace resources
{

class	BMPFormatLoader : public IFormatLoader
{
private:
    struct SLIM_CORE_PACKED	Header
    {
	uint16	magic;
	uint32	size;
	uint16	_app1;
	uint16	_app2;
	uint32	offset;
    };

    struct SLIM_CORE_PACKED	InfoHeader
    {
	uint32	size;
	int32	width;
	int32	height;
	uint16	planes;
	uint16	bpp;
	uint32	compression;
	uint32	raw_data_size;
	int32	h_resolution;
	int32	v_resolution;
	uint32	palette_size;
	uint32	important_colors;
    };

public:
    BMPFormatLoader();
    ~BMPFormatLoader();

public:
    void	load(VirtualFile* file, ImageData& data) override;
};

}
}

# include "BMPFormatLoader.hpp"

#endif // !SLIM_RESOURCES_BMP_FORMAT_LOADER_HH_
