namespace slim
{
namespace time
{

bool
Clock::isRunning() const
{
    return (m_running);
}

Clock::time
Clock::getElapsedTime() const
{
    return (m_elapsedTime);
}


void
Clock::setRunning(bool running)
{
    m_running = running;
}

}
}
