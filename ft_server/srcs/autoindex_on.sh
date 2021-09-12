cp /var/www/html/nginx-aion.conf /etc/nginx/sites-available
cp /var/www/html/nginx-aion.conf /etc/nginx/sites-enabled

rm -rf /etc/nginx/sites-available/nginx-aioff.conf
rm -rf /etc/nginx/sites-enabled/nginx-aioff.conf


service nginx restart