//PLEASE DO NOT EDIT THIS CODE
//This code was generated using the UMPLE 1.24.0-78d6971 modeling language

#ifndef TCP_SIMULATION_MODEL_MODEL
#define TCP_SIMULATION_MODEL_MODEL

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WIN64)
#define WINDOWS_OS
// NO PREPROCESSOR DEFINITION FOR PRAGMA
#if _MSC_VER
#define PRAGMA
#pragma warning( disable : 4290 )
#endif
#elif defined(hpux) || defined(__hpux) || defined(__hpux__)
#define HPUX_OS
#elif defined(__APPLE__) || defined(macintosh)
#define MAC_OS
#elif defined(bsdi) || defined(__bsdi__)
#define BSD_OS
#endif

#ifdef PRAGMA
#pragma once
#ifdef _MSC_VER

#pragma include_alias("..\model\model_Model.h", "model_Model.h")
#pragma include_alias(".\tcp_simulation\Tcp.h", "tcp_simulation/Tcp.h")
#pragma include_alias(".\tcp_simulation\Queue_Tcp.h", "tcp_simulation/Queue_Tcp.h")
#pragma include_alias(".\tcp_simulation\BufferedReader.h", "tcp_simulation/BufferedReader.h")
#pragma include_alias(".\tcp_simulation\Queue_1.h", "tcp_simulation/Queue_1.h")
#pragma include_alias(".\tcp_simulation\Semaphore.h", "tcp_simulation/Semaphore.h")
#pragma include_alias(".\tcp_simulation\LinkedList<String>.h", "tcp_simulation/LinkedList<String>.h")
#pragma include_alias(".\tcp_simulation\Thread.h", "tcp_simulation/Thread.h")
#pragma include_alias(".\tcp_simulation\Receiver.h", "tcp_simulation/Receiver.h")

#else
#pragma interface "model_Model.h"
#endif
#endif

//------------------------
// PACKAGE FILES DECLARATION
//------------------------
#ifdef WINDOWS_OS
#include <windows.h>
#include <process.h>
#else
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#endif

#ifdef HPUX_OS
#include <sys/pstat.h>
#elif defined MAC_OS
#undef DEBUG
#include <CoreServices/CoreServices.h>
#elif defined BSD_OS
#include <mach/mach_types.h>
#include <sys/systm.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#endif

//------------------------
// LIBRARIES INCLUDES
//------------------------
using namespace std;

//------------------------
// USED LIBRARIES
//------------------------
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#define _tcp_simulation_BEGIN 	namespace tcp { namespace simulation { 
#define _tcp_simulation_END 	} } 
#define _Tcp_ENUM_BEGIN 	namespace _Tcp_ENUM{
#define _Tcp_ENUM_END 	}
#define Connection 	::tcp::simulation::_Tcp_ENUM::_Connection

//------------------------------
// NAMESPACES AND PREDEFINITIONS
//------------------------------
#ifdef __cplusplus
_tcp_simulation_BEGIN
_tcp_simulation_END
_Tcp_ENUM_BEGIN
_Tcp_ENUM_END
#endif 

//#define Close_Wait 0
//#define Closed 1
//#define Closing 2
//#define Established 3
//#define FIN_Wait_1 4
//#define FIN_Wait_2 5
//#define Last_ACK 6
//#define Listen 7
//#define SYN_Received 8
//#define SYN_Sent 9
//#define Timed_Wait 10

/// is_pointer
template <typename T> struct remove_const_type { typedef T type; };
template <typename T> struct remove_const_type<const T> { typedef T type; };
template <typename T> struct remove_volatile_type { typedef T type; };
template <typename T> struct remove_volatile_type<volatile T> { typedef T type; };
template <typename T> struct removeType : remove_const_type<typename remove_volatile_type<T>::type> {};
template <typename T> struct is_ptr_type { enum { value = false }; };
template <typename T> struct is_ptr_type<T*> { enum { value = true }; };
template <typename T> struct is_ptr : is_ptr_type<typename removeType<T>::type> {};

#define PLACE_HOLDER			int
#define USECS_PER_MSEC			1000
#define MUSECS_PER_SEC			1000
#define USECS_PER_SEC			1000000

#ifdef WINDOWS_OS

