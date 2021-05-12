# Apache Pulsar PHP Client

## Dependencies

- [PHP-CPP](https://github.com/CopernicaMarketingSoftware/PHP-CPP)
- [Pulsar C++ Client](https://github.com/apache/pulsar/tree/master/pulsar-client-cpp/)
- PHP 7.x


## Building

```
git clone git@gitlab.com:minds/pulsar-php-client.git
make clean
make -j4
```

## Examples

`php -dextension=./output/pulsar.so examples/test-consumer.php`

See [examples](./examples) for more examples.


## Credits

- Copyright (c) 2021 Minds Inc
- Copyright (c) 2021 Oraoto