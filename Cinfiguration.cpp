#include "Configuration.h"

void Configuration::clear()
{
    for (int i = 0; i < components.size(); i++)
    {
        delete components[i];
    }
    
}

void Configuration::hasCpu()
{
    this->cpu = true;
}

void Configuration::hasRam()
{
    this->ram = true;
}

Configuration::~Configuration()
{
    clear();
}

double Configuration::price() const
{
    double total = 0;
    for (int i = 0; i < this->components.size(); i++)
    {
        total += this->components[i]->price();
    }
    
    return total;
}

const Component *Configuration::operator[](std::size_t index) const
{
    if(index < this->components.size()-1 && index > 0)
        std::invalid_argument("index out of range");

    return this->components[index];
}

void Configuration::insert(const Component *c)
{
    this->components.push_back(c);
}
