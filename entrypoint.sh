#!/bin/sh

# Ждем, пока контейнер `test-app` запустится (увеличиваем время ожидания)
sleep 5

# Получаем ID контейнера `test-app`
APP_CONTAINER=$(docker ps -q -f name=test-app)

# Проверяем, существует ли контейнер
if [ -n "$APP_CONTAINER" ]; then
    # Если контейнер существует, пытаемся получить его логи
    docker logs "$APP_CONTAINER" > /usr/share/nginx/html/index.html
else
    # Если контейнер не найден, выводим сообщение об ошибке
    echo "Error: test-app wasn't found" > /usr/share/nginx/html/index.html
fi

# Запускаем nginx
exec nginx -g 'daemon off;'
