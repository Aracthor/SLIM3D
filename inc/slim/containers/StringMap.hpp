#ifndef SLIM_CONTAINERS_STRING_MAP_HPP_
# define SLIM_CONTAINERS_STRING_MAP_HPP_

# include "slim/containers/Map.hpp"

namespace slim
{
namespace containers
{

template <typename T>
class	StringMap : public Map<const char*, T>
{
public:
    StringMap(memory::Chunk& chunk);
    ~StringMap();

protected:
    bool	compare(const char* str1, const char* str2) const override;
};

}
}

# include "slim/containers/StringMap.ipp"

#endif // !SLIM_CONTAINERS_STRING_MAP_HPP_
