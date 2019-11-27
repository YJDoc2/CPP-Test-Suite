#include <list>
#include <algorithm>
#include "./test_class_suite.hpp"

void test_class_suite::add_test(test *t){
    this->tests.push_back(t);
}

void test_class_suite::run_tests(){
    try{
        std::for_each(this->tests.begin(),this->tests.end(),[](test *t){t->run_test();});
    }catch(assertion_exception& e){
        throw e;
    }
}

void test_class_suite::run_all_tests(){
    int i=0;
    std::for_each(this->tests.begin(),this->tests.end(),[&i,this](test *t){
        try{
            t->run_test();
        }catch(assertion_exception& e){
            i++;
            this->exceptions.push_back(e);
        }
    });
    if(i>0){
        throw exceptions;
    }
}

