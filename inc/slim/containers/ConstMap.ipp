namespace slim
{
namespace containers
{

template <typename T, typename U>
ConstMap<T, U>::ConstMap(const T* keys, const U* values) :
    m_keys(keys),
    m_values(values)
{
}

template <typename T, typename U>
ConstMap<T, U>::~ConstMap()
{
}


template <typename T, typename U>
const U&
ConstMap<T, U>::operator[](const T& key) const
{
    return m_values[this->getIndexOf(key)];
}


template <typename T, typename U>
unsigned int
ConstMap<T, U>::getIndexOf(const T& key) const
{
    unsigned int	index = 0;

    while (m_keys[index] != key)
    {
	index++;
    }

    return index;
}

}
}
