#ifndef AP_PROJECT_ENTITY_H
#define AP_PROJECT_ENTITY_H

#include <map>

using namespace std;

//Base class of hierarchy
class Entity {
private:
    pair<int,int> position;

    string type;
protected:
    void setType(string type);
public:
    Entity(const pair<int,int> &position);

    int getX();

    int getY();

    string getType();
};


#endif //AP_PROJECT_ENTITY_H
