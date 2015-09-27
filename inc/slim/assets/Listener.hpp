namespace slim
{
namespace assets
{

unsigned int
Listener::getWaitedNumber() const
{
    return m_waitedNumber;
}

bool
Listener::isReady() const
{
    return (m_waitedNumber == 0);
}

}
}
