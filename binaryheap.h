#ifndef BINARY_HEAP_H_
#define BINARY_HEAP_H_
#include <iostream>
using namespace std;

class binheap
{
    public:
        typedef int val_t;
        const static unsigned CAP = 100;
        binheap( ) {count = 0;}
        bool isEmpty( ) {return count==0;}
        bool isFull( ) {return count==CAP;}

        void insert(val_t val) {
            if(isFull()) return;
            //Not full, so we add and reheap UP
            data[count] = val; count++;
            if(count>1) reheapUp(count-1);
        }
        void remove( ) {
            if(isEmpty()) return;
            //Not empty, so we remove and reheap DOWN
            data[0] = data[count]; count--;
            if(count!=1) reheapDown();
        }

        void print( ) {
            for(unsigned i=0; i<count; i++) cout<<data[i]<<" ";
            cout << endl;
        }
    private:
        unsigned count;
        val_t data[CAP];

        void reheapUp(unsigned index) {
            while(index > 0) {
                if(data[index] > data[index/2]) {
                    val_t temp = data[index];
                    data[index] = data[(index-1)/2];
                    data[(index-1)/2] = temp;
                }
                index = (index-1)/2;
            }
        }
        void reheapDown() {
            unsigned cursor = 0;
            while(true) {
                if( (2*cursor+1)>=count )break;
                else if( (2*cursor+2)==count ) {
                    if(data[cursor]<data[(2*cursor)+1]) {
                        val_t temp = data[cursor];
                        data[cursor] = data[(2*cursor)+1];
                        data[(2*cursor)+1] = temp;
                    }
                    cursor = (2*cursor)+1;
                }
                else {
                    if(data[(2*cursor)+1] > data[(2*cursor)+2]) {
                        val_t temp = data[cursor];
                        data[cursor] = data[(2*cursor)+1];
                        data[(2*cursor)+1] = temp;
                        cursor = (2*cursor)+1;
                    }
                    else {
                        val_t temp = data[cursor];
                        data[cursor] = data[(2*cursor)+2];
                        data[(2*cursor)+2] = temp;
                        cursor = (2*cursor)+2;
                    }
                }
            }
        }
};

#endif

