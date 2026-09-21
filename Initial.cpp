#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Vehicle {
public:
    Vehicle(const std::string& model, double distance)
        : model(model), distance(distance) {}

    const std::string& getModel() const {
        return model;
    }

    double getDistance() const {
        return distance;
    }

private:
    std::string model;
    double distance;
};

class Fleet {
public:
    void addVehicle(const std::string& model, double distance) {
        vehicles.emplace_back(model, distance);
    }

    double totalDistance() const {
        double total = 0.0;

        for (const auto& vehicle : vehicles) {
            total += vehicle.getDistance();
        }

        return total;
    }

    void printReport() const {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "Fleet Report\n";
        std::cout << "============\n";

        for (const auto& vehicle : vehicles) {
            std::cout << vehicle.getModel()
                      << " | "
                      << vehicle.getDistance()
                      << " km"
                      << std::endl;
        }

        std::cout << "============\n";
        std::cout << "Total Distance: " << totalDistance() << " km" << std::endl;
    }

private:
    std::vector<Vehicle> vehicles;
};

int main() {
    Fleet fleet;

    fleet.addVehicle("Truck A", 1245.6);
    fleet.addVehicle("Van B", 863.4);
    fleet.addVehicle("Car C", 452.9);
    fleet.addVehicle("Truck D", 1788.1);

    fleet.printReport();

    return 0;
}
