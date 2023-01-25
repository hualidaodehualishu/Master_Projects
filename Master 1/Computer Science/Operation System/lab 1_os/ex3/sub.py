import argparse

from google.cloud import pubsub_v1


def sub(project_id: str, subscription_id: str, timeout: float = None) -> None:
    """Receives messages from a Pub/Sub subscription."""
    subscriber_client = pubsub_v1.SubscriberClient()
    subscription_path = subscriber_client.subscription_path(project_id, subscription_id)

    def callback(message: pubsub_v1.subscriber.message.Message) -> None:
       data= message.data
       print("receive from publisher: ",end='')
       print(data.decode('utf8'))
       message.ack()

    streaming_pull_future = subscriber_client.subscribe(
        subscription_path, callback=callback
    )
    print(f"Listening for messages on {subscription_path}..\n")

    try:
         streaming_pull_future.result(timeout=timeout)
    except:
         streaming_pull_future.cancel()
         streaming_pull_future.result()
    subscriber_client.close()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("project_id", help="Google Cloud project ID")
    parser.add_argument("subscription_id", help="Pub/Sub subscription ID")
    parser.add_argument(
        "timeout", default=None, nargs="?", const=1, help="Pub/Sub subscription ID"
    )

    args = parser.parse_args()

    sub(args.project_id, args.subscription_id, args.timeout)


