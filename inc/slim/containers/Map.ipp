// TODO better than that
namespace slim
{
namespace containers
{

template <typename T, typename U>
Map<T, U>::Map(memory::Chunk& chunk) :
    m_keys(chunk),
    m_values(chunk)
{
}

template <typename T, typename U>
Map<T, U>::~Map()
{
}


template <typename T, typename U>
void
Map<T, U>::insert(T key, U value)
{
    SLIM_DEBUG_ASSERT(this->containsKey(key) == false);
    m_keys.insert(key);
    m_values.insert(value);
}


template <typename T, typename U>
std::size_t
Map<T, U>::getSize() const
{
    return m_keys.getSize();
}

template <typename T, typename U>
const U&
Map<T, U>::at(T key) const
{
    return m_values[this->getKeyIndex(key)];
}

template <typename T, typename U>
bool
Map<T, U>::containsKey(T key) const
{
    bool	found = false;
    std::size_t	i = 0;

    while (!found && i < this->getSize())
    {
	found = (key == m_keys[i]);
	i++;
    }

    return found;
}


template <typename T, typename U>
const U&
Map<T, U>::operator[](T key) const
{
    return this->at(key);
}


template <typename T, typename U>
bool
Map<T, U>::compare(T key1, T key2) const
{
    return (key1 == key2);
}


template <typename T, typename U>
std::size_t
Map<T, U>::getKeyIndex(T key) const
{
    std::size_t	index = 0;

    while (this->compare(key, m_keys[index]) == false)
    {
	index++;
	SLIM_DEBUG_ASSERT(index < m_keys.getSize());;
    }

    return index;
}

}
}
