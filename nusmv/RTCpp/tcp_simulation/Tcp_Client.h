//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language
#ifndef TCP_SIMULATION_TCP_CLIENT_H
#define TCP_SIMULATION_TCP_CLIENT_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "tcp_simulation/Tcp_Client.h"
#endif
#endif

//------------------------
// LIBRARIES INCLUDES
//------------------------
using namespace java::io;
using namespace java::lang;
using namespace java::util;

//------------------------
// USED LIBRARIES
//------------------------
#include <IOException>
#include <Thread>
#include <InterruptedException>
#include <LinkedList>
_tcp_simulation_BEGIN

/*
 * create client class to implement MySocket class
 */
// line 282 "../model.ump"
class Tcp_Client : public Thread {
		
};
_tcp_simulation_END

//------------------------
// GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
#include <ext/hash_map>
namespace __gnu_cxx{
template<> struct hash<tcp::simulation::Tcp_Client*>{
    size_t operator()(tcp::simulation::Tcp_Client* ptr ) const {
        return ptr->hashCode();
    }
};
}
#endif

#endif