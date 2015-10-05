#define XK_LATIN1
#include <X11/keysymdef.h>

namespace slim
{
namespace events
{

namespace keyboard
{

enum	EKeyCode
{
    space		= XK_space,
    exclam		= XK_exclam,
    quotation		= XK_quotedbl,
    numberSign		= XK_numbersign,
    dollar		= XK_dollar,
    percent		= XK_percent,
    ampersand		= XK_ampersand,
    apostrophe		= XK_apostrophe,
    quoteright		= XK_quoteright,
    leftParenthesis	= XK_parenleft,
    rightParenthesis	= XK_parenright,
    asterisk		= XK_asterisk,
    plus		= XK_plus,
    comma		= XK_comma,
    minus		= XK_minus,
    period		= XK_period,
    slash		= XK_slash,

    number0		= XK_0,
    number1		= XK_1,
    number2		= XK_2,
    number3		= XK_3,
    number4		= XK_4,
    number5		= XK_5,
    number6		= XK_6,
    number7		= XK_7,
    number8		= XK_8,
    number9		= XK_9,

    colon		= XK_colon,
    semicolon		= XK_semicolon,
    less		= XK_less,
    equal		= XK_equal,
    greater		= XK_greater,
    question		= XK_question,
    at			= XK_at,

    A			= XK_A,
    B			= XK_B,
    C			= XK_C,
    D			= XK_D,
    E			= XK_E,
    F			= XK_F,
    G			= XK_G,
    H			= XK_H,
    I			= XK_I,
    J			= XK_J,
    K			= XK_K,
    L			= XK_L,
    M			= XK_M,
    N			= XK_N,
    O			= XK_O,
    P			= XK_P,
    Q			= XK_Q,
    R			= XK_R,
    S			= XK_S,
    T			= XK_T,
    U			= XK_U,
    V			= XK_V,
    W			= XK_W,
    X			= XK_X,
    Y			= XK_Y,
    Z			= XK_Z,

    leftBracket		= XK_bracketleft,
    backslash		= XK_backslash,
    rightBracket        = XK_bracketright,
    asciicircum		= XK_asciicircum,
    underscore		= XK_underscore,
    grave		= XK_grave,
    leftQuote		= XK_quoteleft,

    a			= XK_a,
    b			= XK_b,
    c			= XK_c,
    d			= XK_d,
    e			= XK_e,
    f			= XK_f,
    g			= XK_g,
    h			= XK_h,
    i			= XK_i,
    j			= XK_j,
    k			= XK_k,
    l			= XK_l,
    m			= XK_m,
    n			= XK_n,
    o			= XK_o,
    p			= XK_p,
    q			= XK_q,
    r			= XK_r,
    s			= XK_s,
    t			= XK_t,
    u			= XK_u,
    v			= XK_v,
    w			= XK_w,
    x			= XK_x,
    y			= XK_y,
    z			= XK_z,

    leftBrace		= XK_braceleft,
    pipe		= XK_bar,
    rightBrace		= XK_braceright,
    tilde		= XK_asciitilde,

    keysMax
};

enum	EAction
{
    pressed,
    released
};

}

}
}
