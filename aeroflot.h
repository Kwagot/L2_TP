#ifndef AEROFLOT_H
#define AEROFLOT_H

#include <string>

class AEROFLOT {
    public:
        AEROFLOT();
        AEROFLOT(std::string destination, unsigned int id, std::string type);
        ~AEROFLOT();
        AEROFLOT(const AEROFLOT & obj);

        std::string  get_destination();
        void         set_destination(std::string dest);

        unsigned int get_id();
        void         set_id(unsigned int id);

        std::string  get_type();
        void         set_type(std::string type);

    private:
        std::string  destination;
        unsigned int id;
        std::string  type;
};

#endif // AEROFLOT_H
