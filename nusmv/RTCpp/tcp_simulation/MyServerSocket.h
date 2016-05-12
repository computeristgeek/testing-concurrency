//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language
#ifndef TCP_SIMULATION_MYSERVERSOCKET_H
#define TCP_SIMULATION_MYSERVERSOCKET_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "tcp_simulation/MyServerSocket.h"
#endif
#endif_tcp_simulation_BEGIN

// line 250 "../model.ump"
class MyServerSocket {
		
};
_tcp_simulation_END

//------------------------
// GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
#include <ext/hash_map>
namespace __gnu_cxx{
template<> struct hash<tcp::simulation::MyServerSocket*>{
    size_t operator()(tcp::simulation::MyServerSocket* ptr ) const {
        return ptr->hashCode();
    }
};
}
#endif

#endif