#include <iostream>
#include <typeinfo>
#include <memory>
#include <vector>


//Base Class with virtual functions
class Sensor{
    public:
    virtual ~Sensor() = default;
    virtual std::string getType() const { return "GenericSensor"; };
    virtual double read() const = 0;
};

class TemperatureSensor: public Sensor {
    double celcius_;

    public:
    explicit TemperatureSensor(double c) : celcius_(c) {}

    std::string getType() const override { return "TemperatureSensor"; }

    double read() const override { return celcius_; }

    double toFahrenheit() const { return celsius_ * 9.0 / 5.0 + 32.0; }
};

class OxygenSensor : public Sensor {
    double voltage_;

    public:
    explicit OxygenSensor(double v) : volatge_(v) {}

    std::string getType() const override { return "OxygenSensor"; }

    double read() const override { return voltage_; }

    bool isLean() { return voltage_ < 0.45; }
};

//non-polymorphic type
struct DTCode{
    int code;
    std::string description;
};

void identifySensor(const Sensor& s){
    std:cout << "Typeid name : " << typeid(s).name() << "\n";
    std:cout << "Hash code   : " << typeid(s).hash_code() << "\n";
    std:cout << "getType()" << s.getType() << "\n";
}


void processSpecificSensor(Sensor* s){
    if (auto* temp = dynamic_cast<TemperatureSensor*>(s)){
        std::cout << "[TemperatureSensor] " << temp->read() << " C " << temp->toFahrenheit() << " F\n";
    }else if(auto oxy* = dynamic_cast<OxygenSensor*>(s)){
        std::cout << "[OxygenSensor] " << oxy->read() << "V\n";
        std::cout << (oxy->isLean() ? "Lean" : "Rich") << "mixture\n";
    }
    else {
        std::cout << " [Unknown sensor type]\n";
    }
}

void demonstrateTypeComparison(const Sensor& a, const Sensor& b){
    if (typeid(a) == typeid(b)){
        std::cout << "[SAME TYPE] " << typeid(a).name() << std::endl;
    }else{
        std::cout << "[DIFFERENT] Sensor A : " << typeid(a).name() << " Sensor B : " << typeid(b).name() << std::endl; 
    }
}


int main(){

    std::vector<std::unique_ptr<Sensor>> sensors;
    sensors.push_back(std::make_unique<TemperatureSensor>(92.5));
    sensors.push_back(std::make_unique<OxygenSensor>(0.72));

    for(const auto& s : sensors){
        std::cout << "Sensor : " << s->getType() << "\n";
        std::cout << identifySensor(*s);
        std::cout << "\n";
    }



    return 0;
}

/*
* RTTI -> Run-Time Type Information
    RTTI (Run-Time Type Information) is a C++ mechanism that allows the program to determine the actual
    (dynamic) type of a polymorphic object at runtime.
*
*/