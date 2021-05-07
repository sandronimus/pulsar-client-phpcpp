#include "Schema.h"
#include <string>


void registerSchema(Php::Namespace &pulsarNamespace)
{
    Php::Class<SchemaType> schemaType("SchemaType");
    schemaType.constant("NONE", pulsar::SchemaType::NONE);
    schemaType.constant("STRING", pulsar::SchemaType::STRING);
    schemaType.constant("PROTOBUF", pulsar::SchemaType::PROTOBUF);
    schemaType.constant("JSON", pulsar::SchemaType::JSON);
    schemaType.constant("AVRO", pulsar::SchemaType::AVRO);
    schemaType.constant("INT8", pulsar::SchemaType::INT8);
    schemaType.constant("INT16", pulsar::SchemaType::INT16);
    schemaType.constant("INT32", pulsar::SchemaType::INT32);
    schemaType.constant("DOUBLE", pulsar::SchemaType::DOUBLE);
    schemaType.constant("KEY_VALUE", pulsar::SchemaType::KEY_VALUE);
    schemaType.constant("FLOAT", pulsar::SchemaType::FLOAT);
    schemaType.constant("BYTES", pulsar::SchemaType::BYTES);
    schemaType.constant("AUTO_CONSUME", pulsar::SchemaType::AUTO_CONSUME);
    schemaType.constant("AUTO_PUBLISH", pulsar::SchemaType::AUTO_PUBLISH);
    pulsarNamespace.add(schemaType);
}
