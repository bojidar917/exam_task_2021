#include <stdexcept>

#include "Cpu.h"

Cpu::Cpu(const std::string &label, const unsigned short cores, const unsigned short clockSpeed)
    : Component(label), cores(cores), clockSpeed(clockSpeed)
{
    if(!validateCores(this->cores))
        throw std::invalid_argument("Cores must be between 1 and 8");
}

void Cpu::output(std::ostream &out) const
{
    Component::output(out);
    out << "Cores: " << this->cores << ", clockSpeed: " << this->clockSpeed << std::endl;
}


bool Cpu::validateCores(unsigned short coresToCheck) const
{
    if(coresToCheck > 1 && coresToCheck < 9)
        return true;
    else
        return false;
}
