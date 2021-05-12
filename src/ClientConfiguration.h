#pragma once

#include <phpcpp.h>
#include <pulsar/ClientConfiguration.h>

class ClientConfiguration : public Php::Base {

  public:
    pulsar::ClientConfiguration config;

    ~ClientConfiguration() {}

    void __construct(Php::Parameters &params);

    Php::Value setUseTls(Php::Parameters &params);

    Php::Value setTlsTrustCertsFilePath(Php::Parameters &params);

    Php::Value setTlsAllowInsecureConnection(Php::Parameters &params);

    Php::Value setAuth(Php::Parameters &params);
   
};

void registerClientConfiguration(Php::Namespace &pulsarNamespace);
