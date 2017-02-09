namespace slim
{
namespace time
{

void
Synchronizer::restart()
{
    m_clock.reset();
}

void
Synchronizer::addLoop(Loop* loop)
{
    m_loops.insert(loop);
}


static Clock::time
getRemainingTime(Loop* const& loop)
{
    return loop->getRemainingTime();
}

Clock::time
Synchronizer::getMinimumRemainingTime() const
{
    return m_loops.minimum(&getRemainingTime);
}

}
}
