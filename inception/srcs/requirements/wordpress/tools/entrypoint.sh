#!/bin/sh

MYSQL_PASSWORD=$(cat /run/secrets/db_password)
MYSQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)


until mysqladmin ping -h mariadb -u root -p${MYSQL_ROOT_PASSWORD} --silent; do
	echo "Waiting for MariaDB..."
	sleep 2
done


if [ ! -f "/var/www/html/wp-config.php" ];then
	cat > /var/www/html/wp-config.php << EOF
<?php
define('DB_NAME', '${MYSQL_DATABASE}');
define('DB_USER', '${MYSQL_USER}');
define('DB_PASSWORD', '${MYSQL_PASSWORD}');
define('DB_HOST', 'mariadb');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');
define('AUTH_KEY', '$(openssl rand -base64 32)');
define('SECURE_AUTH_KEY', '$(openssl rand -base64 32)');
define('LOGGED_IN_KEY', '$(openssl rand -base64 32)');
define('NONCE_KEY', '$(openssl rand -base64 32)');
define('AUTH_SALT', '$(openssl rand -base64 32)');
define('SECURE_AUTH_SALT', '$(openssl rand -base64 32)');
define('LOGGED_IN_SALT', '$(openssl rand -base64 32)');
define('NONCE_SALT', '$(openssl rand -base64 32)');
\$table_prefix = 'wp_';
define('WP_DEBUG', false);
if (!defined('ABSPATH'))
	define('ABSPATH', dirname(__FILE__) . '/');
require_once(ABSPATH . 'wp-settings.php');
EOF
fi


exec php-fpm83 -F
