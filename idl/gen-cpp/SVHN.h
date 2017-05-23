/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef SVHN_H
#define SVHN_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "svhn_types.h"



#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class SVHNIf {
 public:
  virtual ~SVHNIf() {}
  virtual int32_t recognize(const SVHNQuery& query) = 0;
};

class SVHNIfFactory {
 public:
  typedef SVHNIf Handler;

  virtual ~SVHNIfFactory() {}

  virtual SVHNIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(SVHNIf* /* handler */) = 0;
};

class SVHNIfSingletonFactory : virtual public SVHNIfFactory {
 public:
  SVHNIfSingletonFactory(const boost::shared_ptr<SVHNIf>& iface) : iface_(iface) {}
  virtual ~SVHNIfSingletonFactory() {}

  virtual SVHNIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(SVHNIf* /* handler */) {}

 protected:
  boost::shared_ptr<SVHNIf> iface_;
};

class SVHNNull : virtual public SVHNIf {
 public:
  virtual ~SVHNNull() {}
  int32_t recognize(const SVHNQuery& /* query */) {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _SVHN_recognize_args__isset {
  _SVHN_recognize_args__isset() : query(false) {}
  bool query :1;
} _SVHN_recognize_args__isset;

class SVHN_recognize_args {
 public:

  SVHN_recognize_args(const SVHN_recognize_args&);
  SVHN_recognize_args& operator=(const SVHN_recognize_args&);
  SVHN_recognize_args() {
  }

  virtual ~SVHN_recognize_args() throw();
  SVHNQuery query;

  _SVHN_recognize_args__isset __isset;

  void __set_query(const SVHNQuery& val);

  bool operator == (const SVHN_recognize_args & rhs) const
  {
    if (!(query == rhs.query))
      return false;
    return true;
  }
  bool operator != (const SVHN_recognize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SVHN_recognize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class SVHN_recognize_pargs {
 public:


  virtual ~SVHN_recognize_pargs() throw();
  const SVHNQuery* query;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SVHN_recognize_result__isset {
  _SVHN_recognize_result__isset() : success(false) {}
  bool success :1;
} _SVHN_recognize_result__isset;

class SVHN_recognize_result {
 public:

  SVHN_recognize_result(const SVHN_recognize_result&);
  SVHN_recognize_result& operator=(const SVHN_recognize_result&);
  SVHN_recognize_result() : success(0) {
  }

  virtual ~SVHN_recognize_result() throw();
  int32_t success;

  _SVHN_recognize_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const SVHN_recognize_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const SVHN_recognize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SVHN_recognize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _SVHN_recognize_presult__isset {
  _SVHN_recognize_presult__isset() : success(false) {}
  bool success :1;
} _SVHN_recognize_presult__isset;

class SVHN_recognize_presult {
 public:


  virtual ~SVHN_recognize_presult() throw();
  int32_t* success;

  _SVHN_recognize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class SVHNClient : virtual public SVHNIf {
 public:
  SVHNClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SVHNClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t recognize(const SVHNQuery& query);
  void send_recognize(const SVHNQuery& query);
  int32_t recv_recognize();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class SVHNProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<SVHNIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (SVHNProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_recognize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  SVHNProcessor(boost::shared_ptr<SVHNIf> iface) :
    iface_(iface) {
    processMap_["recognize"] = &SVHNProcessor::process_recognize;
  }

  virtual ~SVHNProcessor() {}
};

class SVHNProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  SVHNProcessorFactory(const ::boost::shared_ptr< SVHNIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< SVHNIfFactory > handlerFactory_;
};

class SVHNMultiface : virtual public SVHNIf {
 public:
  SVHNMultiface(std::vector<boost::shared_ptr<SVHNIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~SVHNMultiface() {}
 protected:
  std::vector<boost::shared_ptr<SVHNIf> > ifaces_;
  SVHNMultiface() {}
  void add(boost::shared_ptr<SVHNIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t recognize(const SVHNQuery& query) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->recognize(query);
    }
    return ifaces_[i]->recognize(query);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class SVHNConcurrentClient : virtual public SVHNIf {
 public:
  SVHNConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  SVHNConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t recognize(const SVHNQuery& query);
  int32_t send_recognize(const SVHNQuery& query);
  int32_t recv_recognize(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif



#endif
