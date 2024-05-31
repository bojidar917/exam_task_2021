#pragma once

#include <string>
#include <iostream>
class Component
{
public:
    Component(const std::string& label);
    virtual ~Component() = default;

    virtual double price() const = 0;
    virtual void output(std::ostream& out) const;

    virtual void saveToFile(std::ostream& out, const std::string& fileName) const;

private:
    const std::string label;
};