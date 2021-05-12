<?php

use Pulsar\Client;
use Pulsar\ClientConfiguration;
use Pulsar\Consumer;
use Pulsar\ConsumerConfiguration;
use Pulsar\SchemaType;

$clientConfig = new ClientConfiguration();
$clientConfig->setUseTls(true)
    ->setTlsTrustCertsFilePath(dirname(__FILE__) . '/tls.crt');

$client = new Client("pulsar+ssl://127.0.0.1:6651", $clientConfig);

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
$config->setSchema(SchemaType::AVRO, "test", $schema, []);

$consumer = $client->subscribe("test-topic-with-schema", "consumer-1", $config);

while (true) {
    $message = $consumer->receive();
    var_dump($message->getMessageId()->getTopicName());
    var_dump($message->hasPartitionKey());
    var_dump($message->getDataAsString());
    var_dump($message->getProperties());
    var_dump($message->getProperty('hello'));
    $consumer->acknowledge($message);
}
