#!/bin/bash

mysql_install_db --datadir=/var/lib/mysql
mysqld_safe -u root & sleep 5
mysql -u root -e "CREATE DATABASE wordpress; \
				GRANT ALL PRIVILEGES ON wordpress.* TO 'fmira'@'%' \
				IDENTIFIED BY 'fmira'; \
				FLUSH PRIVILEGES;"
mysql wordpress -u root < wordpress.sql
telegraf & sleep infinity & wait # Clumsy, but works.
