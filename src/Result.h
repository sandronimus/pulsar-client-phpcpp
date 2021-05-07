#pragma once

#include <pulsar/Result.h>
#include <phpcpp.h>

class Result : public Php::Base {
  public:
    static Php::Value ResultOk;

    static Php::Value ResultUnknownError;

    static Php::Value ResultInvalidConfiguration;

    static Php::Value ResultTimeout;
    static Php::Value ResultLookupError;
    static Php::Value ResultConnectError;
    static Php::Value ResultReadError;

    static Php::Value ResultAuthenticationError;
    static Php::Value ResultAuthorizationError;
    static Php::Value ResultErrorGettingAuthenticationData;
  
    static Php::Value ResultBrokerMetadataError;
    static Php::Value ResultBrokerPersistenceError;
    static Php::Value ResultChecksumError;

    static Php::Value ResultConsumerBusy;
    static Php::Value ResultNotConnected;
    static Php::Value ResultAlreadyClosed;

    static Php::Value ResultInvalidMessage;

    static Php::Value ResultConsumerNotInitialized;
    static Php::Value ResultProducerNotInitialized;
    static Php::Value ResultProducerBusy;
    static Php::Value ResultTooManyLookupRequestException;


    static Php::Value ResultInvalidTopicName;
    static Php::Value ResultInvalidUrl;
    static Php::Value ResultServiceUnitNotReady;

    static Php::Value ResultOperationNotSupported;
    static Php::Value ResultProducerBlockedQuotaExceededError;
    static Php::Value ResultProducerBlockedQuotaExceededException;
    static Php::Value ResultProducerQueueIsFull;
    static Php::Value ResultMessageTooBig;
    static Php::Value ResultTopicNotFound;
    static Php::Value ResultSubscriptionNotFound;
    static Php::Value ResultConsumerNotFound;
    static Php::Value ResultUnsupportedVersionError;
    static Php::Value ResultTopicTerminated;
    static Php::Value ResultCryptoError;

    static Php::Value ResultIncompatibleSchema;
    static Php::Value ResultConsumerAssignError;
  

    static Php::Value ResultCumulativeAcknowledgementNotAllowedError;

    static Php::Value ResultTransactionCoordinatorNotFoundError;
    static Php::Value ResultInvalidTxnStatusError;
    static Php::Value ResultNotAllowedError;
    static Php::Value ResultTransactionConflict;
    static Php::Value ResultTransactionNotFound;
    static Php::Value ResultProducerFenced;

    static Php::Value ResultMemoryBufferIsFull;
};

void registerResult(Php::Namespace &pulsarNamespace);
