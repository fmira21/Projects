#!/bin/bash

/usr/sbin/php-fpm7
telegraf & /usr/sbin/nginx -g "daemon off;"
