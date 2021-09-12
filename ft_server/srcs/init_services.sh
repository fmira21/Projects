mkdir /etc/nginx/ssl
cd /etc/nginx/ssl
openssl req -x509 -newkey rsa:4096 -keyout key.key -out certificate.crt -days 365 -subj "/CN=localhost"

service nginx start
service mysql start
service php7.3-fpm start

echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "UPDATE mysql.user SET plugin='' where USER='root';"| mysql -u root --skip-password



bash
