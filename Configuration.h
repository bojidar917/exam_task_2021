#include <vector>

#include "Component.h"
#include "ComponentFactory.h"

class Configuration
{
public:
    ~Configuration();

    std::vector<const Component*> components;

    friend Configuration* createConfiguration();

    double price() const;
    const Component* operator[](std::size_t index) const;
    friend std::ostream& operator<<(std::ostream& os, const Configuration* conf);

private:
    Configuration() {};
    Configuration(const Configuration& other) = delete;
    Configuration& operator=(const Configuration& other) = delete;
    
    void insert(const Component* c);

    bool cpu;
    bool ram;

    void clear();

    void hasCpu();
    void hasRam();
};

inline Configuration *createConfiguration()
{
   try
   {
        // static Configuration* configuration = new Configuration(); //why do we need it to be static - svilen said so
        Configuration* configuration = new Configuration(); 
        
        const Component* component = componentFactory();
        configuration->insert(component);

        const Component* othercomponent = componentFactory();
        configuration->insert(othercomponent);

        // std::cout << configuration;

        return configuration;
   }
   catch(...)
   {
        return nullptr;
   }
    //в мейна трябва да се погрижим да се зачисти паметта
}

inline std::ostream &operator<<(std::ostream &os, const Configuration* conf)
{
    for (int i = 0; i < conf->components.size(); i++)
    {
        conf->components[i]->output(os);
    }

    os << "Total price: "<< conf->price();    
    
    return os;
}
