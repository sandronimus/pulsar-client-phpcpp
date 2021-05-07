<?php

use Pulsar\Client;
use Pulsar\MessageBuilder;
use Pulsar\ProducerConfiguration;
use Pulsar\SchemaType;
use Pulsar\Result;

$client = new Client("pulsar://127.0.0.1:6650");

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

$config = new ProducerConfiguration();
$config->setSchema(SchemaType::AVRO, "test", $schema, []);

$producer = $client->createProducer("test-topic-with-schema", $config);

$i = 0;
while (true) {
    $prop = [
        "a" => ++$i,
    ];

    $builder = new MessageBuilder();
    $builder->setContent(json_encode([
        'foo' => 'bar',
        'iteration' => $i,
    ]))
    ->setProperties($prop);



    $message = $builder->setDeliverAfter(300)->build();
    $result = $producer->send($message);

    if ($result === Result::ResultOk) {
        echo "\n success";
    } else {
        echo "\n could not send $result";
    }

    sleep(10);
}
