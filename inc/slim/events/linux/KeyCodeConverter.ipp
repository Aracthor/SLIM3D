namespace slim
{
namespace events
{

keyboard::EKeyCode
KeyCodeConverter::convert(unsigned int XCode)
{
    return m_codes[XCode];
}

}
}
