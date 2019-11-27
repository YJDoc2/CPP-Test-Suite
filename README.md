# CPP-Test-Suite

## Introduction

Repository of a basic Test Suite made in c++, for easier testing of c++ Programs.  
There are two possible mode for testing - class based and function based.  
Compiling using make will create class_eg and fn_eg, the compiled class_test_example.cpp abd functional_test_example.cpp

## assertion_exception

A basic class extending std::exception class,providing a standerd class to throw.  
Can be instantiated using a message string, or a message char array,
or a message string, expected and obtained vaule (both of same type)

## Class Based Testing using test_class_suite.

First make a class extending 'test' class. implement run_test() function, before() and after() functions are optional to implement.
One can write multiple funtions in the class, each calling before() and after() if required. In case the test fails, the function should Throw an assertion_exception. All functions running the tests should be called in run_test() function.  
A test_class_suite should be created, and a pointer to all test class variables should be added using add_test().

One can run tests in two ways :

<ol>
<li>run_tests() : aborting the run on first assertion_exception caught,which will be thrown by test_class_suite</li>
<li>run_all_test() : running all tests and throwing a std::list of assertion_exception caught,if any.</li>
</ol>

## Function Based Testing using test_functional_suite.

write all functions running tests, and throwing an assertion_exception if test fails. Create a test_functional_suite variable. One can set the before() and after() functions using set_before_function() and set_after_function().  
The before funtion will be called before <strong>all</strong> tests, and the after function will be called after <strong>all</strong> the tests.  
One can add the functions that run the tests using add_test(fn_name).
<b><i>NOTE : </i></b> The tesing funtion should be return void and should not have any parameters.

One can run tests in two ways :

<ol>
<li>run_tests() : aborting the run on first assertion_exception caught,which will be thrown by test_functional_suite</li>
<li>run_all_test() : running all tests and throwing a std::list of assertion_exception caught,if any.</li>
</ol>
