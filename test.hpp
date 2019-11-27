#include <iostream>
#ifndef _test_
#define _test_
class test{
    protected :
        virtual void before(){

        }
        virtual void after(){

        }
    public :
        virtual void run_test() =0;
};
#endif