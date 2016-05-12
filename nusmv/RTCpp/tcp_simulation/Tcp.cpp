//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language

#define TCP_SIMULATION_TCP_BODY

#if defined( PRAGMA ) && ! defined( PRAGMA_IMPLEMENTED )
#pragma implementation <tcp_simulation/Tcp.h>
#endif

//------------------------
// FILE INCLUDES
//------------------------
#include <model_Model.h>
#include <tcp_simulation/Tcp.h>
#include <tcp_simulation/BufferedReader.h>
#include <tcp_simulation/Queue_Tcp.h>
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
#include <LinkedList>
#include <Queue>
#include <Thread>
#include <InterruptedException>
#include <IOException>

_tcp_simulation_BEGIN

//------------------------------
// ATTRIBUTES IMPLEMENTATIONS
//------------------------------
const string Tcp::SYN = "";
const string Tcp::ACK = "";
const string Tcp::FIN = "";
const string Tcp::RST = "";
const string Tcp::SYNACK = "";
;
_tcp_simulation_END