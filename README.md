# General

This repository contains some examples how to use libmosquitto to create MQTT clients.

# Content 

- mqtt_publish.c: A simple MQTT client, who publishes a message under the topic test/t1
- mqtt_sub.c: A simple MQTT client, who subsribes to a topic and print out a message, everytime it receives a message
- makefile: to build the examples

# Dependencies and usage

To run the script, you need the following packages. Here is the installation command for Debian based systems:

~~~~~
sudo apt install gcc mosquitto mosquitto-clients libmosquitto-dev
~~~~~

# Modified version

In this branch the subscriber will subnscribe to four topics. Test it with the following bash loop:

~~~~~
for((i=1;i<5;i++))
do
	mosquitto_pub -t test/t$i -m "$i says Hello!"
done
~~~~~

