#include "aeroflot.h"

AEROFLOT::AEROFLOT() {
    destination = "None";
    id = 0;
    type = "None";
}

AEROFLOT::~AEROFLOT() {
}

AEROFLOT::AEROFLOT(const AEROFLOT & obj) {
    this->destination = obj.destination;
    this->id = obj.id;
    this->type = obj.type;
}

AEROFLOT::AEROFLOT(std::string destination, unsigned int id, std::string type) {
    this->destination = destination;
    this->id = id;
    this->type = type;
}

void AEROFLOT::set_type(std::string type) {
    this->type = type;
}

void AEROFLOT::set_destination(std::string dest) {
    destination = dest;
}

void AEROFLOT::set_id(unsigned int id) {
    this->id = id;
}

std::string AEROFLOT::get_destination() {
    return destination;
}

std::string AEROFLOT::get_type() {
    return type;
}

unsigned int AEROFLOT::get_id() {
    return id;
}
