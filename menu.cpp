#include "menu.h"

menu::menu() {
    container = new PlaneContainer;
}

void menu::show() {
    int run = true;
    int pos = 0;

    std::string command;
    std::size_t next_char;
    int command_num;

    std::string dest;
    int id;
    std::string type;

    std::string path;

    AEROFLOT   obj;
    AEROFLOT * obj_ptr;

    bool showed;

    while(run) {

        std::cout << '\n' << std::endl;

        for(int i = 0; i < names_count; ++i) {
            std::cout << i << "   " << names[i] << '\n';
        }

        command_num = -1;
        while (command_num < 0) {

            std::cout << "Command -> ";
            std::cin  >> command;

            try {
                command_num = std::stoi(command,&next_char);
            }  catch (std::invalid_argument) {
                std::cout << "Not correct argument\n";
            }
        }

        switch (command_num) {
            case 0: {

                command_num = -1;
                while (command_num < 0) {
                    std::cout << " Destination ( _ for all ) -> ";
                    std::cin >> command;

                    command_num = 1;
                    if (command[0] == '_') command_num = 0;
                }

                showed = true;

                if (command_num) {
                    for (int i = 0; i < container->get_size(); ++i) {
                        obj_ptr = container->get(i);
                        if (obj_ptr->get_destination() == command) {
                            std::cout   << '\n'
                                        << "Destination " << obj_ptr->get_destination() << "\n"
                                        << "ID          " << obj_ptr->get_id() << "\n"
                                        << "Type        " << obj_ptr->get_type() << "\n";
                            showed = false;
                        }
                    }
                } else {
                    for (int i = 0; i < container->get_size(); ++i) {
                        obj_ptr = container->get(i);
                        std::cout   << '\n'
                                    << "Destination " << obj_ptr->get_destination() << "\n"
                                    << "ID          " << obj_ptr->get_id() << "\n"
                                    << "Type        " << obj_ptr->get_type() << "\n";
                        showed = false;
                    }
                }

                if (showed) std::cout << "No such planes" << std::endl;



                break;
            }

            case 1: {

                while (true) {
                    std::cout << " Set sort ( i/d/t ) -> ";
                    std::cin >> command;

                    if (command[0] == 'i' || command[0] == 'd' || command[0] == 't') break;

                    std::cout << " No such sort\n";
                }

                switch (command[0]) {
                    case 'i': {
                        std::cout << " Sorting by ID" << std::endl;
                        break;
                    }
                    case 'd': {
                        std::cout << " Sorting by DESTINATION" << std::endl;
                        break;
                    }
                    case 't': {
                        std::cout << " Sorting by TYPE" << std::endl;
                        break;
                    }
                }

                container->set_sort(command[0]);

                break;
            }


            case 2: {

                command = "";

                std::cout << " Destination -> ";
                std::cin >> command;

                while (command.empty()) {
                    std::cout << " Destination -> ";
                    std::cin >> command;
                    std::cout << "\n";
                }

                dest = command;

                command_num = -1;
                while (command_num <= 0) {
                    std::cout << " ID          -> ";
                    std::cin >> command;
                    try {
                        command_num = std::stoi(command);
                    }  catch (std::invalid_argument) {
                        std::cout << "Not correct argument\n";
                    }
                }

                id = command_num;

                command = "";

                while (command.empty()) {
                    std::cout << " Type        -> ";
                    std::cin >> command;
                    std::cout << "\n";
                }

                type = command;

                container->add(AEROFLOT(dest,id,type));
                break;
            }

            case 3: {

                if (container->get_size() == 0) {
                    std::cout << "List is empty\n";
                    continue;
                }

                command_num = -1;
                while (command_num < 0) {
                    std::cout << "ID -> ";
                    std::cin >> command;
                    try {
                        command_num = std::stoi(command);
                    }  catch (std::invalid_argument) {
                        std::cout << "Not correct argument";
                    }
                    if (command_num < 0 || command_num > container->get_size()-1) command_num = -1;
                }

                obj_ptr = container->get(command_num);

                command = "";

                std::cout << " Destination -> ";
                std::cin >> command;

                while (command.empty()) {
                    std::cout << " Destination -> ";
                    std::cin >> command;
                    std::cout << "\n";
                }

                dest = command;

                command_num = -1;
                while (command_num <= 0) {
                    std::cout << " ID          -> ";
                    std::cin >> command;
                    try {
                        command_num = std::stoi(command);
                    }  catch (std::invalid_argument) {
                        std::cout << "Not correct argument\n";
                    }
                }

                id = command_num;

                command = "";

                while (command.empty()) {
                    std::cout << " Type        -> ";
                    std::cin >> command;
                    std::cout << "\n";
                }

                type = command;


                obj_ptr->set_id(id);
                obj_ptr->set_destination(dest);
                obj_ptr->set_type(type);

                break;
            }

            case 4: {

                if (container->get_size() == 0) {
                    std::cout << "List is empty\n";
                    continue;
                }

                command_num = -1;
                while (command_num < 0) {
                    std::cout << "ID -> ";
                    std::cin >> command;
                    try {
                        command_num = std::stoi(command);
                    }  catch (std::invalid_argument) {
                        std::cout << "Not correct argument";
                    }
                    if (command_num < 0 || command_num > container->get_size()-1) command_num = -1;
                }

                obj = container->pop(command_num);

                std::cout   << '\n'
                            << "Destination " << obj.get_destination() << "\n"
                            << "ID          " << obj.get_id() << "\n"
                            << "Type        " << obj.get_type() << "\n";

                break;
            }

            case 5: {

                command = "";

                std::cout << " Path -> ";
                std::cin >> command;

                std::ifstream file(command);

                while (!file.is_open()) {
                    std::cout << " Path -> ";
                    std::cin >> command;
                    file.open(command);
                }

                std::cout << "\n";

                task(file);

                std::cout << "\n";

                file.close();

                break;
            }

            case 6: {
                run = false;
                break;
            }
        }

    }
}
