FROM php:7.3-fpm-alpine3.10

ENV BUILD_DEPS \
    bash \
    cmake \
    autoconf \
    g++ \
    gcc \
    make \
    pcre-dev \
    libuv-dev \
    git \
    gmp-dev \
    autoconf \
    libtool \
    openssl-dev \
    zlib-dev \
    boost-dev \
    py3-setuptools \
    python3-dev \ 
    protobuf-dev \
    curl-dev \
    gtest-dev gmock \
    $PHPIZE_DEPS

# Install dependencies

RUN apk add --no-cache --virtual build-deps $BUILD_DEPS

RUN git clone https://github.com/CopernicaMarketingSoftware/PHP-CPP.git \
    && cd PHP-CPP \
    && make \
    && make install \
    && cd ..

RUN git clone --depth 1 https://github.com/apache/pulsar.git \
    && cd pulsar/pulsar-client-cpp \
    && cmake . \
    && make \
    && cd ..

# Cleanup

RUN rm -rf PHP-CPP pulsar
