#ifndef SLIM_CONTAINERS_PRESIZED_ARRAY_HH_
# define SLIM_CONTAINERS_PRESIZED_ARRAY_HH_

# include "slim/containers/IArray.hh"

namespace slim
{
namespace containers
{

template <typename T, unsigned int N>
class	PresizedArray : public IArray<T>
{
public:
    PresizedArray();
    explicit PresizedArray(T defaultData);
    ~PresizedArray();

public:
    void		fill(T elem);
    void		insert(T elem) override;
    inline unsigned int	getSize() const override;

public:
    void		forEach(void (*function)(const T& elem)) const;
    void		forEach(void (*function)(T& elem));
    template <typename U>
    void		forEach(void (*function)(const T& elem, const U& param), const U& param) const;
    template <typename U>
    void		forEach(void (*function)(T& elem, const U& param), const U& param);
    template <typename U>
    U			minimum(U (*function)(const T& elem)) const;
    template <typename U>
    U			maximum(U (*function)(const T& elem)) const;

public:
    const T&	operator[](unsigned int index) const override;
    T&		operator[](unsigned int index) override;

private:
    unsigned int	m_currentSize;
    T			m_data[N];
};

}
}

# include "PresizedArray.hpp"

#endif // !SLIM_CONTAINERS_PRESIZED_ARRAY_HH_
