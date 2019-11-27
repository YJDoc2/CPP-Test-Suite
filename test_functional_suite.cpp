#include <list>
#include <algorithm>
#include "./test_functional_suite.hpp"
#include "./assertion_exception.hpp"
#include "./test.hpp"


void test_functional_suite::add_test(void (*fn)(void)){
    this->tests.push_back(fn);
}

void test_functional_suite::set_before_function(void (*fn)(void)){
    this->before = fn;
}

void test_functional_suite::set_after_function(void (*fn)(void)){
    this->after = fn;
}

void test_functional_suite::run_tests(){

    try{
        std::for_each(this->tests.begin(),this->tests.end(),
        [this](void(*fn)(void)){     
            this->before();
            fn();
            this->after();
        });
    }catch(assertion_exception e){
        throw e;
    }
}

void test_functional_suite::run_all_tests(){
    int i=0;
    std::for_each(this->tests.begin(),this->tests.end(),[&i,this](void(*fn)()){
        this->before();
        try{
            fn();
        }catch(assertion_exception& e){
            i++;
            this->exceptions.push_back(e);
        }
        this->after();
    });
    if(i>0){
        throw exceptions;
    }
}