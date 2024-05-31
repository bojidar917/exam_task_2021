#include "Component.h"

Component::Component(const std::string &label) : label(label)
{
}

void Component::output(std::ostream &out) const
{
    out << label << " " << this->price() << std::endl;
}

void Component::saveToFile(std::ostream &out, const std::string &fileName) const
{
    if(!out)
    {
        throw std::runtime_error("invalid output file");
    }
    else
    {
        out << label << " " << this->price() << std::endl;
    }
}
