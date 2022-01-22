#!/bin/bash

/usr/sbin/sshd
telegraf & /usr/sbin/nginx -g "daemon off;"
