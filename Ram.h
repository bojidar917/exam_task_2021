#include <string>
#include <iostream>

#include "Component.h"

class Ram : public Component 
{
public:
    Ram(const std::string& label, const unsigned short capacity);
    ~Ram() = default;

    double price() const override { return this->capacity * RAM_PRICE;}
    void output(std::ostream& out) const override;

private:
    const double RAM_PRICE = 89.99;
    const unsigned short capacity;

    bool validateCapacity(const unsigned short capacity) const;
};