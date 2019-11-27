#include <list>
#include "./assertion_exception.hpp"
#include "./test.hpp"


#ifndef _testsuite_
#define _testsuite_
class test_functional_suite{

    private:
        void (*before)(void);
        void (*after)(void);
        std::list<void (*)(void)> tests;
        std::list<assertion_exception> exceptions;

    public:
        test_functional_suite(){
            before = [](){};
            after = [](){};
        }
        void set_before_function(void (*fn)(void));
        void set_after_function(void (*fn)(void));
        void add_test(void (*fn)(void));
        void run_tests();
        void run_all_tests();


};
#endif