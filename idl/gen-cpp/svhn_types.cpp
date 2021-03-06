/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "svhn_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>




SVHNQuery::~SVHNQuery() throw() {
}


void SVHNQuery::__set_filename(const std::string& val) {
  this->filename = val;
}

void SVHNQuery::__set_image(const std::string& val) {
  this->image = val;
}

uint32_t SVHNQuery::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->filename);
          this->__isset.filename = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->image);
          this->__isset.image = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SVHNQuery::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SVHNQuery");

  xfer += oprot->writeFieldBegin("filename", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->filename);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("image", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->image);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SVHNQuery &a, SVHNQuery &b) {
  using ::std::swap;
  swap(a.filename, b.filename);
  swap(a.image, b.image);
  swap(a.__isset, b.__isset);
}

SVHNQuery::SVHNQuery(const SVHNQuery& other0) {
  filename = other0.filename;
  image = other0.image;
  __isset = other0.__isset;
}
SVHNQuery& SVHNQuery::operator=(const SVHNQuery& other1) {
  filename = other1.filename;
  image = other1.image;
  __isset = other1.__isset;
  return *this;
}
void SVHNQuery::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SVHNQuery(";
  out << "filename=" << to_string(filename);
  out << ", " << "image=" << to_string(image);
  out << ")";
}


InvalidOperation::~InvalidOperation() throw() {
}


void InvalidOperation::__set_why(const std::string& val) {
  this->why = val;
}

uint32_t InvalidOperation::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->why);
          this->__isset.why = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t InvalidOperation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("InvalidOperation");

  xfer += oprot->writeFieldBegin("why", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->why);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(InvalidOperation &a, InvalidOperation &b) {
  using ::std::swap;
  swap(a.why, b.why);
  swap(a.__isset, b.__isset);
}

InvalidOperation::InvalidOperation(const InvalidOperation& other2) : TException() {
  why = other2.why;
  __isset = other2.__isset;
}
InvalidOperation& InvalidOperation::operator=(const InvalidOperation& other3) {
  why = other3.why;
  __isset = other3.__isset;
  return *this;
}
void InvalidOperation::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "InvalidOperation(";
  out << "why=" << to_string(why);
  out << ")";
}

const char* InvalidOperation::what() const throw() {
  try {
    std::stringstream ss;
    ss << "TException - service has thrown: " << *this;
    this->thriftTExceptionMessageHolder_ = ss.str();
    return this->thriftTExceptionMessageHolder_.c_str();
  } catch (const std::exception&) {
    return "TException - service has thrown: InvalidOperation";
  }
}


