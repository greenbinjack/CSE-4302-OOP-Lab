#include <iostream>
using namespace std;

enum FuelType {petrol, octane};

class Vehicle {
private:
    int license_plate;
    string manufacturer;
    int carriage_size_limit;
public:
    Vehicle () {}
    Vehicle (int license_plate, string manufacturer, int carriage_size_limit)
     : license_plate (license_plate), manufacturer (manufacturer), carriage_size_limit (carriage_size_limit) {}
    int get_license_plate () {
        return license_plate;
    }
    string get_manufacturer () {
        return manufacturer;
    }
    int get_carriage_size_limit () {
        return carriage_size_limit;
    }
    void check ();
};

class GasolineVehicle : public Vehicle {
private:
    int fuel_tank_capacity;
    FuelType fuel_type;
public:
    GasolineVehicle () {}
    GasolineVehicle (int license_plate, string manufacturer, int carriage_size_limit, int fuel_tank_capacity, FuelType fuel_type)
     : Vehicle (license_plate, manufacturer, carriage_size_limit), fuel_tank_capacity (fuel_tank_capacity), fuel_type (fuel_type) {}

    int get_fuel_tank_capacity () {
        return fuel_tank_capacity;
    }
    FuelType get_fuel_type () {
        return fuel_type;
    }
};

class ElectricVehicle : public Vehicle {
private:
    int battery_capacity;
    int charging_time;
public:
    ElectricVehicle () {}
    ElectricVehicle (int license_plate, string manufacturer, int carriage_size_limit, int battery_capacity, int charging_time)
     : Vehicle (license_plate, manufacturer, carriage_size_limit), battery_capacity (battery_capacity), charging_time (charging_time) {}

    int get_battery_capacity () {
        return battery_capacity;
    }
    int get_charging_time () {
        return charging_time;
    }
};

class Motorcycle : public GasolineVehicle {
public:
    Motorcycle () {}
    Motorcycle (int license_plate, string manufacturer, int carriage_size_limit, int fuel_tank_capacity, FuelType fuel_type)
     : GasolineVehicle (license_plate, manufacturer, carriage_size_limit, fuel_tank_capacity, fuel_type) {}
};

class Car : public GasolineVehicle {
private:
    int num_of_passengers;
public:
    Car () {}
    Car (int license_plate, string manufacturer, int carriage_size_limit, int fuel_tank_capacity, FuelType fuel_type, int num_of_passengers)
     : GasolineVehicle (license_plate, manufacturer, carriage_size_limit, fuel_tank_capacity, fuel_type), num_of_passengers (num_of_passengers) {}
public:
    int get_num_of_passengers () {
        return num_of_passengers;
    }
    void check () {
        cout << "Car - maintenance" << endl;
    }
};

class Truck : public GasolineVehicle {
private:
    int cargo_capacity;
public:
    Truck () {}
    Truck (int license_plate, string manufacturer, int carriage_size_limit, int fuel_tank_capacity, FuelType fuel_type, int cargo_capacity)
     : GasolineVehicle (license_plate, manufacturer, carriage_size_limit, fuel_tank_capacity, fuel_type), cargo_capacity (cargo_capacity) {}
    int get_cargo_capacity () {
        return cargo_capacity;
    }
    void check () {
        cout << "Truck - maintenance" << endl;
    }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
private:
    float energy_regeneration_efficiency;
public:
    float get_energy_regeneration_efficiency () {
        return energy_regeneration_efficiency;
    }
};

class Employee {
private:
    int ID;
    string name;
public:
    Employee () {}
    Employee (int ID, string name) : ID (ID), name (name) {}
    int get_ID () {
        return ID;
    }
    string get_name () {
        return name;
    }
};

class Manager : public Employee {
public:
    Manager () {}
    Manager (int ID, string name) : Employee (ID, name) {}
    void display () {
        cout << "Mr. " << get_name () << endl;
    }
};

class Driver : public Employee {
public:
    Driver () {}
    Driver (int ID, string name) : Employee (ID, name) {}
    void display () {
        cout << get_name () << endl;
    }
};

class Branch {
private:
    Motorcycle motorcycles[10];
    Car cars[10];
    Truck trucks[10];
    ElectricVehicle electric_vehicles[10];
    HybridVehicle hybrid_vehicles[10];
    Manager managers[10];
    Driver drivers[30];
};

int main () {
    Car myCar;
    Truck myTruck;

    myCar.check ();
    myTruck.check ();
    return 0;
}
