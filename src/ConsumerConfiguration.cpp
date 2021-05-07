#include "ConsumerConfiguration.h"
#include "Message.h"
#include <pulsar/ConsumerType.h>

#define CONSUMER_CONFIGURATION_CLASS_NAME "Pulsar\\ConsumerConfiguration"

Php::Value ConsumerConfiguration::setConsumerType(Php::Parameters &params) {
    auto consumerType = pulsar::ConsumerType((params[0].numericValue()));
    this->config.setConsumerType(consumerType);
    return Php::Object(CONSUMER_CONFIGURATION_CLASS_NAME, this);
}

Php::Value ConsumerConfiguration::setSchema(Php::Parameters &params) {
    auto schemaType = pulsar::SchemaType(params[0].numericValue()); // SchemaType is enum
    std::string schemaName = params[1];
    std::string schema = params[2];
    std::map<std::string, std::string> properties = params[3];

    auto schemaInfo = pulsar::SchemaInfo(schemaType, schemaName, schema, properties);
    this->config.setSchema(schemaInfo);
    return Php::Object(CONSUMER_CONFIGURATION_CLASS_NAME, this);
}

void registerConsumerConfiguration(Php::Namespace &pulsarNamespace) {
    Php::Class<ConsumerConfiguration> consumerConfiguration(
        "ConsumerConfiguration");
    consumerConfiguration.method<&ConsumerConfiguration::setConsumerType>(
        "setConsumerType");
    consumerConfiguration.method<&ConsumerConfiguration::setSchema>(
        "setSchema");
    pulsarNamespace.add(consumerConfiguration);
}
