#ifndef SLIM_MEMORY_CHUNK_HPP_
# define SLIM_MEMORY_CHUNK_HPP_

# include <cstddef>

namespace slim
{
namespace memory
{

class			Chunk
{
public:
    Chunk(char* data, std::size_t size);
    virtual ~Chunk();

public:
    void		clear();
    template <class T, typename ...Args>
    T*			create(Args&&... args);
    template <class T>
    void	        destroy(T* object);

public:
    virtual void*	alloc(std::size_t size) = 0;
    virtual void	free(char* ptr) = 0;

public:
    // For some chunk implementations, this may not work on release mode !
    inline std::size_t	getSize() const;

protected:
    char*		m_start;
    char*		m_data;
    std::size_t		m_size;
    std::size_t		m_maxSize;
};

}
}

# include "Chunk.ipp"

#endif // !SLIM_MEMORY_CHUNK_HPP_
