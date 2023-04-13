//
// Created by henry on 12/04/23.
//

#ifndef PAGEDPOWERS_POWER_H
#define PAGEDPOWERS_POWER_H

#include <string>

class Power {
public:
    Power(std::string n, std::string d, float e);

    std::string getName() const;
    std::string getDescription() const;
    float getEffect() const;

    void setName(std::string n);
    void setDescription(std::string d);
    void setEffect(float e);

private:
    std::string name;
    std::string description;
    float effect;
};


#endif //PAGEDPOWERS_POWER_H
