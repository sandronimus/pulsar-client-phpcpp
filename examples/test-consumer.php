<?php

use Pulsar\Client;
use Pulsar\Consumer;
use Pulsar\ConsumerConfiguration;
use Pulsar\SchemaType;

$client = new Client();
$client->init("pulsar://127.0.0.1:6650");

$schema = json_encode([
    'type' => 'record', // ??
    'name' => 'test',
    'fields' => [
        [
            'name' => 'foo',
            'type' => 'string',
        ],
        [
            'name' => 'iteration',
            'type' => 'int',
        ],
    ]
]);

$config = new ConsumerConfiguration();
$config->setConsumerType(Consumer::ConsumerShared);
//$config->setSchema(SchemaType::AVRO, "test", $schema, []);

$consumer = $client->subscribe("test-topic-with-schema", "consumer-1", $config);

while (true) {
    $message = $consumer->receive();

    if ($message) {
        var_dump($message->getMessageId()->getTopicName());
        var_dump($message->hasPartitionKey());
        var_dump($message->getDataAsString());
        var_dump($message->getProperties());
        var_dump($message->getProperty('hello'));
        var_dump($message->getEventTimestamp());
        $consumer->acknowledge($message);
    }
}

$client->close();
