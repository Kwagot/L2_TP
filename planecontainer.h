#ifndef PLANECONTAINER_H
#define PLANECONTAINER_H

#include <aeroflot.h>

class PlaneContainer {
    public:
        PlaneContainer();
        ~PlaneContainer();
        PlaneContainer(const PlaneContainer & obj);

        void       add(AEROFLOT obj);
        AEROFLOT * get(unsigned int id);
        AEROFLOT   pop(unsigned int id);

        void       set_sort(char sort_type);

        unsigned int get_size();

    private:

        char sort_type = 'i';

        // sort types
        // i -> id
        // d -> destination
        // t -> type

        void move(unsigned int pos);
        void move_back(unsigned int pos);

        void resort();

        unsigned int size;
        AEROFLOT ** container;
};

#endif // PLANECONTAINER_H
