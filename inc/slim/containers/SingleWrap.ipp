#include "slim/debug/assert.hpp"

#include "slim/string.h"

namespace slim
{
namespace containers
{

template <class T>
SingleWrap<T>::SingleWrap()
{
}

template <class T>
SingleWrap<T>::~SingleWrap()
{
}


template <class T>
void
SingleWrap<T>::init(const T& data)
{
    SLIM_DEBUG_ASSERT(m_inited == false);
    memcpy(m_data, &data, sizeof(T));
    m_inited = true;
}

template <class T>
void
SingleWrap<T>::destroy()
{
    SLIM_DEBUG_ASSERT(m_inited == true);
    reinterpret_cast<T*>(&m_data)->~T();
    m_inited = false;
}


template <class T>
bool
SingleWrap<T>::isInited() const
{
    return m_inited;
}

template <class T>
const T&
SingleWrap<T>::getData() const
{
    SLIM_DEBUG_ASSERT(m_inited == true);
    return *reinterpret_cast<const T*>(m_data);
}

template <class T>
T&
SingleWrap<T>::getData()
{
    SLIM_DEBUG_ASSERT(m_inited == true);
    return *reinterpret_cast<T*>(m_data);
}

}
}
