#ifndef SLIM_CONTAINERS_BUFFER_HH_
# define SLIM_CONTAINERS_BUFFER_HH_

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

public:
    inline unsigned int	getSize() const;
    inline const T*	getData() const;

public:
    inline T	operator[](unsigned int index) const;
    inline T&	operator[](unsigned int index);

public:
    inline void	operator<<(T c);
    void	operator<<(const T* str);

    // Used for numbers type (int, long etc)
    template <typename U>
    void	operator<<(U n);

private:
    T			m_data[N];
    unsigned int	m_size;
};

}
}

# include "Buffer.hpp"

#endif // !SLIM_CONTAINERS_BUFFER_HH_
