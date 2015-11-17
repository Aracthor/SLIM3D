#ifndef SLIM_CONTAINERS_STRING_HPP_
# define SLIM_CONTAINERS_STRING_HPP_

namespace slim
{
namespace containers
{

class	String
{
public:
    inline String(const char* data);
    inline String(const String& reference);
    inline ~String();

public:
    inline const char*	getData() const;

public:
    inline char	operator[](unsigned int index) const;

public:
    inline bool	operator==(const char* string) const;
    inline bool	operator!=(const char* string) const;
    inline bool	operator==(const String& string) const;
    inline bool	operator!=(const String& string) const;
    inline bool	operator<(const String& string) const;

private:
    const char*	m_data;
};

}
}

# include "String.ipp"

#endif // !SLIM_CONTAINERS_STRING_HPP_
