#ifndef SLIM_CONTAINERS_BUFFER_HPP_
# define SLIM_CONTAINERS_BUFFER_HPP_

# include "slim/containers/String.hpp"

namespace slim
{
namespace containers
{

template <typename T, unsigned int N>
class	Buffer
{
public:
    Buffer();
    ~Buffer();

public:
    inline void	clear();
    void	resetToSize(unsigned int size);

public:
    inline bool		isEmpty() const;
    inline unsigned int	getSize() const;
    inline const T*	getData() const;

public:
    inline T	operator[](unsigned int index) const;
    inline T&	operator[](unsigned int index);

public:
    inline Buffer<T, N>&	operator<<(T c);
    Buffer<T, N>&		operator<<(const T* str);
    inline Buffer<T, N>&	operator<<(T* str);
    inline Buffer<T, N>&	operator<<(const String& str);
    template <unsigned int M>
    inline Buffer<T, N>&	operator<<(const Buffer<T, M> buffer);

    // Used for pointers type
    template <typename U>
    inline Buffer<T, N>&	operator<<(U* ptr);

    // Used for numbers type (int, long etc)
    template <typename U>
    Buffer<T, N>&		operator<<(U n);

private:
    T			m_data[N];
    unsigned int	m_size;
};

}
}

# include "Buffer.ipp"

#endif // !SLIM_CONTAINERS_BUFFER_HPP_
