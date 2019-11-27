#include <exception>
#include <string>

#ifndef _assertionexception_
#define _assertionexception_
class assertion_exception:public std::exception{
    private:
        std::string error;
        assertion_exception(){}
    public:
        assertion_exception(std::string e){
            this->error = e;
        }
        assertion_exception(char* e){
            this->error = e;
        }

        template <typename T>
        assertion_exception(std::string msg,T expected_val,T actual_val){
            this->error = msg+" Expected "+std::to_string(expected_val)+", but obtained "+std::to_string(actual_val);
        }
        const char* what(){
            return error.c_str();
        }
    

};
#endif