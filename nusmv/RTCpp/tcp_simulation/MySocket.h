//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language
#ifndef TCP_SIMULATION_MYSOCKET_H
#define TCP_SIMULATION_MYSOCKET_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "tcp_simulation/MySocket.h"
#endif
#endif_tcp_simulation_BEGIN

// line 211 "../model.ump"
class MySocket {
		
};
_tcp_simulation_END

//------------------------
// GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
#include <ext/hash_map>
namespace __gnu_cxx{
template<> struct hash<tcp::simulation::MySocket*>{
    size_t operator()(tcp::simulation::MySocket* ptr ) const {
        return ptr->hashCode();
    }
};
}
#endif

#endif