#define EVENT_TYPE						HANDLE
#define CONDITION_TYPE					PLACE_HOLDER
#define THREAD_TYPE			 			HANDLE
#define THREAD_RETURN_TYPE				unsigned WINAPI
#define THREAD_ERROR_INSTANCE(returnValue)	((returnValue) == NULL)
#define THREAD_ERROR_CODE(value)			GetLastError()

#define MUTEX_CRITICAL_SECTION			CRITICAL_SECTION
#define START_MUTEX_FUNCTION(arg) \
	InitializeCriticalSection((arg))

#define TERMINATE_MUTEX_FUNCTION(arg) \
	DeleteCriticalSection((arg))

#define LOCK_MUTEX_FUNCTION(arg) \
	EnterCriticalSection((arg))

#define UNLOCK_MUTEX_FUNCTION(arg) \
	LeaveCriticalSection((arg))

#define START_EVENT_TYPE_FUNCTION(mutex, cond) \
	mutex = CreateEvent(0, FALSE, FALSE, 0)

#define TERMINATE_EVENT_FUNCTION(mutex, cond) \
	CloseHandle(mutex)

#define WAIT_EVENT_FUNCTION(mutex, cond, wakeup)		\
	switch(WaitForSingleObject(mutex, INFINITE)) {		\
	case WAIT_OBJECT_0:									\
		return;											\
	default:											\
		throw ThreadException("wait event failed");		\
	}

#define WAIT_TIME_EVENT_FUNCTION(mutex, cond, ms, wakeup, reset, status)			\
	switch (WaitForSingleObject(mutex, ms + 1))										\
	{																				\
	case WAIT_TIMEOUT:																\
		status = false;																\
	case WAIT_OBJECT_0:																\
		status = true;																\
	default:																		\
		throw ThreadException("wait event failed");									\
	}

#define WAKEUP_EVENT_FUNCTION(mutex, cond, wakeup) \
	SetEvent(mutex)

#define THREAD_JOIN_FUNCTION(hdl)				WaitForSingleObject(hdl, INFINITE)
#define THREAD_SLEEP_FUNCTION(ms)				Sleep((ms))

#define THREAD_CREATE_FUNCTION(id, funPtr, callPtr)	id =(HANDLE)CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)funPtr,callPtr,0L,NULL)

#define THREAD_TERMINATE_FUNCTION(hdl)	TerminateThread(hdl, 0)

#define THREAD_CANCEL_FUNCTION(hdl)	TerminateThread(hdl, 0)

#define IS_THREAD_ALIVE_FUNCTION(hdl, isRunning)	\
	DWORD exitCode = 0;								\
	if(GetExitCodeThread(hdl, &exitCode)) 			\
		isRunning = (exitCode == STILL_ACTIVE)

#define BROADCAST_FUNCTION(arg) 0

#define SET_EVENT_FUNCTION(arg) \
	SetEvent((arg))

#define RESET_EVENT_FUNCTION(arg) \
	ResetEvent((arg))

#define LOCK_MUTEX_EVENT_FUNCTION(arg) 0
#define UNLOCK_MUTEX_EVENT_FUNCTION(arg) 0
	
#else

#define EVENT_TYPE							pthread_mutex_t
#define CONDITION_TYPE						pthread_cond_t cond

#define THREAD_TYPE							pthread_t
#define THREAD_RETURN_TYPE					void *

#define THREAD_ERROR_INSTANCE(returnValue)	((returnValue) == NULL)
#define THREAD_ERROR_CODE(value)			GetLastError()

#define THREAD_ERROR_INSTANCE(returnValue)		((returnValue) != 0)
#define THREAD_ERROR_CODE(value)				(value)

#define MUTEX_CRITICAL_SECTION					pthread_mutex_t;
#define START_MUTEX_FUNCTION(arg)	\
	arg = PTHREAD_MUTEX_INITIALIZER

#define TERMINATE_MUTEX_FUNCTION(arg) \
	pthread_mutex_destroy((arg))

#define LOCK_MUTEX_FUNCTION(arg)	\
	pthread_mutex_lock((arg))

#define UNLOCK_MUTEX_FUNCTION(arg) \
	pthread_mutex_unlock((arg))

