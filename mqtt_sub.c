#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mosquitto.h>

void on_connect(struct mosquitto *mosq, void *obj, int rc) {
	printf("ID: %d\n", * (int *) obj);
	if(rc) {
		printf("Error with result code: %d\n", rc);
		exit(-1);
	}
	mosquitto_subscribe(mosq, NULL, "test/t1", 0);
	mosquitto_subscribe(mosq, NULL, "test/t2", 0);
	mosquitto_subscribe(mosq, NULL, "test/t3", 0);
	mosquitto_subscribe(mosq, NULL, "test/t4", 0);
}

void on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg) {
	if(strcmp(msg->topic, "test/t1") == 0 )
		printf("Topic is test/t1\n");
	else if(strcmp(msg->topic, "test/t2") == 0 )
		printf("Topic is test/t2\n");
	else if(strcmp(msg->topic, "test/t3") == 0 )
		printf("Topic is test/t3\n");
	else if(strcmp(msg->topic, "test/t4") == 0 )
		printf("Topic is test/t4\n");
	else
		/* I should never land here ...*/
		printf("Strange...\n");
	printf("New message with topic %s: %s\n", msg->topic, (char *) msg->payload);
}

int main() {
	int rc, id=12;

	mosquitto_lib_init();

	struct mosquitto *mosq;

	mosq = mosquitto_new("subscribe-test", true, &id);
	mosquitto_connect_callback_set(mosq, on_connect);
	mosquitto_message_callback_set(mosq, on_message);
	
	rc = mosquitto_connect(mosq, "localhost", 1883, 10);
	if(rc) {
		printf("Could not connect to Broker with return code %d\n", rc);
		return -1;
	}

	mosquitto_loop_start(mosq);
	printf("Press Enter to quit...\n");
	getchar();
	mosquitto_loop_stop(mosq, true);

	mosquitto_disconnect(mosq);
	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();

	return 0;
}
