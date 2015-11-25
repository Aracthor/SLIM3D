namespace slim
{
namespace memory
{

template <class T, typename ...Args>
T*
Chunk::create(Args&&... args)
{
    T*	pointer = static_cast<T*>(this->alloc(sizeof(T)));

    new (pointer) T(args...);
    return pointer;
}

template <class T>
void
Chunk::destroy(T* object)
{
    object->~T();
    this->free(reinterpret_cast<char*>(object));
}


template <typename T>
T*
Chunk::realloc(T* ptr, std::size_t size)
{
    return reinterpret_cast<T*>(this->realloc(reinterpret_cast<void*>(ptr), size));
}

template <typename T>
T*
Chunk::alloc(std::size_t size)
{
    return reinterpret_cast<T*>(this->alloc(size));
}

void
Chunk::free(void* ptr)
{
    this->free(reinterpret_cast<char*>(ptr));
}


Chunk::Checkpoint
Chunk::saveCheckpoint() const
{
    return m_data;
}


std::size_t
Chunk::getSize() const
{
    return m_size;
}

}
}