#define START_EVENT_TYPE_FUNCTION(mutex, cond) \
	 pthread_mutex_init(&mutex, NULL) \
	 pthread_cond_init(&cond, NULL)

#define TERMINATE_EVENT_FUNCTION(mutex, cond) \
	pthread_cond_destroy(&cond) \
	pthread_mutex_destroy(&mutex)

#define WAIT_EVENT_FUNCTION(mutex, cond, wakeup)	\
	pthread_mutex_lock(&mutex)						\
	int err = 0										\
	while (!wakeup) {					            \
		err = pthread_cond_wait(&cond, &mutex)		\
		if (err) {									\
			pthread_mutex_unlock(&_mutex);			\
			throw ThreadException(get_error(err))   \
		}											\
	}												\
	wakeup = FALSE									\
	pthread_mutex_unlock(&mutex)

#define WAIT_TIME_EVENT_FUNCTION(mutex, cond, ms, wakeup, reset, status)			\
	struct timeval tv																\
	struct timespec tdif															\
	gettimeofday(&tv, NULL)															\
	tdif.tv_sec  = tv.tv_sec + ms / MUSECS_PER_SEC									\
	tdif.tv_nsec = tv.tv_usec*MUSECS_PER_SEC + (ms % MUSECS_PER_SEC)*USECS_PER_SEC	\
	if (tdif.tv_nsec >= NSECS_PER_SEC) {											\
		tdif.tv_nsec -= NSECS_PER_SEC												\
		tdif.tv_sec++																\
	}																				\
	pthread_mutex_lock(&mutex)														\
	while (!wakeup)																	\
	{																				\
		status = pthread_cond_timedwait(&cond, &mutex, &tdif)						\
		if(status) {																\
			if (status == ETIMEDOUT) break;											\
			pthread_mutex_unlock(&mutex)											\
			throw ThreadException(get_error(status))								\
		}																			\
	}																				\
	wakeup =  status == 0 && reset ? false : wakeup									\
	pthread_mutex_unlock(&mutex)

#define WAKEUP_EVENT_FUNCTION(mutex, cond, wakeup)  \
	pthread_mutex_lock(&mutex)						\
	wakeup = TRUE									\
	pthread_cond_signal(&cond)						\
	pthread_mutex_unlock(&mutex)

#define THREAD_JOIN_FUNCTION(id)	pthread_join(id, NULL)
#define THREAD_SLEEP_FUNCTION(ms) \
	struct timeval tv \
    tv.tv_usec = (ms % MUSECS_PER_SEC) * USECS_PER_MSEC \
    tv.tv_sec = ms / MUSECS_PER_SEC \
    select(0, NULL, NULL, NULL, &tv)

#define THREAD_CREATE_FUNCTION(id, funPtr, callPtr)				\
	pthread_attr_t attr											\
	pthread_attr_init(&attr)									\
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED)	\
	pthread_attr_setinheritsched(&attr, PTHREAD_INHERIT_SCHED)	\
	hdl = pthread_create(&id, &attr, funPtr, callPtr)			\
	pthread_attr_destroy(&attr)

#define THREAD_TERMINATE_FUNCTION(arg)	pthread_exit(arg)
#define THREAD_CANCEL_FUNCTION(Id)					\
	if (pthread_cancel(Id))							\
		throw ThreadException(ErrorMessage(code));
#define IS_THREAD_ALIVE_FUNCTION(hdl, isRunning)	\
	isRunning = (phtread_kill(hdl, 0) == 0)

#define BROADCAST_FUNCTION(arg) \
	pthread_cond_broadcast((arg))

#define SET_EVENT_FUNCTION(arg) 1

#define RESET_EVENT_FUNCTION(arg) 1

#define LOCK_MUTEX_EVENT_FUNCTION(arg)	\
	pthread_mutex_lock((arg))

#define UNLOCK_MUTEX_EVENT_FUNCTION(arg) \
	pthread_mutex_unlock((arg))

#endif

#define CREATE_THREAD(id, funPtr, callPtr)								\
	THREAD_CREATE_FUNCTION(id, funPtr, callPtr);						\
	if(THREAD_ERROR_INSTANCE(id))										\
		throw ThreadException(ErrorMessage(THREAD_ERROR_CODE(id)))

