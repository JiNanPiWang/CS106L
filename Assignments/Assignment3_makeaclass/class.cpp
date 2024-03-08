// Blank cpp file
#include "class.h"

const std::string &bike::getBrand() const
{
    return brand;
}

const std::string &bike::getSize() const
{
    return size;
}

void bike::setBrand(const std::string &Brand)
{
    bike::brand = Brand;
}

void bike::setSize(const std::string &Size)
{
    bike::size = Size;
}

std::ostream &operator<<(std::ostream &os, const bike &bike)
{
    os << "brand: " << bike.brand << " size: " << bike.size;
    return os;
}
