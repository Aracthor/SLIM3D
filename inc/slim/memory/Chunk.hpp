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
    typedef char*	Checkpoint;


public:
    Chunk(char* data, std::size_t size, const char* name);
    virtual ~Chunk();

public:
    virtual void	clear();
    template <class T, typename ...Args>
    T*			create(Args&&... args);
    template <class T>
    void	        destroy(T* object);

public:
    virtual void*	realloc(void* ptr, std::size_t size); // ptr can be nullptr for a simple alloc.
    template <typename T>
    inline T*		realloc(T* ptr, std::size_t size);
    virtual void*	alloc(std::size_t size) = 0;
    template <typename T>
    inline T*		alloc(std::size_t size);
    virtual void	free(char* ptr) = 0;
    inline void		free(void* ptr);

public:
    // Do NOT work with QueueChunk.
    // TODO create a CheckpointableChunk class, and do NOT make QueueChunk inheriting from it.
    inline Checkpoint	saveCheckpoint() const;
    void		loadCheckpoint(Checkpoint checkpoint);

public:
    // For some chunk implementations, this may not work on release mode !
    inline std::size_t	getSize() const;

protected:
    char*		m_data;
    char*		m_start;
    void*		m_lastAllocated = nullptr;
    std::size_t		m_size;
    std::size_t		m_maxSize;
    const char*		m_name;
};

}
}

# include "Chunk.ipp"

#endif // !SLIM_MEMORY_CHUNK_HPP_
