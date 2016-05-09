#include "slim/events/linux/KeyCodeConverter.hpp"

#define XK_LATIN1
#define XK_MISCELLANY
#include <X11/keysymdef.h>

#include <cstring>

namespace slim
{
namespace events
{

KeyCodeConverter::KeyCodeConverter(::Display *& display) :
    m_display(display)
{
    m_codes[XK_Escape]		= keyboard::escape,

    m_codes[XK_space]		= keyboard::space;
    m_codes[XK_exclam]		= keyboard::exclam;
    m_codes[XK_quotedbl]	= keyboard::quotation;
    m_codes[XK_numbersign]	= keyboard::numberSign;
    m_codes[XK_dollar]		= keyboard::dollar;
    m_codes[XK_percent]		= keyboard::percent;
    m_codes[XK_ampersand]	= keyboard::ampersand;
    m_codes[XK_apostrophe]	= keyboard::apostrophe;
    m_codes[XK_quoteright]	= keyboard::quoteright;
    m_codes[XK_parenleft]	= keyboard::leftParenthesis;
    m_codes[XK_parenright]	= keyboard::rightParenthesis;
    m_codes[XK_asterisk]	= keyboard::asterisk;
    m_codes[XK_plus]		= keyboard::plus;
    m_codes[XK_comma]		= keyboard::comma;
    m_codes[XK_minus]		= keyboard::minus;
    m_codes[XK_period]		= keyboard::period;
    m_codes[XK_slash]		= keyboard::slash;

    m_codes[XK_0]		= keyboard::number0;
    m_codes[XK_1]		= keyboard::number1;
    m_codes[XK_2]		= keyboard::number2;
    m_codes[XK_3]		= keyboard::number3;
    m_codes[XK_4]		= keyboard::number4;
    m_codes[XK_5]		= keyboard::number5;
    m_codes[XK_6]		= keyboard::number6;
    m_codes[XK_7]		= keyboard::number7;
    m_codes[XK_8]		= keyboard::number8;
    m_codes[XK_9]		= keyboard::number9;

    m_codes[XK_colon]		= keyboard::colon;
    m_codes[XK_semicolon]       = keyboard::semicolon;
    m_codes[XK_less]		= keyboard::less;
    m_codes[XK_equal]		= keyboard::equal;
    m_codes[XK_greater]		= keyboard::greater;
    m_codes[XK_question]	= keyboard::question;
    m_codes[XK_at]		= keyboard::at;

    m_codes[XK_A]       	= keyboard::A;
    m_codes[XK_B]		= keyboard::B;
    m_codes[XK_C]		= keyboard::C;
    m_codes[XK_D]		= keyboard::D;
    m_codes[XK_E]		= keyboard::E;
    m_codes[XK_F]		= keyboard::F;
    m_codes[XK_G]		= keyboard::G;
    m_codes[XK_H]		= keyboard::H;
    m_codes[XK_I]		= keyboard::I;
    m_codes[XK_J]		= keyboard::J;
    m_codes[XK_K]		= keyboard::K;
    m_codes[XK_L]		= keyboard::L;
    m_codes[XK_M]		= keyboard::M;
    m_codes[XK_N]		= keyboard::N;
    m_codes[XK_O]		= keyboard::O;
    m_codes[XK_P]		= keyboard::P;
    m_codes[XK_Q]		= keyboard::Q;
    m_codes[XK_R]		= keyboard::R;
    m_codes[XK_S]		= keyboard::S;
    m_codes[XK_T]		= keyboard::T;
    m_codes[XK_U]		= keyboard::U;
    m_codes[XK_V]		= keyboard::V;
    m_codes[XK_W]		= keyboard::W;
    m_codes[XK_X]		= keyboard::X;
    m_codes[XK_Y]		= keyboard::Y;
    m_codes[XK_Z]		= keyboard::Z;

    m_codes[XK_bracketleft]	= keyboard::leftBracket;
    m_codes[XK_backslash]       = keyboard::backslash;
    m_codes[XK_bracketright]	= keyboard::rightBracket;
    m_codes[XK_asciicircum]	= keyboard::asciicircum;
    m_codes[XK_underscore]	= keyboard::underscore;
    m_codes[XK_grave]		= keyboard::grave;
    m_codes[XK_quoteleft]	= keyboard::leftQuote;

    m_codes[XK_a]		= keyboard::a;
    m_codes[XK_b]		= keyboard::b;
    m_codes[XK_c]		= keyboard::c;
    m_codes[XK_d]		= keyboard::d;
    m_codes[XK_e]		= keyboard::e;
    m_codes[XK_f]		= keyboard::f;
    m_codes[XK_g]		= keyboard::g;
    m_codes[XK_h]		= keyboard::h;
    m_codes[XK_i]		= keyboard::i;
    m_codes[XK_j]		= keyboard::j;
    m_codes[XK_k]		= keyboard::k;
    m_codes[XK_l]		= keyboard::l;
    m_codes[XK_m]		= keyboard::m;
    m_codes[XK_n]		= keyboard::n;
    m_codes[XK_o]		= keyboard::o;
    m_codes[XK_p]		= keyboard::p;
    m_codes[XK_q]		= keyboard::q;
    m_codes[XK_r]		= keyboard::r;
    m_codes[XK_s]		= keyboard::s;
    m_codes[XK_t]		= keyboard::t;
    m_codes[XK_u]		= keyboard::u;
    m_codes[XK_v]		= keyboard::v;
    m_codes[XK_w]		= keyboard::w;
    m_codes[XK_x]		= keyboard::x;
    m_codes[XK_y]		= keyboard::y;
    m_codes[XK_z]		= keyboard::z;

    m_codes[XK_braceleft]	= keyboard::leftBrace;
    m_codes[XK_bar]		= keyboard::pipe;
    m_codes[XK_braceright]	= keyboard::rightBrace;
    m_codes[XK_asciitilde]	= keyboard::tilde;
}

KeyCodeConverter::~KeyCodeConverter()
{
}

}
}
