// Blank header file
#include <string>
#include <utility>
#include <ostream>

class bike
{
private:
    std::string brand;
    std::string size;
public:
    bike() = default;

    bike(std::string brand, std::string size) : brand(std::move(brand)), size(std::move(size)){}

    virtual ~bike() = default;

    [[nodiscard]] const std::string &getBrand() const;

    [[nodiscard]] const std::string &getSize() const;

    void setBrand(const std::string &Brand);

    void setSize(const std::string &size);

    friend std::ostream &operator<<(std::ostream &os, const bike &bike);

};