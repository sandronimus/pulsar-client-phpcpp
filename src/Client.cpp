#include "Client.h"
#include "ClientConfiguration.h"
#include "Consumer.h"
#include "ConsumerConfiguration.h"
#include "Producer.h"
#include "ProducerConfiguration.h"

Php::Value Client::init(Php::Parameters &params) {
    std::string serviceUrl = params[0];

    if (params.size() == 1) {
        this->client = new ::pulsar::Client(serviceUrl);
    }

    if (params.size() == 2) {
        auto conf = (ClientConfiguration *)(params[1].implementation());
        this->client = new ::pulsar::Client(serviceUrl, conf->config);
    }

    return this;
}

Php::Value Client::createProducer(Php::Parameters &params) {
    Producer *producer = new Producer();
    std::string topic = params[0];

    if (params.size() == 1) {
        this->client->createProducer(topic, producer->producer);
        return Php::Object("Pulsar\\Producer", producer);
    }

    if (params.size() == 2) {
        auto conf = (ProducerConfiguration *)(params[1].implementation());
        this->client->createProducer(topic, conf->config, producer->producer);
        return Php::Object("Pulsar\\Producer", producer);
    }

    return Php::Object("Pulsar\\Producer", producer);
}

Php::Value Client::subscribe(Php::Parameters &params) {
    Consumer *consumer = new Consumer();

    if (params.size() == 2 && params[0].isString() && params[1].isString()) {
        std::string topic = params[0];
        std::string consumerName = params[1];
        this->client->subscribe(topic, consumerName, consumer->consumer);
        return Php::Object("Pulsar\\Consumer", consumer);
    }

    if (params.size() == 3 && params[0].isString() && params[1].isString() &&
        params[2].isObject()) {
        std::string topic = params[0];
        std::string consumerName = params[1];
        auto conf = (ConsumerConfiguration *)(params[2].implementation());
        this->client->subscribe(topic, consumerName, conf->config,
                                consumer->consumer);
        return Php::Object("Pulsar\\Consumer", consumer);
    }

    return Php::Object("Pulsar\\Consumer", consumer);
}

Php::Value Client::subscribeWithRegex(Php::Parameters &params) {
    Consumer *consumer = new Consumer();

    if (params.size() == 2 && params[0].isString() && params[1].isString()) {
        std::string regexPattern = params[0];
        std::string consumerName = params[1];
        this->client->subscribeWithRegex(regexPattern, consumerName, consumer->consumer);
        return Php::Object("Pulsar\\Consumer", consumer);
    }

    if (params.size() == 3 && params[0].isString() && params[1].isString() &&
        params[2].isObject()) {
        std::string regexPattern = params[0];
        std::string consumerName = params[1];
        auto conf = (ConsumerConfiguration *)(params[2].implementation());
        this->client->subscribeWithRegex(regexPattern, consumerName, conf->config,
                                consumer->consumer);
        return Php::Object("Pulsar\\Consumer", consumer);
    }

    return Php::Object("Pulsar\\Consumer", consumer);
}

void Client::close() {
    this->client->close();
}

void registerClient(Php::Namespace &pulsarNamespace) {
    Php::Class<Client> client("Client");
    client.method<&Client::init>("init");
    client.method<&Client::createProducer>("createProducer");
    client.method<&Client::subscribe>("subscribe");
    client.method<&Client::subscribeWithRegex>("subscribeWithRegex");
    client.method<&Client::close>("close");
    pulsarNamespace.add(client);
}
