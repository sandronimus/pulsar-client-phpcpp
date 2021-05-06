#include "Message.h"
#include "MessageId.h"

Message::Message(pulsar::Message msg) { this->message = msg; }

Php::Value Message::getDataAsString() {
    return this->message.getDataAsString();
}

Php::Value Message::getProperties() {
    return this->message.getProperties();
}

Php::Value Message::getProperty(Php::Parameters &params) {
    return this->message.getProperty(params[0]);
}

Php::Value Message::hasProperty(Php::Parameters &params) {
    return this->message.hasProperty(params[0]);
}

Php::Value Message::getMessageId() {
    MessageId *messageId = new MessageId(this->message.getMessageId());
    return Php::Object("Pulsar\\MessageId", messageId);
}

Php::Value Message::getPartitionKey() {
    return this->message.getPartitionKey();
}

Php::Value Message::hasPartitionKey() {
   return this->message.hasPartitionKey(); 
}

void registerMessage(Php::Namespace &pulsarNamespace) {
    Php::Class<Message> message("Message");
    message.method<&Message::getDataAsString>("getDataAsString");
    message.method<&Message::getProperties>("getProperties");
    message.method<&Message::getProperty>("getProperty");
    message.method<&Message::hasProperty>("hasProperty");
    message.method<&Message::getMessageId>("getMessageId");
    message.method<&Message::getPartitionKey>("getPartitionKey");
    message.method<&Message::hasPartitionKey>("hasPartitionKey");
    pulsarNamespace.add(message);
}
