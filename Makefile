mqtt_pub: mqtt_pub.c
	gcc mqtt_pub.c -o mqtt_pub -lmosquitto

clean:
	rm mqtt_pub
