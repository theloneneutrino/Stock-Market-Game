#include <locale>
using std::locale;

struct Currency : std::moneypunct<char, true>
{
    char_type do_decimal_point() const { return '.'; }
    char_type do_thousands_sep() const { return ','; }
    string_type do_grouping() const { return "\3"; }
};