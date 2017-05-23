/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef svhn_TYPES_H
#define svhn_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>




class SVHNQuery;

class InvalidOperation;

typedef struct _SVHNQuery__isset {
  _SVHNQuery__isset() : filename(false), image(false) {}
  bool filename :1;
  bool image :1;
} _SVHNQuery__isset;

class SVHNQuery {
 public:

  SVHNQuery(const SVHNQuery&);
  SVHNQuery& operator=(const SVHNQuery&);
  SVHNQuery() : filename(), image() {
  }

  virtual ~SVHNQuery() throw();
  std::string filename;
  std::string image;

  _SVHNQuery__isset __isset;

  void __set_filename(const std::string& val);

  void __set_image(const std::string& val);

  bool operator == (const SVHNQuery & rhs) const
  {
    if (!(filename == rhs.filename))
      return false;
    if (!(image == rhs.image))
      return false;
    return true;
  }
  bool operator != (const SVHNQuery &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SVHNQuery & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SVHNQuery &a, SVHNQuery &b);

inline std::ostream& operator<<(std::ostream& out, const SVHNQuery& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _InvalidOperation__isset {
  _InvalidOperation__isset() : why(false) {}
  bool why :1;
} _InvalidOperation__isset;

class InvalidOperation : public ::apache::thrift::TException {
 public:

  InvalidOperation(const InvalidOperation&);
  InvalidOperation& operator=(const InvalidOperation&);
  InvalidOperation() : why() {
  }

  virtual ~InvalidOperation() throw();
  std::string why;

  _InvalidOperation__isset __isset;

  void __set_why(const std::string& val);

  bool operator == (const InvalidOperation & rhs) const
  {
    if (!(why == rhs.why))
      return false;
    return true;
  }
  bool operator != (const InvalidOperation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InvalidOperation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
  mutable std::string thriftTExceptionMessageHolder_;
  const char* what() const throw();
};

void swap(InvalidOperation &a, InvalidOperation &b);

inline std::ostream& operator<<(std::ostream& out, const InvalidOperation& obj)
{
  obj.printTo(out);
  return out;
}



#endif
