//
// Created by kstepanov on 17/05/2021.
//

#ifndef WORDS_MYVECTOR_H
#define WORDS_MYVECTOR_H

template <class T>
class MyVector {
public:
    typedef T* iterator; // creates an alias of the T* type called iterator
    MyVector(){
    };


    iterator begin() {
        return items;
    }

    iterator end() {
        return &items[used];
    }

    int size() {
        return used;
    }

    /*void sort(){
        for (MyVector<T>::iterator i = begin(); i!=end(); i++) {
            for (MyVector<T>::iterator j = begin(); j!=end(); j++) {
                if(i>j){
                    T temp;
                    i = temp;
                    i = j;
                    j = temp;
                }
            }
        }
    }*/

    T& operator[](int i) {
        return items[i];
    }

    iterator insert (iterator position, const T& item) {
        for (MyVector<T>::iterator i = end(); i > position; i--) {
            *i = *(i - 1);
        }
        *position = item;
        ++used;
        return position;
    }

private:
    T items[100000];
    int used = 0;
};

#endif //WORDS_MYVECTOR_H
