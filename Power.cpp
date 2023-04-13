//
// Created by henry on 12/04/23.
//

#include "Power.h"

Power::Power(std::string n, std::string d, float e) {
    name = n;
    description = d;
    effect = e;
}

std::string Power::getName() const {
    return name;
}

std::string Power::getDescription() const {
    return description;
}

float Power::getEffect() const {
    return effect;
}

void Power::setName(std::string n) {
    name = n;
}

void Power::setDescription(std::string d) {
    description = d;
}

void Power::setEffect(float e) {
    effect = e;
}
