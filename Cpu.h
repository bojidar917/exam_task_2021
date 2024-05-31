#include <string>
#include <iostream>
#include "Component.h"

class Cpu : public Component
{
public:
    Cpu(const std::string& label, const unsigned short cores, const unsigned short clockSpeed);
    ~Cpu() = default;

    double price() const override {return this->cores * CORE_PRICE;}
    void output(std::ostream& out) const override;

private:
    const double CORE_PRICE = 29.99;
    const unsigned short cores;
    const unsigned short clockSpeed;

    bool validateCores(unsigned short coresToCheck) const;
};