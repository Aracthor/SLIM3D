#ifndef SLIM_CONTAINERS_ARRAY_HPP_
# define SLIM_CONTAINERS_ARRAY_HPP_

# include "slim/containers/IArray.hpp"
# include "slim/memory/Chunk.hpp"

namespace slim
{
namespace containers
{

template <typename T>
class	Array : public IArray<T>
{
public:
    Array(memory::Chunk& chunk);
    Array(memory::Chunk& chunk, std::size_t size);
    Array(memory::Chunk& chunk, const Array<T>& array);
    ~Array();

public:
    void		insert(T elem) override;
    void		resize(std::size_t size);
    inline std::size_t	getSize() const override;
    inline std::size_t	getMaxSize() const;

public:
    inline const T&	getLast() const;
    inline T&		getLast();

public:
    inline const T&	operator[](std::size_t index) const override;
    T&			operator[](std::size_t index) override;

private:
    memory::Chunk&	m_chunk;
    T*			m_data;
    std::size_t		m_size;
    std::size_t		m_maxSize;
};

}
}

# include "Array.ipp"

#endif // !SLIM_CONTAINERS_ARRAY_HPP_
