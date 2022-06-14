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
    if (params.size() == 0) {
        return Php::Value();
    }
    return this->message.getProperty(params[0]);
}

Php::Value Message::hasProperty(Php::Parameters &params) {
    if (params.size() == 0) {
        return Php::Value(false);
    }
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

Php::Value Message::getPublishTimestamp() {
    int publishTimestamp = (int) this->message.getPublishTimestamp();
    return publishTimestamp;
}

Php::Value Message::getEventTimestamp() {
    int eventTimestamp = (int) this->message.getEventTimestamp();
    return eventTimestamp;
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
    message.method<&Message::getPublishTimestamp>("getPublishTimestamp");
    message.method<&Message::getEventTimestamp>("getEventTimestamp");
    pulsarNamespace.add(message);
}
