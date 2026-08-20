#include <iostream>

class Device{
    public:
    int power;
    Device() : power(100){
        std::cout << "Root created successfully!\n";
    }
};


//marking the base class as virtual prevents the Diamond problem
//failing to do so, will result to an ambiguity error
class Scanner : virtual public Device{
    public:
    Scanner(){
        std::cout << "[SCANNER] Scanner added!\n";
    }
    void scan(){
        std::cout << "scanning ...\n";
    }
};

class Printer : virtual public Device{
    public:
    Printer(){
        std::cout << "[PRINTER] Printer added!\n";
    }
    void print(){
        std::cout << "Printing ...\n";
    }
};


class AllInOnePrinter : public Printer, public Scanner {
    public:
    AllInOnePrinter(){
        std::cout << "All in one synthesizer!\n";
    }

    void showPower(){
        std::cout << "Power consumption " << power << " Watts\nDiamond Problem Solved!\n";
    }
};

class VehicleTelemetry;
void diagnosticDump(const VehicleTelemetry &vt);

class VehicleTelemetry{
public:
    static constexpr int MAX_FLEET_SIZE = 100;
    explicit VehicleTelemetry(std::string vin, double speed = 0.0)
        : vin_(std::move(vin)), lastSpeed_(speed) {
            assert(totalVehiclesTracked_ < MAX_FLEET_SIZE && "Fleet size exceeded");
            ++totalVehiclesTracked_;
    }
    ~VehicleTelemetry() {
        --totalVehiclesTracked_;
    }

    static int getFleetCount() {
        return totalVehiclesTracked_;
    }

    void updateSpeed(double newSpeed) {
        lastSpeed_ = newSpeed;
    }

    friend void diagnosticDump(const VehicleTelemetry& vt);

private:
static int totalVehiclesTracked_;
std::string vin_;
double lastSpeed_;

};

int VehicleTelemetry::totalVehiclesTracked_ = 0;

void diagnosticDump(const VehicleTelemetry& vt) {
    std::cout << "[DIAG] VIN : "  << vt.vin_
              << " Speed : "      << vt.lastSpeed_ 
              << "Fleet Size : "  << VehicleTelemetry::totalVehiclesTracked_ << "\n";
}

int main(){

    AllInOnePrinter machine;
    machine.scan();
    machine.print();
    machine.showPower();

    std::cout << "Fleet count before any vehicle: "
              << VehicleTelemetry::getFleetCount() << "\n";

    VehicleTelemetry v1("WBA3A5C55DF123456", 85.0);

    std::cout << "After v1: fleet count = "
              << VehicleTelemetry::getFleetCount() << "\n";


    VehicleTelemetry v2("WVWZZZ3CZWE987654", 120.5);

    std::cout << "After v2: fleet count = "
              << VehicleTelemetry::getFleetCount() << "\n";
    
    {

        VehicleTelemetry v3("TMBJB9NE1L0123456");

        std::cout << "After v3 (scoped): fleet count = "
                  << VehicleTelemetry::getFleetCount() << "\n";

    }

    // v3 destroyed when scope ends — counter decrements.

    std::cout << "After v3 destroyed: fleet count = "
              << VehicleTelemetry::getFleetCount() << "\n\n";

    // Demo 2: Static method called without an object
    // No object required — call directly on the class.

    std::cout << "--- Static method without object ---\n";

    std::cout << "VehicleTelemetry::getFleetCount() = "
              << VehicleTelemetry::getFleetCount() << "\n\n";

    // Demo 3: Friend function accessing private data

    // diagnosticDump reads private vin_ and lastSpeed_ directly.

    std::cout << "--- Friend function ---\n";

    v1.updateSpeed(92.3);
    diagnosticDump(v1);
    diagnosticDump(v2);

    std::cout << "\n";


    return 0;
}