#include "ProducerConfiguration.h"

#include <pulsar/ConsumerType.h>
#include <pulsar/Schema.h>

#define PRODUCER_CONFIGURATION_CLASS_NAME "Pulsar\\ProducerConfiguration"

Php::Value ProducerConfiguration::setSchema(Php::Parameters &params) {
    auto schemaType = pulsar::SchemaType(params[0].numericValue()); // SchemaType is enum
    std::string schemaName = params[1];
    std::string schema = params[2];
    std::map<std::string, std::string> properties = params[3];

    auto schemaInfo = pulsar::SchemaInfo(schemaType, schemaName, schema, properties);
    this->config.setSchema(schemaInfo);
    return Php::Object(PRODUCER_CONFIGURATION_CLASS_NAME, this);
}

void registerProducerConfiguration(Php::Namespace &pulsarNamespace) {
    Php::Class<ProducerConfiguration> producerConfiguration(
        "ProducerConfiguration");
    producerConfiguration.method<&ProducerConfiguration::setSchema>(
        "setSchema");
    pulsarNamespace.add(producerConfiguration);
}
