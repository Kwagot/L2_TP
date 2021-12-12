#ifndef MENU_H
#define MENU_H

#include <planecontainer.h>
#include <task.h>

class menu {
    public:
        menu();

        void show();

    private:
        PlaneContainer * container;

        std::string names[7] = {
            "Display",
            "Change sort",
            "Add",
            "Edit",
            "Remove",
            "Task2",
            "Exit"
        };

        int names_count = 7;
};

#endif // MENU_H
