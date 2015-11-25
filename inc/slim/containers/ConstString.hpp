#ifndef SLIM_CONTAINERS_CONST_STRING_HPP_
# define SLIM_CONTAINERS_CONST_STRING_HPP_

namespace slim
{
namespace containers
{

class	ConstString
{
public:
    ConstString(const char* data);
    ConstString(const ConstString& reference);
    ~ConstString();

public:
    inline const char*	getData() const;

public:
    inline char		operator[](unsigned int index) const;

public:
    inline bool	operator==(const char* string) const;
    inline bool	operator!=(const char* string) const;
    inline bool	operator==(const ConstString& string) const;
    inline bool	operator!=(const ConstString& string) const;
    inline bool	operator<(const ConstString& string) const;

private:
    const char*	m_data;
};

}
}

# include "ConstString.ipp"

#endif // !SLIM_CONTAINERS_CONST_STRING_HPP_
