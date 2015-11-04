namespace slim
{
namespace time
{

unsigned int
Loop::getFramerate() const
{
    return m_framerate;
}

Clock::time
Loop::getRemainingTime() const
{
    return (m_timeToWait - m_accumulated);
}

}
}
