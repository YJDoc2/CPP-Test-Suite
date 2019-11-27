#include <list>
#include "./assertion_exception.hpp"
#include "./test.hpp"



#ifndef _testsuite_
#define _testsuite_

class test_class_suite{

    private:
        std::list<test*> tests;
        std::list<assertion_exception> exceptions;

    public:
        void add_test(test *t);
        void run_tests();
        void run_all_tests();


};

#endif