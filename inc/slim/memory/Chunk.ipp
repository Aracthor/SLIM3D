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


void
Chunk::free(void* ptr)
{
    this->free(reinterpret_cast<char*>(ptr));
}


std::size_t
Chunk::getSize() const
{
    return m_size;
}

}
}
