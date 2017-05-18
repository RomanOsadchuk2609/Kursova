#ifndef CELL_H
#define CELL_H

class CELL {
private:
    int Status;
    int TimeOfImmunity;
    int TimeOfInfection;
public:
    CELL();

    virtual ~CELL();

    int getStatus() const;

    void setStatus(int Status);

    void setTimeOfInfection(int TimeOfInfection);

    void infectNeighbor(int , CELL**&);
    void SSS(int , CELL**&);

    int getTimeOfInfection() const;
    void setTimeOfImmunity(int TimeOfImmunity);
    int getTimeOfImmunity() const;

};

#endif // CELL_H

