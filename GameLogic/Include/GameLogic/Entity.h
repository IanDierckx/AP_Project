#ifndef AP_PROJECT_ENTITY_H
#define AP_PROJECT_ENTITY_H

#include <map>

using namespace std;

namespace GameLogic{
    //Base class of hierarchy
    class Entity {
    private:
        pair<int,int> position;

        string type;

        int speed{};
    protected:
        void setType(string type);
    public:
        Entity(const pair<int,int> &position);

        int getX();

        int getY();

        string getType();

        void setX(int x);

        void setY(int y);

        void setSpeed(int speed);

        int getSpeed();
    };
}


#endif //AP_PROJECT_ENTITY_H
