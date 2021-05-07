#include "Producer.h"
#include "Message.h"
#include <pulsar/Result.h>

Php::Value Producer::send(Php::Parameters &params) {
    auto message = (Message *)(params[0].implementation());
    pulsar::Result result = this->producer.send(message->message);

    // Exceptions in PHP_CPP don't support custom class names
    // making them fairly.. useless to us

    // if (result != pulsar::Result::ResultOk) {
    //     throw Php::Exception(pulsar::strResult(result));
    // }

    return result;
}

void registerProducer(Php::Namespace &pulsarNamespace) {
    Php::Class<Producer> producer("Producer");
    producer.method<&Producer::send>("send");
    pulsarNamespace.add(producer);
}
