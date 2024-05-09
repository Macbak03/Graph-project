#include <stdexcept>

class InvalidDataException : public std::runtime_error {
public:
    explicit InvalidDataException(const std::string& msg) : std::runtime_error(msg) {}
};