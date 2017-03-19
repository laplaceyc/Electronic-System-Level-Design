// timer.cpp
#include "timer.h"

void timer::runtimer() {
    while(true) {
        if (start) {
            cout << "Timer: timer start detected " << endl;
            count = 5;
            timeout = false;
        } else {
            if (count > 0) {
                count--;
                timeout = false;
            } else {
                timeout = true;
            }
        }
        wait();
    }
}
