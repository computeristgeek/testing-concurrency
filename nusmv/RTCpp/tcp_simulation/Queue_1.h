//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language
#ifndef TCP_SIMULATION_QUEUE_1_H
#define TCP_SIMULATION_QUEUE_1_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "tcp_simulation/Queue_1.h"
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
using namespace std;
using namespace java::util::concurrent;
using namespace java::lang;

//------------------------
// USED LIBRARIES
//------------------------
#include <ostream>
#include <Semaphore>
#include <InterruptedException>
_tcp_simulation_BEGIN

/*
 * Queue_1 class that have acquire and release methods used to send signals between the threads
 */
// line 125 "../model.ump"
class Queue_1 {
		
	private:
	
		// Attributes
		Semaphore semC;
		Semaphore semS;
};
_tcp_simulation_END

//------------------------
// GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
#include <ext/hash_map>
namespace __gnu_cxx{
template<> struct hash<tcp::simulation::Queue_1*>{
    size_t operator()(tcp::simulation::Queue_1* ptr ) const {
        return ptr->hashCode();
    }
};
}
#endif

#endif