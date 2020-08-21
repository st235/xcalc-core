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
        stream_ << value;
        return *this;
    }

    std::string operator>>(ToString) { return stream_.str(); }

    std::string str() const {
        return stream_.str();
    }

    explicit operator std::string() const {
        return stream_.str();
    }

  private:
    std::stringstream stream_;
};

}

#endif //XCALC_CORE_FORMATTER_H
