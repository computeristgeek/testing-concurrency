//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language
#ifndef TCP_SIMULATION_QUEUE_TCP_H
#define TCP_SIMULATION_QUEUE_TCP_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "tcp_simulation/Queue_Tcp.h"
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
using namespace java::lang;
using namespace java::util;

//------------------------
// USED LIBRARIES
//------------------------
#include <ostream>
#include <Thread>
#include <InterruptedException>

_tcp_simulation_BEGIN

// line 158 "../model.ump"
class Queue_Tcp {
			
		// line 166 ../model.ump
		  public synchronized void putMessage (String var) throws InterruptedException 
		  {
		    messages.add(var);
		   notify();
		   //String msg = (String)messages.getFirst();
		   String msg = messages.element();
		   System.out.println("send message: " +msg);
		  }
		
		// line 175 ../model.ump
		  public synchronized String getMessage () throws InterruptedException 
		  {
		    while ( messages.size() == 0 ) 
		      wait();
		    String message =messages.remove();
		    return (message);
		  }
	private:
	
		// Attributes
		LinkedList<String> messages;
};
_tcp_simulation_END

//------------------------
// GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
#include <ext/hash_map>
namespace __gnu_cxx{
template<> struct hash<tcp::simulation::Queue_Tcp*>{
    size_t operator()(tcp::simulation::Queue_Tcp* ptr ) const {
        return ptr->hashCode();
    }
};
}
#endif

#endif