static std::string ErrorMessage(int errorCode){
	string str = "";
	if (errorCode == 0) {
		return str;
	}

	char* what = "Error Numer";
	int whlen = strlen(what);
	int ncode = errorCode, dlen = 1;
	while (ncode !=0) {dlen++; ncode/=10;}
	char *buffer = (char *) malloc(sizeof(char) * (whlen + dlen + 1));
    sprintf(buffer, "%s = %d", what, errorCode);
	str = buffer;
	return str;
}

struct ThreadException : public std::exception{
   std::string s;
   ThreadException(std::string ss) : s(ss) {}
   ~ThreadException() throw() {}
   const char* what() const throw() { return s.c_str(); }
};

template <typename T>
void* ConvertToFunctionPointer(T x) {
  return *reinterpret_cast<void**>(&x);
}

struct Runnable {
	virtual void run() = 0;
};

class AtomicMutex{
  public:
	AtomicMutex() { START_MUTEX_FUNCTION(&section); }
	~AtomicMutex() { TERMINATE_MUTEX_FUNCTION(&section); }
    void lock() { LOCK_MUTEX_FUNCTION(&section); }
    void unlock() { UNLOCK_MUTEX_FUNCTION(&section); }

  private:
	MUTEX_CRITICAL_SECTION section;
};

static AtomicMutex atomicMutex;

class MutexLock{
public:

    MutexLock() : m_value(0){
		wakeup = FALSE;
		START_EVENT_TYPE_FUNCTION(mutex, cond);
		if (!mutex)
			throw ThreadException("Cannot create lock");
	}

	MutexLock(const MutexLock& m) {
		this->m_value = m.m_value;
		this->wakeup = m.wakeup;
		this->mutex = m.mutex;
		this->cond = m.cond;
	}

    ~MutexLock(){
		TERMINATE_EVENT_FUNCTION(mutex, cond);
	}

	void wait() {
		WAIT_EVENT_FUNCTION(mutex, cond, wakeup);
	}

    void wakeUp() {
		WAKEUP_EVENT_FUNCTION(mutex, cond, wakeup);
	}

    void lock() {
		bool canBeAccessed= this->verifyLock();
		if (canBeAccessed){
			return;
		}

		atomicMutex.lock();
		canBeAccessed = m_value==0;
		m_value += 1;
		atomicMutex.unlock();

		if (!canBeAccessed){
			wait();
			atomicMutex.lock();
			m_value -= 1;
			atomicMutex.unlock();
		}

	}

	bool isLocked() {
		atomicMutex.lock();
		bool canBeAccessed = m_value == 0;
		atomicMutex.unlock();
		return !canBeAccessed;
	}

	bool verifyLock(int set = 0) {
		atomicMutex.lock();
		bool canBeAccessed = m_value == 0;
		if( m_value == set) {
			m_value = !set;
			canBeAccessed = true;
		}
		atomicMutex.unlock();
		return canBeAccessed;
	}

    void unlock() {
		if (!verifyLock(1)){
			wakeUp();
		}
	}

private:
	volatile int m_value;
	volatile bool wakeup;

	EVENT_TYPE mutex;
    CONDITION_TYPE  cond;
};

#define synchronized(L)                                               \
        for(L.lock();L.isLocked();									  \
			L.unlock() )

struct ThreadParameters
{
    void* runCall;
    void* context;
    ThreadParameters(void* ctx, void* callPtr) : context(ctx), runCall(callPtr) {}
};

class Thread: public Runnable {

	public:
		Thread(string threadName = "") : runnableObject(NULL), name(threadName), thrParams(this,ConvertToFunctionPointer(&Thread::run))
			, _threadHdl(0),_isRunning(false),_isTerminated(false) {}
		Thread(Runnable *target, string threadName = "") :  name(threadName),thrParams(this,ConvertToFunctionPointer(&Thread::run)) , runnableObject(target) {}
		Thread(void* funcPtr, void* ctx = 0 ,string threadName = "") : runnableObject(NULL), name(threadName), thrParams(ctx,funcPtr) {}
		Thread(void (*funcPtr)(void*), void* ctx = 0, string threadName = "") : runnableObject(NULL),name(threadName), thrParams(ctx,ConvertToFunctionPointer(funcPtr)) {}
		Thread(void (*funcPtr)(), string threadName = "") : runnableObject(NULL),name(threadName), thrParams(this,ConvertToFunctionPointer(funcPtr)) {}
		template<class T>
		Thread(void (T::*RunnableCall)(), string threadName = "") : runnableObject(NULL), name(threadName), thrParams(this,ConvertToFunctionPointer(RunnableCall)) {}
		template<class T>
		Thread(void (T::*RunnableCall)(void*), void* ctx = 0, string threadName = "") : runnableObject(NULL), name(threadName), thrParams(ctx,ConvertToFunctionPointer(RunnableCall)) {}
		virtual ~Thread() {
			THREAD_TERMINATE_FUNCTION(0);
		}

