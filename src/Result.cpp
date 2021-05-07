#include "Result.h"

void registerResult(Php::Namespace &pulsarNamespace)
{
    Php::Class<Result> result("Result");
    result.constant("ResultOk", pulsar::Result::ResultOk);

    result.constant("ResultUnknownError", pulsar::Result::ResultUnknownError);

    result.constant("ResultInvalidConfiguration", pulsar::Result::ResultInvalidConfiguration);

    result.constant("ResultTimeout", pulsar::Result::ResultTimeout);
    result.constant("ResultLookupError", pulsar::Result::ResultLookupError);
    result.constant("ResultConnectError", pulsar::Result::ResultConnectError);
    result.constant("ResultReadError", pulsar::Result::ResultReadError);

    result.constant("ResultAuthenticationError", pulsar::Result::ResultAuthenticationError);
    result.constant("ResultAuthorizationError", pulsar::Result::ResultAuthorizationError);
    result.constant("ResultErrorGettingAuthenticationData", pulsar::Result::ResultErrorGettingAuthenticationData);
  
    result.constant("ResultBrokerMetadataError", pulsar::Result::ResultBrokerMetadataError);
    result.constant("ResultBrokerPersistenceError", pulsar::Result::ResultBrokerPersistenceError);
    result.constant("ResultChecksumError", pulsar::Result::ResultChecksumError);

    result.constant("ResultConsumerBusy", pulsar::Result::ResultConsumerBusy);
    result.constant("ResultNotConnected", pulsar::Result::ResultNotConnected);
    result.constant("ResultAlreadyClosed", pulsar::Result::ResultAlreadyClosed);

    result.constant("ResultInvalidMessage", pulsar::Result::ResultInvalidMessage);

    result.constant("ResultConsumerNotInitialized", pulsar::Result::ResultConsumerNotInitialized);
    result.constant("ResultProducerNotInitialized", pulsar::Result::ResultProducerNotInitialized);
    result.constant("ResultProducerBusy", pulsar::Result::ResultProducerBusy);
    result.constant("ResultTooManyLookupRequestException", pulsar::Result::ResultTooManyLookupRequestException);


    result.constant("ResultInvalidTopicName", pulsar::Result::ResultInvalidTopicName);
    result.constant("ResultInvalidUrl", pulsar::Result::ResultInvalidUrl);
    result.constant("ResultServiceUnitNotReady", pulsar::Result::ResultServiceUnitNotReady);

    result.constant("ResultOperationNotSupported", pulsar::Result::ResultOperationNotSupported);
    result.constant("ResultProducerBlockedQuotaExceededError", pulsar::Result::ResultProducerBlockedQuotaExceededError);
    result.constant("ResultProducerBlockedQuotaExceededException", pulsar::Result::ResultProducerBlockedQuotaExceededException);
    result.constant("ResultProducerQueueIsFull", pulsar::Result::ResultProducerQueueIsFull);
    result.constant("ResultMessageTooBig", pulsar::Result::ResultMessageTooBig);
    result.constant("ResultTopicNotFound", pulsar::Result::ResultTopicNotFound);
    result.constant("ResultSubscriptionNotFound", pulsar::Result::ResultSubscriptionNotFound);
    result.constant("ResultConsumerNotFound", pulsar::Result::ResultConsumerNotFound);
    result.constant("ResultUnsupportedVersionError", pulsar::Result::ResultUnsupportedVersionError);
    result.constant("ResultTopicTerminated", pulsar::Result::ResultTopicTerminated);
    result.constant("ResultCryptoError", pulsar::Result::ResultCryptoError);

    result.constant("ResultIncompatibleSchema", pulsar::Result::ResultIncompatibleSchema);
    result.constant("ResultConsumerAssignError", pulsar::Result::ResultConsumerAssignError);
  

    result.constant("ResultCumulativeAcknowledgementNotAllowedError", pulsar::Result::ResultCumulativeAcknowledgementNotAllowedError);

    result.constant("ResultTransactionCoordinatorNotFoundError", pulsar::Result::ResultTransactionCoordinatorNotFoundError);
    result.constant("ResultInvalidTxnStatusError", pulsar::Result::ResultInvalidTxnStatusError);
    result.constant("ResultNotAllowedError", pulsar::Result::ResultNotAllowedError);
    result.constant("ResultTransactionConflict", pulsar::Result::ResultTransactionConflict);
    // result.constant("ResultTransactionNotFound", pulsar::Result::ResultTransactionNotFound);
    // result.constant("ResultProducerFenced", pulsar::Result::ResultProducerFenced);

    // result.constant("ResultMemoryBufferIsFull", pulsar::Result::ResultMemoryBufferIsFull);

    pulsarNamespace.add(result);
}
