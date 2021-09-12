cp /var/www/html/nginx-aioff.conf /etc/nginx/sites-available
cp /var/www/html/nginx-aioff.conf /etc/nginx/sites-enabled

rm -rf /etc/nginx/sites-available/nginx-aion.conf
rm -rf /etc/nginx/sites-enabled/nginx-aion.conf


service nginx restart