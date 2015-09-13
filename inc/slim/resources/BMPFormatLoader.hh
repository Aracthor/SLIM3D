#ifndef SLIM_RESOURCES_BMP_FORMAT_LOADER_HH_
# define SLIM_RESOURCES_BMP_FORMAT_LOADER_HH_

# include "slim/resources/IFormatLoader.hh"

namespace slim
{
namespace resources
{

class	BMPFormatLoader : public IFormatLoader
{
public:
    BMPFormatLoader();
    ~BMPFormatLoader();

public:
    void	load(const byte* fileData, ImageData& data) override;
};

}
}

# include "BMPFormatLoader.hpp"

#endif // !SLIM_RESOURCES_BMP_FORMAT_LOADER_HH_
