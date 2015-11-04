namespace slim
{
namespace events
{

mouse::EButton
MouseButtonConverter::convert(unsigned int button)
{
    return m_buttons[button];
}

}
}