		static void sleep(long ms) throw(ThreadException) {
			THREAD_SLEEP_FUNCTION(ms);
		}

		THREAD_TYPE getId() const {
			return this->_threadHdl;
		}

		static THREAD_RETURN_TYPE threadFunctionPointer(void* ptr) {
			ThreadParameters* threadParameters = (ThreadParameters*)ptr;
			if(threadParameters->context != NULL) {
                ((void (*)(void*)) threadParameters->runCall)(threadParameters->context);
			} else {
			    ((void (*)(void)) threadParameters->runCall)();
			}

			return 0;
		}

		bool isFinished() {
			return !this->isRunning();
		}

		bool isTerminated() {
			synchronized(lock) {
				return this->_isTerminated;
			}
		}

		bool isRunning() {
			synchronized(lock) {
				if(this->_isRunning) {
					IS_THREAD_ALIVE_FUNCTION(_threadHdl,_isRunning);
				}
				return this->_isRunning;
			}
		}

		virtual void run() {
			if(this->runnableObject != NULL) {
				runnableObject->run();
			}
		}

		virtual void stop() {
			synchronized(lock) {
				THREAD_CANCEL_FUNCTION(_threadHdl);
				_isTerminated = true;
				_isRunning = false;
			}
		}

		string getName() const {
			return name;
		}

		void setName(string name) {
			this->name = name;
		}

		virtual void start(Runnable *target) throw(ThreadException) {
			runnableObject = target;
			start();
		}
		
		virtual void start() throw(ThreadException) {
			synchronized(lock) {
				reset();
				CREATE_THREAD(_threadHdl,Thread::threadFunctionPointer, &thrParams);
				_isRunning = true;
			}
		}

		void join() throw(ThreadException) {
			THREAD_JOIN_FUNCTION(_threadHdl);
		}
		
		void wait() throw(ThreadException) {
			lock.wait();
		}

		void wakeUp() throw(ThreadException) {
			lock.wakeUp();
		}

	private:
		mutable MutexLock lock;
		THREAD_TYPE _threadHdl;
		string name;

		ThreadParameters thrParams;
		Runnable* runnableObject;

		bool _isRunning;
		bool _isTerminated;

		void reset() {
			_threadHdl = 0;
			_isRunning = false;
			_isTerminated = false;
		}

};

//------------------------
// PREDEFINED TYPES
//------------------------


//A template function to get the index of an item for a given vector. It returns -1 if the
//item was not found
template < typename InputIterator, typename EqualityComparable >
	int IndexOf(const InputIterator& begin,
	const InputIterator& end, const EqualityComparable& item) {
		if(begin == end )
			return -1;

		InputIterator fnd = std::find(begin, end, item);
		unsigned int index = std::distance(begin, fnd);
		return fnd != end ? index : -1;
};

//Used as a function pointer to safely destroy elements or collections of elements
//Example: 
//	std::for_each( arr->begin(), arr->end(), delete_pointer_element());
//	delete arr;
struct deleteElement{
 template< typename T >
 void operator()( T element ) const{
	delete element;
	}
};

template<typename T>
unsigned int compare(T c1, T c2, unsigned int sz ) {
	if(!is_ptr<T>::value) {
		return memcmp(&c1,&c2, sz);
	}
	return memcmp((void*)c1, (void*)c2, sz);
};

template<typename T>
void copyObject(T* object1, T* object2, unsigned int sz ) {
	if(!is_ptr<T>::value) {
		memcpy(&object2,&object1, sz);
	}
 	memcpy((void*)object2, (void*)object1, sz);
};



#endif