std::ostream&
operator<<(std::ostream& stream, slim::debug::console::EColor color)
{
    stream << static_cast<char>(0x1B) << "[3" << static_cast<char>(color + '0') << 'm';

    return stream;
}

std::ostream&
operator<<(std::ostream& stream, slim::debug::console::EEffect effect)
{
    stream << static_cast<char>(0x1B) << "[0" << static_cast<char>(effect + '0') << 'm';

    return stream;
}
