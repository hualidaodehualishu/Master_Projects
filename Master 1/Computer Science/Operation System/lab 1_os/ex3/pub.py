

import argparse

from google.cloud import pubsub_v1


def pub(project_id: str, topic_id: str) -> None:
    """Publishes a message to a Pub/Sub topic."""
    client = pubsub_v1.PublisherClient()
    topic_path = client.topic_path(project_id, topic_id)
    string = input('please input: ')
    arr=bytes(string,'utf-8')
    data = arr
    api_future = client.publish(topic_path, data)
    message_id = api_future.result()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("project_id", help="Google Cloud project ID")
    parser.add_argument("topic_id", help="Pub/Sub topic ID")

    args = parser.parse_args()
while True:
    pub(args.project_id, args.topic_id)


