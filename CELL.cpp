#include "CELL.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

CELL::CELL() {
}

void CELL::setTimeOfInfection(int TimeOfInfection) {
    CELL::TimeOfInfection = TimeOfInfection;
}

int CELL::getTimeOfInfection() const {
    return TimeOfInfection;
}
void CELL::setTimeOfImmunity(int TimeOfImmunity) {
    CELL::TimeOfImmunity = TimeOfImmunity;
}
int CELL::getTimeOfImmunity() const {
    return TimeOfImmunity;
}

CELL::~CELL() {

}

int CELL::getStatus() const {
    return Status;
}
void CELL::setStatus(int Status) {
    CELL::Status = Status;
}

