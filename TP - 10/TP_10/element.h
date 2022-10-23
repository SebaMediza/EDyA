//
// Created by daniel on 21/5/20.
//

#include <ostream>
#include <iostream>

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

template<class T>
class Item {
private:
    T data;
    int order;
public:
    static int comp;
    static int assignment;

    Item(T data, int order) {
        this->data = data;
        this->order = order;
    };

    Item() {
        this->order = 0;
    };

    Item(T data) {
        this->data = data;
        this->order = 0;
    };

    T getData() const {
        return data;
    }

    void setData(T data) {
        Item::data = data;
    }

    int getOrder() const {
        return order;
    }

    void setOrder(int order) {
        Item::order = order;
    }

    bool operator==(const Item &rhs) const {
        comp++;
        return data == rhs.data &&
               order == rhs.order;
    }

    bool operator!=(const Item &rhs) const {
        comp++;
        return !(rhs == *this);
    }

    bool operator<(const Item &rhs) const {
        comp++;
        return data < rhs.data;
    }

    bool operator>(const Item &rhs) const {
        comp++;
        return rhs < *this;
    }

    bool operator<=(const Item &rhs) const {
        comp++;
        return !(rhs < *this);
    }

    bool operator>=(const Item &rhs) const {
        comp++;
        return !(*this < rhs);
    }

    Item &operator=(Item other) {
        assignment++;
        std::swap(this->data, other.data);
        std::swap(this->order, other.order);
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Item &item) {
        os << "(" << item.data << ", " << item.order << ")";
        return os;
    }


    static void reset() {
        comp = 0;
        assignment = 0;
    }
};

template<class T>
int Item<T>::comp = 0;
template<class T>
int Item<T>::assignment = 0;

#endif
