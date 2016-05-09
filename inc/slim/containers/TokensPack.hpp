#ifndef SLIM_CONTAINERS_TOKENS_PACK_HPP_
# define SLIM_CONTAINERS_TOKENS_PACK_HPP_

namespace slim
{
namespace containers
{

class	TokensPack
{
public:
    TokensPack(char* str, char separator = '\n');
    ~TokensPack();

public:
    char*		getNextToken();

private:
    char*		m_data;
    char*		m_lastSeparatorFound;
    char	        m_separator;
};

}
}

#endif // !SLIM_CONTAINERS_TOKENS_PACK_HPP_
