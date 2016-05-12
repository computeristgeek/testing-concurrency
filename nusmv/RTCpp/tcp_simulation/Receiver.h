//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language
#ifndef TCP_SIMULATION_RECEIVER_H
#define TCP_SIMULATION_RECEIVER_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "tcp_simulation/Receiver.h"
#endif
#endif

//------------------------
// FILE INCLUDES
//------------------------
#include <model_Model.h>
//------------------------
// LIBRARIES INCLUDES
//------------------------
using namespace tcp::simulation;
using namespace java::lang;

//------------------------
// USED LIBRARIES
//------------------------
#include <Thread>
#include <InterruptedException>
_tcp_simulation_BEGIN

// line 192 "../model.ump"
class Receiver : public Thread {
		
};
_tcp_simulation_END

//------------------------
// GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
#include <ext/hash_map>
namespace __gnu_cxx{
template<> struct hash<tcp::simulation::Receiver*>{
    size_t operator()(tcp::simulation::Receiver* ptr ) const {
        return ptr->hashCode();
    }
};
}
#endif

#endif