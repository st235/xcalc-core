#ifndef XCALC_CORE_FORMATTER_H
#define XCALC_CORE_FORMATTER_H

#include <sstream>

namespace xcalc_internal {

class Formatter {
  public:
    enum ToString { end };

    Formatter() = default;
    ~Formatter() = default;

    Formatter(const Formatter &) = delete;
    Formatter& operator= (Formatter&) = delete;

    template <typename Type>
    Formatter& operator<< (const Type& value)
    {
        _stream << value;
        return *this;
    }

    std::string operator>>(ToString) { return _stream.str(); }

    std::string str() const {
        return _stream.str();
    }

    explicit operator std::string() const {
        return _stream.str();
    }

  private:
    std::stringstream _stream;
};

}

#endif //XCALC_CORE_FORMATTER_H
