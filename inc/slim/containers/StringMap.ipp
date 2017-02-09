namespace slim
{
namespace containers
{

template <typename T>
StringMap<T>::StringMap(memory::Chunk& chunk) :
    Map<const char*, T>::Map(chunk)
{
}

template <typename T>
StringMap<T>::~StringMap()
{
}


template <typename T>
bool
StringMap<T>::compare(const char* str1, const char* str2) const
{
    return !strcmp(str1, str2);
}

}
}
