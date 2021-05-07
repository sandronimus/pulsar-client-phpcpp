#pragma once

#include <pulsar/Schema.h>
#include <phpcpp.h>

class SchemaType : public Php::Base {
  public:
    static Php::Value ALL;
    static Php::Value STRING;
    static Php::Value PROTOBUF;
    static Php::Value JSON;
    static Php::Value AVRO;
    static Php::Value INT8;
    static Php::Value INT16;
    static Php::Value INT32;
    static Php::Value DOUBLE;
    static Php::Value KEY_VALUE;
    static Php::Value FLOAT;
    static Php::Value BYTES;
    static Php::Value AUTO_CONSUME;
    static Php::Value AUTO_PUBLISH;
};

void registerSchema(Php::Namespace &pulsarNamespace);
