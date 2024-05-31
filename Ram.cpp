#include <stdexcept>

#include "Ram.h"

Ram::Ram(const std::string &label, const unsigned short capacity)
    : Component(label), capacity(capacity)
{
    if(!validateCapacity(this->capacity))
        throw std::invalid_argument("invalid capacity of the ram memory");

}

void Ram::output(std::ostream &out) const
{
    Component::output(out);
    out << "capacity: " << capacity << std::endl;
}

bool Ram::validateCapacity(const unsigned short capacity) const
{
    if(capacity > 1 && capacity < 10000)
        return true;
    return false;
}
