all: mqtt_pub mqtt_sub
	echo "Build finish!"

mqtt_pub: mqtt_pub.c
	gcc mqtt_pub.c -o mqtt_pub -lmosquitto

mqtt_sub: mqtt_sub.c
	gcc mqtt_sub.c -o mqtt_sub -lmosquitto

clean:
	rm mqtt_pub mqtt_sub
