#pragma once

#include <phpcpp.h>
#include <pulsar/ProducerConfiguration.h>

class ProducerConfiguration : public Php::Base {

  public:
    pulsar::ProducerConfiguration config;

    ProducerConfiguration(){};

    Php::Value setSchema(Php::Parameters &params);
};

void registerProducerConfiguration(Php::Namespace &pulsarNamespace);
