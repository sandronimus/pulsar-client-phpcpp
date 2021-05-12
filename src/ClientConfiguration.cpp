#include "ClientConfiguration.h"

Php::Value ClientConfiguration::setUseTls(Php::Parameters &params) {
   this->config.setUseTls(params[0]);
   return this;
}

Php::Value ClientConfiguration::setTlsTrustCertsFilePath(Php::Parameters &params) {
   this->config.setTlsTrustCertsFilePath(params[0]);
   return this;
}

Php::Value ClientConfiguration::setTlsAllowInsecureConnection(Php::Parameters &params) {
   this->config.setTlsAllowInsecureConnection(params[0]);
   return this;
}

void registerClientConfiguration(Php::Namespace &pulsarNamespace) {
    Php::Class<ClientConfiguration> clientConfiguration("ClientConfiguration");
    clientConfiguration.method<&ClientConfiguration::setUseTls>("setUseTls");
    clientConfiguration.method<&ClientConfiguration::setTlsTrustCertsFilePath>("setTlsTrustCertsFilePath");
    clientConfiguration.method<&ClientConfiguration::setTlsAllowInsecureConnection>("setTlsAllowInsecureConnection");
    pulsarNamespace.add(clientConfiguration);
}
