//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language
#ifndef TCP_SIMULATION_THREAD_H
#define TCP_SIMULATION_THREAD_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "tcp_simulation/Thread.h"
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
_tcp_simulation_BEGIN

// line 189 "../model.ump"
class Thread {
		
};
_tcp_simulation_END

//------------------------
// GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
#include <ext/hash_map>
namespace __gnu_cxx{
template<> struct hash<tcp::simulation::Thread*>{
    size_t operator()(tcp::simulation::Thread* ptr ) const {
        return ptr->hashCode();
    }
};
}
#endif

#endif