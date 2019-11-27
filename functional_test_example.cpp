#include <math.h>
#include <iostream>
#include <exception>
#include <list>
#include <algorithm>
#include "./test_functional_suite.hpp"
#include "./assertion_exception.hpp"

struct Complex{
    float x,y;
};

Complex c;

float getR(Complex *c){
    return sqrt(c->x*c->x+c->y*c->y);
}

float getTheta(Complex *c){

    return atan(c->y/c->x);

}

void before(){
    ::c.x = 4;
    ::c.y = 4;
}

void after(){
    ::c.x = 0;
    ::c.y = 0;
}

void checkR(){

    float r = getR(&c);
    if(abs(r-5.0)>0.0001){
        throw assertion_exception("Assertion fail in check R.",(float)5.0,r);
    }


}


void checkTheta(){

    double t = getTheta(&c);
    if(abs(t-atan(4.0/3.0))>0.0001){
        throw assertion_exception("Assertion fail in check Theta.",atan(4.0/3.0),t);
    }


}

int main(){
    test_functional_suite ts;
    ts.set_before_function(before);
    ts.set_after_function(after);
    ts.add_test(checkR);
    ts.add_test(checkTheta);
    std::cout<<"run_tests---\n";
    try{
        ts.run_tests();
    }catch(assertion_exception& e){
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<"run_all_tests---\n";
    try{
        ts.run_all_tests();
    }catch(std::list<assertion_exception>& e){
        std::for_each(e.begin(),e.end(),[](auto e){std::cout<<e.what()<<std::endl;});
    }

    return 0;
}