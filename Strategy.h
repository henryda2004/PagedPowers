//
// Created by henry on 12/04/23.
//

#ifndef PAGEDPOWERS_STRATEGY_H
#define PAGEDPOWERS_STRATEGY_H

#include <string>
#include "Power.h"

class Strategy {
public:
    Strategy(std::string n, Power p1, Power p2);

    std::string getName() const;
    void setName(std::string n);

    Power getPower1() const;
    void setPower1(Power p);

    Power getPower2() const;
    void setPower2(Power p);

private:
    std::string name;
    Power power1;
    Power power2;
};


#endif //PAGEDPOWERS_STRATEGY_H
