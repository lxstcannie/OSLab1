//#define BOOST_TEST_MODULE CreatorTest
//#include <boost/test/included/unit_test.hpp>
//#include <cstdlib>
//#include <iostream>
//#include <fstream>
//#include <string>
//
//BOOST_AUTO_TEST_CASE(test_creator) {
//    std::string filename = "test.bin";
//    const int numRecords = 1;
//
//    std::string command = "creator.exe " + std::string(filename) + " " + std::to_string(numRecords);
//    int result = std::system(command.c_str());
//
//    BOOST_CHECK(result == 0);
//
//    std::ifstream file(filename);
//    BOOST_CHECK(file.good());
//
//    file.close();
//    std::remove(filename);
//}