#include "Client.h"
#include "Consumer.h"
#include "ConsumerConfiguration.h"
#include "Message.h"
#include "MessageId.h"
#include "MessageBuilder.h"
#include "Producer.h"
#include "ProducerConfiguration.h"
#include "Result.h"
#include "Schema.h"
#include <phpcpp.h>

extern "C" {
PHPCPP_EXPORT void *get_module() {
    static Php::Extension extension("pulsar", "1.0");

    Php::Namespace pulsarNamespace("Pulsar");

    registerMessage(pulsarNamespace);
    registerMessageId(pulsarNamespace);
    registerMessageBuilder(pulsarNamespace);
    registerProducer(pulsarNamespace);
    registerProducerConfiguration(pulsarNamespace);
    registerConsumer(pulsarNamespace);
    registerClient(pulsarNamespace);
    registerConsumerConfiguration(pulsarNamespace);
    registerSchema(pulsarNamespace);
    registerResult(pulsarNamespace);

    extension.add(pulsarNamespace);

    return extension;
}
}
