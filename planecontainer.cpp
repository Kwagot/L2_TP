#include "planecontainer.h"

bool letter_is_closer_to_start(std::string left, std::string right) {
    unsigned int len;
    bool if_end;
    if (left.length() < right.length()) {
        len = left.length();
        if_end = true;
    } else {
        len = right.length();
        if_end = false;
    }
    for (unsigned int i = 0; i < len; ++i) {
        if (left[i] < right[i]) {
            return true;
        }
    }
    return if_end;
}

PlaneContainer::PlaneContainer() {
    size = 0;
    container = static_cast<AEROFLOT**>(malloc(1));
}

PlaneContainer::~PlaneContainer() {

    for (unsigned int i = 0; i < size; ++i) delete container[i];

    free(container);
}

void PlaneContainer::move(unsigned int pos) {
    for (unsigned int i = size; i > pos; i--) {
        *container[i] = *container[i-1];
    }
}

void PlaneContainer::move_back(unsigned int pos) {
    for (unsigned int i = pos; i < size - 1; i++) {
        *container[i] = *container[i+1];
    }
}

void PlaneContainer::resort() {
    bool flag = true;
    bool found;
    int max_pos = size;
    AEROFLOT tmp;
    while (flag || max_pos > 0) {
        flag = false;
        for (int i = 0; i < max_pos-1; ++i) {
            found = false;
            switch (sort_type) {
                case 'i': {
                    if (container[i]->get_id() < container[i+1]->get_id()) found = true;
                    break;
                }
                case 'd': {
                    if (!letter_is_closer_to_start(container[i]->get_destination(),container[i+1]->get_destination())) found = true;
                    break;
                }
                case 't': {
                    if (!letter_is_closer_to_start(container[i]->get_type(),container[i+1]->get_type())) found = true;
                    break;
                }
            }

            if (found) {
                flag = true;
                tmp = *container[i];
                *container[i] = *container[i+1];
                *container[i+1] = tmp;
            }

        }
        max_pos--;
    }
}

void PlaneContainer::set_sort(char sort_type) {
    this->sort_type = sort_type;

    resort();
}

void PlaneContainer::add(AEROFLOT obj) {
    container = static_cast<AEROFLOT**>(realloc(container, (size+1) * sizeof(AEROFLOT *)));
    container[size] = new AEROFLOT;

    bool found     = false;

    for (unsigned int i = 0; i < size; ++i) {

        switch (sort_type) {
            case 'i': {
                if (obj.get_id() < container[i]->get_id()) found = true;
                break;
            }
            case 'd': {
                if (letter_is_closer_to_start(obj.get_destination(),container[i]->get_destination())) found = true;
                break;
            }
            case 't': {
                if (letter_is_closer_to_start(obj.get_type(),container[i]->get_type())) found = true;
                break;
            }
        }
        if (found) {
            move(i);
            *container[i] = obj;
            break;
        }
    }
    if (!found) *container[size] = obj;

    size++;
}

AEROFLOT * PlaneContainer::get(unsigned int id) {
    return container[id];
}

AEROFLOT PlaneContainer::pop(unsigned int id) {

    AEROFLOT obj = *container[id];
    if (size > 1) {
        move_back(id);
        size--;
        delete container[size];
        container = static_cast<AEROFLOT**>(realloc(container, size * sizeof(AEROFLOT *)));
        return obj;
    }
    size--;
    delete container[size];
    return obj;
}

unsigned int PlaneContainer::get_size() {
    return size;
}
