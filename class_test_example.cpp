#include <math.h>
#include <iostream>
#include <exception>
#include <list>
#include <algorithm>
#include "./test.hpp"
#include "./test_class_suite.hpp"
#include "./assertion_exception.hpp"

class complex{
    private:
       
        complex(){}
    public:
         float x,y;
        complex(float a,float b){
            x= a;
            y= b;
        }
        float getR(){
            return static_cast<float>(sqrt(x*x+y*y));
        }
        float getTheta(){
            return static_cast<float>(atan(y/x));
        }
        complex operator +(const complex& c){
            return complex(c.x+x,c.y+y);
        }
        complex operator =(const complex& c){
            this->x = c.x;
            this->y = c.y;
            return *this;
        }
};

class Test1:public test{
    private:
        complex *c;
    public:
        Test1(){

        }
        void before(){
            c = new complex(4,4);
        }
        void after(){
            delete c;
        }
        void checkTheta(){
            before();
            if(abs(c->getTheta()-atan(4.0/3.0))>0.0001){
                throw assertion_exception("Assertion Fail in check Theta. expected "+std::to_string((4.0/3.0))+" got "+std::to_string(c->getTheta()));
            }
            after();
        }

        void checkR(){
            before();
            if(abs(c->getR()-5)>0.001){
                throw assertion_exception("Assertion Fail in check R. expected "+std::to_string(5)+" got "+std::to_string(c->getR()));
            }
            after();
        }

        void run_test(){
            checkR();
            checkTheta();
        }
};


class Test2:public test{
    private:
        complex c1,c2;
    public:
        Test2():c1(5,4),c2(4,4){

        }
        
        void checkAdd(){
            before();
            complex c3 = c1+c2;
            if(c3.x != 8 || c3.y != 8){
                throw assertion_exception("Assertion Fail in add. expected (8,8) got ("+
                std::to_string(c3.x)+
                ","+
                std::to_string(c3.y)+
                ")"
                );
            }

        }

        void run_test(){
            checkAdd();
        }
};

int main(){
    test_class_suite ts;
    Test1 *t1 = new Test1();
    Test2 *t2 = new Test2();
    ts.add_test(t1);
    ts.add_test(t2);
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