<?php

use Pulsar\Client;
use Pulsar\Consumer;
use Pulsar\ConsumerConfiguration;
use Pulsar\MessageBuilder;

$client = new Client("pulsar://127.0.0.1:6650");

$config = new ConsumerConfiguration();
$config->setConsumerType(Consumer::ConsumerShared);

$consumer = $client->subscribe("persistent://prop/r1/ns1/test-topic", "consumer-1", $config);

while (true) {
    $message = $consumer->receive();
    var_dump($message->getMessageId()->getTopicName());
    var_dump($message->hasPartitionKey());
    var_dump($message->getDataAsString());
    var_dump($message->getProperties());
    var_dump($message->getProperty('hello'));
    $consumer->acknowledge($message);
}
