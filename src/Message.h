#pragma once

#include <phpcpp.h>
#include <pulsar/Message.h>

class Message : public Php::Base {
  public:
    pulsar::Message message;

    Message() {}
    Message(pulsar::Message msg);

    Php::Value getDataAsString();

    Php::Value getProperties();
    Php::Value hasProperty(Php::Parameters &params);
    Php::Value getProperty(Php::Parameters &params);
    Php::Value getMessageId();
    Php::Value getPartitionKey();
    Php::Value hasPartitionKey();

    Php::Value getPublishTimestamp();
    Php::Value getEventTimestamp();
};

void registerMessage(Php::Namespace &pulsarNamespace);
