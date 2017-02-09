#ifndef SLIM_CONTAINERS_PRESIZED_ARRAY_HPP_
# define SLIM_CONTAINERS_PRESIZED_ARRAY_HPP_

# include "slim/containers/IArray.hpp"

namespace slim
{
namespace containers
{

template <typename T, std::size_t N>
class	PresizedArray : public IArray<T>
{
public:
    PresizedArray();
    explicit PresizedArray(T defaultData);
    ~PresizedArray();

public:
    void		fill(T elem);
    void		insert(T elem) override;
    inline std::size_t	getSize() const override;

public:
    template <typename ...Args>
    void		forEach(void (*function)(const T& elem, Args ...args), Args& ...args) const;
    template <typename ...Args>
    void		forEach(void (*function)(T& elem, Args ...args), Args& ...args);
    template <typename U>
    U			minimum(U (*function)(const T& elem)) const;
    template <typename U>
    U			maximum(U (*function)(const T& elem)) const;

public:
    const T&	operator[](std::size_t index) const override;
    T&		operator[](std::size_t index) override;

private:
    std::size_t	m_currentSize;
    T		m_data[N];
};

}
}

# include "PresizedArray.ipp"

#endif // !SLIM_CONTAINERS_PRESIZED_ARRAY_HPP_
