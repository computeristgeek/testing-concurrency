//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language
#ifndef TCP_SIMULATION_MAINTEST_H
#define TCP_SIMULATION_MAINTEST_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "tcp_simulation/MainTest.h"
#endif
#endif

//------------------------
// LIBRARIES INCLUDES
//------------------------
using namespace java::lang;

//------------------------
// USED LIBRARIES
//------------------------
#include <Thread>
_tcp_simulation_BEGIN

/*
 * mainTest class
 */
// line 448 "../model.ump"
class MainTest {
		
};
_tcp_simulation_END

//------------------------
// GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
#include <ext/hash_map>
namespace __gnu_cxx{
template<> struct hash<tcp::simulation::MainTest*>{
    size_t operator()(tcp::simulation::MainTest* ptr ) const {
        return ptr->hashCode();
    }
};
}
#endif

#endif