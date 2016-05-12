//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language
#ifndef TCP_SIMULATION_TCP_H
#define TCP_SIMULATION_TCP_H

#ifdef PRAGMA
#pragma once
#ifndef _MSC_VER
#pragma interface "tcp_simulation/Tcp.h"
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
using namespace java::util;
using namespace java::lang;
using namespace java::io;

//------------------------
// USED LIBRARIES
//------------------------
#include <string>
#include <ostream>
#include <cassert>
#include <LinkedList>
#include <Queue>
#include <Thread>
#include <InterruptedException>
#include <IOException>
_tcp_simulation_BEGIN
class Queue_Tcp;

// line 6 "../model.ump"
class Tcp {
		
	public:
	
		//------------------------
		// STATIC VARIABLES
		//------------------------
		static const string SYN;
		static const string ACK;
		static const string FIN;
		static const string RST;
		static const string SYNACK;
		
		// line 85 ../model.ump
		  public synchronized void sendSyn () 
		  {
		    try{
		      q.putMessage(SYN);
		    }catch (InterruptedException e) {}
		  }
		
		// line 91 ../model.ump
		  public synchronized void sendSynAck () 
		  {
		    try{
		       q.putMessage(SYNACK);
		     }catch (InterruptedException e) {}
		  }
		
		// line 97 ../model.ump
		  public synchronized void sendAck () 
		  {
		    try{
		      q.putMessage(ACK);
		    }catch (InterruptedException e) {}
		  }
		
		// line 104 ../model.ump
		  public synchronized void sendData () 
		  {
		    in=new BufferedReader(new InputStreamReader(System.in));
		     String sn;
		     try{
		       sn=in.readLine();
		       try{
		         q.putMessage(sn);
		       }catch (InterruptedException e) {}
		     } catch (IOException ioe){}
		  }
		
		// line 115 ../model.ump
		  public synchronized void sendFin () 
		  {
		    try{
		        q.putMessage(FIN);
		      }catch (InterruptedException e) {}
		  }
	private:
	
		// Attributes
		Queue_Tcp* q;
		BufferedReader in;
		string sentence;
};
_tcp_simulation_END

//------------------------
// GNU HASH FUNCTION USE
//------------------------
#ifdef __GNUC__
#include <ext/hash_map>
namespace __gnu_cxx{
template<> struct hash<tcp::simulation::Tcp*>{
    size_t operator()(tcp::simulation::Tcp* ptr ) const {
        return ptr->hashCode();
    }
};
}
#endif

#endif